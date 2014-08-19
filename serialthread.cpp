#include "serialthread.h"
#include <QSettings>
#include <QDebug>
#include <QtCore>

using namespace std;


SerialThread::SerialThread(QObject *parent) :
    QThread(parent)
{
    port = new Win_QextSerialPort;
    out = new QTextStream(stdout);
}
SerialThread::~SerialThread()
{
    port->deleteLater();
}
void SerialThread::run()
{
    pcRequestFlag  = false;
    pcType = 0x00;
    vmcStatus = false;
    bool state = false;
    quint8 rcx = 10;
    billInforx = 0;
    coinInforx = 0;
    while(!stopped)
    {
       state = serialRead();
       if(state != vmcStatus && rcx > 8)
       {
           vmcStatus = state;
           emit dbReadySignal(vmcStatus);
       }
       if(state == false)
           rcx = (rcx >= 10) ? 10 : rcx + 1;
       else
           rcx = 0;
       if(vmcStatus == true)
       {
           billInforx++;
           coinInforx++;
       }
       msleep(50);


    }
}

bool SerialThread::init(const QString &portName)
{

    if(!openCom(portName))
    {
        print_com("SerialThread::init() Open fail!");
        portErrInfo = QString("%1").arg(tr("串口被占用,无法打开!"));
        return false;
    }
    //set
    port->setQueryMode(QextSerialBase::Polling);
    port->setBaudRate(BAUD9600);
    port->setDataBits(DATA_8);
    port->setParity(PAR_NONE);
    port->setStopBits(STOP_1);
    port->setFlowControl(FLOW_OFF);
    port->setTimeout(10);
    portErrInfo  = QString("BAUD:9600 DATA:8 STOP:1 PAR:0")
            ;
    return true;
}

bool SerialThread::openCom(const QString &portName)
{
    QString name = portName;
    port->setPortName(name);
    if(port->open(QIODevice::ReadWrite))
    {
        return true;
    }
    else
        return false;
}

quint8 SerialThread::xorCheck(unsigned char *pstr, unsigned short len)
{
    quint8 crc = 0;
    quint16 i;
    for(i=0;i<len;i++) {
        crc = crc ^ pstr[i];
    }
    return crc;

}

quint8 SerialThread::xorCheck(const QByteArray &dataArr)
{

    QByteArray arr = dataArr;
    QDataStream out(&arr,QIODevice::ReadOnly);
    quint8 crc = 0,temp;
    while(!out.atEnd())
    {
        out >> temp;
        crc = crc ^ temp;
    }
    return crc;
}




bool SerialThread::serialRead()
{
    quint16 timeout = 20;
    quint8 index = 0,len = 0,ch,crc;
    poll();//查询

    //超时接收200ms
    while(timeout)
    {
        if(port->getChar((char *)&ch))
        {
          // qDebug()<<"ch="<<ch<<index;
           if(index == 0)
           {
              if(ch != 0xE6)
              {
                 continue;
              }

           }
           else if(index == 1)
           {
              len = ch;

           }
           else if(index >= (len))//解析数据
           {
               recvbuf[index++] = ch;
               pcRecvArr  =  QByteArray((char *)recvbuf,len + 1);//转换接收包
               QString str = QDateTime::currentDateTime().toString("hh:MM:ss:zzz")
                       + QString("DB:%1").arg(QString(pcRecvArr.toHex().toUpper()))
                       + "\n";
               qDebug()<<str;

               crc = xorCheck(recvbuf,len);
               if(crc != recvbuf[len])
               {
                  return false;
               }
               if(recvbuf[3] == 0x02 && (pcType == 0x16 || pcType == 0x17))
                   return true;

               emit dbSerialRptSignal(recvbuf[3],pcRecvArr.remove(0,4));
               return true;
           }

           recvbuf[index++] = ch;
        }
        else
        {
            msleep(1);
            if(timeout)
                timeout--;
        }

    }
    return false;

}

void SerialThread::poll()
{
    QByteArray sendArr;
    QByteArray reqArr;
    QDataStream in(&sendArr,QIODevice::WriteOnly);

    quint8 temp,crc;

    if(pcRequestFlag)
    {
        reqArr = pcSendArr;
        setPcRequestFlag(false);
    }
    else if(billInforx > 5)
    {
        billInforx = 0;
        for(int i = 0;i < 10;i++)
            reqArr[i] = (quint8)0x00;
        pcType = 0x16;

    }
    else if(coinInforx > 5)
    {
        coinInforx = 0;
        for(int i = 0;i < 10;i++)
            reqArr[i] = (quint8)0x00;
        pcType = 0x17;

    }
    else
    {
        for(int i = 0;i < 10;i++)
            reqArr[i] = (quint8)0x00;
        pcType = 0x11;
    }
    QDataStream out(&reqArr,QIODevice::ReadOnly);
    quint8 len = 4;
    in <<(quint8)0xE5<<(quint8)len<<(quint8)0x00//snNo++
        <<(quint8)pcType;
    while(!out.atEnd())
    {
        out>>temp;
        in<<temp;
        len++;
    }
    in.device()->seek(1);
    in<<(quint8)len;//重定位长度
    //crc
    crc = xorCheck(sendArr);
    in.device()->seek(len);
    in<<(quint8)crc;

    port->write(sendArr);
    QString send_str = QDateTime::currentDateTime().toString("hh:MM:ss:zzz")
            + QString("PC:%1").arg(QString(sendArr.toHex().toUpper()));
    qDebug()<<send_str;


    return;

}




void SerialThread::stopSerialThread()
{

    if(!this->isRunning())
        return;
    stopped = true;
    port->close();

}
void SerialThread::startSerialThread()
{
   stopped = false;
   start();
}


