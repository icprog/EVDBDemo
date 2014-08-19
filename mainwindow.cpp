#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList portList;
    portList<<"COM1"<<"COM2"<<"COM3"<<"COM4"<<"COM5"<<"COM6"
             <<"COM7"<<"COM8"<<"COM9"<<"COM10"<<"COM11"<<"COM12";
    ui->comboBox->addItems(portList);


    QFont font = this->font();
    font.setPointSize(12);
    this->setFont(font);
    font.setBold(true);

    setWindowTitle("db_demo");
    ui->label_billState->setFont(font);
    ui->label_coinState->setFont(font);

    port = new SerialThread();


    connect(port,SIGNAL(dbReadySignal(bool)),
            this,SLOT(dbReadySlot(bool)));
    connect(port,SIGNAL(dbSerialRptSignal(unsigned char,QByteArray)),
            this,SLOT(dbSerialRptSlot(unsigned char,QByteArray)),Qt::QueuedConnection);

    timer_dialog = new QTimer(this);
    connect(timer_dialog,SIGNAL(timeout()),this,SLOT(timer_dialog_timeout()));

    dialog = new YocDialog(this);
    on_pushButton_clear_clicked();
    uiInit();
}

MainWindow::~MainWindow()
{
    delete ui;
    port->deleteLater();
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    qDebug()<<"on_pushButton_clicked"<<checked;
    if(checked)
    {

        if(port->init(ui->comboBox->currentText()))
        {
           ui->pushButton->setText(tr("关闭串口"));
           ui->label_portInfo->setText(port->getPortErrInfo());
           port->startSerialThread();

        }
        else
        {
            ui->pushButton->setChecked(false);
            QMessageBox::warning(this,tr("打开串口"),
                       port->getPortErrInfo(),QMessageBox::Yes);


        }

    }
    else
    {
        ui->pushButton->setText(tr("打开串口"));
        ui->label_portInfo->clear();
        port->stopSerialThread();
    }
}


void MainWindow::dbReadySlot(bool flag)
{
    qDebug()<<"dbReadySlot"<<flag;
    if(flag == false)
        uiInit();
}



void MainWindow::dbSerialRptSlot(unsigned char type, const QByteArray &arr)
{
    quint8 index = 0;
    quint32 temp;

    if(type == 0x81)
    {
        temp = arr.at(index++);
        if(temp == 1)//忙
        {           
            return;
        }
        else
        {

        }
        //纸币器

        QString tempStr;
        bool ok;
        temp = arr.at(index++);//类型
        temp = arr.at(index++);
        QStringList tempList;
        tempList<<tr("未知")<<tr("正常")<<tr("故障")<<tr("缺币")<<tr("禁能")
                     <<tr("通信故障");

        tempStr = (temp > 5) ? tempList.at(0):tempList.at(temp);
        ui->label_billState->setText(tempStr);

        temp = arr.mid(index,4).toHex().toUInt(&ok,16);
        index += 4;
        billAmount +=temp;

        temp = arr.mid(index,4).toHex().toUInt(&ok,16);
        index += 4;
        billChange = temp;
         //硬币器
        temp = arr.at(index++);//类型
        temp = arr.at(index++);
        tempStr = (temp > 5) ? tempList.at(0):tempList.at(temp);
        ui->label_coinState->setText(tempStr);
        temp = arr.mid(index,4).toHex().toUInt(&ok,16);
        index += 4;
        coinAmount += temp;


        temp = arr.mid(index,4).toHex().toUInt(&ok,16);
        index += 4;
        coinChange = temp;
        payoutNum += arr.at(index++);


        tempStr = QString("%1.%2")
                .arg(billAmount/100).arg(billAmount/10 % 10,1,10,QLatin1Char('0'));
        ui->lcdNumber_bill->display(tempStr);


        tempStr = QString("%1.%2").arg(billChange/100)
                                    .arg(billChange/10 % 10,1,10,QLatin1Char('0'));
        ui->lcdNumber_billChange->display(tempStr);

        tempStr = QString("%1.%2").arg(coinAmount/100)
                                    .arg(coinAmount/10 % 10,1,10,QLatin1Char('0'));
        ui->lcdNumber_coin->display(tempStr);
        tempStr = QString("%1.%2").arg(coinChange/100)
                                    .arg(coinChange/10 % 10,1,10,QLatin1Char('0'));
        ui->lcdNumber_coinChange->display(tempStr);
        tempStr = QString("%1").arg(payoutNum);
        ui->lcdNumbe->display(tempStr);


    }
    else if(type == 0x01)
    {

    }
    else if(type == 0x02)
    {
        qDebug()<<tr("驱动板忙！");
        showTips(true,tr("驱动板忙！"));
    }
    else if(type == 0x82)//billInfo
    {
       QString str,strch;
       temp = arr.at(index++);
       quint8 temp1 = arr.at(index++);
       quint8 temp2 = arr.at(index++);
       if(temp == 2)
       {
          if(temp1 & 0x01)
          {
              str += tr("马达故障\n");
          }
          else if(temp1 & 0x02)
          {
              str += tr("纸币钞箱故障\n");
          }
          else
          {
             str += tr("其他故障\n");
          }


          if(temp2 & 0x02)
          {
             str += tr("传感器故障\n");
          }
          else if(temp2 & 0x04)
          {
             str += tr("出币口卡币\n");
          }
          else if(temp2 & 0x08)
          {
             str += tr("rom出错\n");
          }
          else if(temp & 0x10)
          {
              str += tr("进币通道出错\n");
          }
          else if(temp2 & 0x20)
          {
              str += tr("投币卡币\n");
          }
          else if(temp2 & 0x40)
          {
              str += tr("移除纸币钞箱\n");
          }
          else if(temp2 & 0x80)
          {
              str += tr("硬件禁能\n");
          }

       }
       //通道面值
       for(int i = 0;i < 8;i++)
       {
         temp = arr.at(index++);
         if(temp > 0)
         {
             strch += QString ("%1%2%3%4%5\n")
                     .arg(tr("通道"))
                     .arg(i + 1).arg(tr("面值:"))
                     .arg(pcAnalysisAmount(temp)).arg(tr("分"));
         }
       }

       ui->label_billchannel->setText(strch + str);
    }
    else if(type == 0x83)//coinInfo
    {
        QString str,strch,strNum;

        temp = arr.at(index++);
        quint8 temp1 = arr.at(index++);
        quint8 temp2 = arr.at(index++);
        if(temp == 2)
        {
           if(temp1 & 0x80)
           {
              str += tr("其他故障\n");
           }

           if(temp2 & 0x02)
           {
              str += tr("传感器故障\n");
           }
           else if(temp2 & 0x04)
           {
              str += tr("出币口卡币\n");
           }
           else if(temp2 & 0x08)
           {
              str += tr("rom出错\n");
           }
           else if(temp2 & 0x10)
           {
               str += tr("进币通道出错\n");
           }
           else if(temp2 & 0x20)
           {
               str += tr("投币卡币\n");
           }
           else if(temp2 & 0x40)
           {
               str += tr("硬币斗移开\n");
           }

        }
        //通道面值
        for(int i = 0;i < 8;i++)
        {
          temp = arr.at(index++);
          if(temp > 0)
          {
              strch += QString ("%1%2%3%4%5\n")
                      .arg(tr("通道"))
                      .arg(i + 1).arg(tr("面值:"))
                      .arg(pcAnalysisAmount(temp)).arg(tr("分"));
          }
        }
        //通道储币
        for(int i = 0;i < 8;i++)
        {
          temp1 = arr.at(index++);
          temp2 = arr.at(index++);
          temp = temp1 * 256 + temp2;
          if(temp > 0)
          {
              strch += QString ("%1%2%3%4%5\n")
                      .arg(tr("通道"))
                      .arg(i + 1).arg(tr("储币:"))
                      .arg(temp)
                      .arg(tr("个"));
          }
        }

        ui->label_coinchannel->setText(strch + strNum + str);

    }

}
void MainWindow::on_pushButton_clear_clicked()
{
    billAmount = 0;
    billChange = 0;
    coinAmount = 0;
    coinChange = 0;
    payoutNum = 0;
    ui->lcdNumber_bill->display("0");
    ui->lcdNumber_coin->display("0");
    ui->lcdNumbe->display("0");
    ui->lcdNumber_billChange->display("0");
    ui->lcdNumber_coinChange->display("0");


}

void MainWindow::uiInit()
{

    ui->lcdNumber_bill->display("8888.8");
    ui->lcdNumber_coin->display("8888.8");
    ui->lcdNumbe->display("8888");
    ui->lcdNumber_billChange->display("8888.8");
    ui->lcdNumber_coinChange->display("8888.8");

    ui->label_billState->setText(tr("未知"));
    ui->label_coinState->setText(tr("未知"));

    ui->label_billchannel->clear();
    ui->label_coinchannel->clear();


}

void MainWindow::showTips(const bool flag, const QString &text)
{
    dialog->setText(text);
    dialog->show();
    if(flag == true)
    {
        timer_dialog->start(1000);
    }

}

void MainWindow::timer_dialog_timeout()
{
    dialog->hide();
}




void MainWindow::pcRequestSendSlot(quint8 type, QByteArray arr)
{

    if(port->getVMCState() == false)
       showTips(true,tr("驱动板未连接上..."));
    port->updatePcCmdType(type);
    port->updatePcSendArr(arr);
    port->setPcRequestFlag(true);
}

void MainWindow::on_pushButton_init_clicked()
{
   QByteArray arr;
   QDataStream in(&arr,QIODevice::WriteOnly);

   in<<(quint8)0x03<<(quint8)0x02<<quint8(0x02);
   for(int i = 0;i < 7;i++)
       in<<(quint8)0x00;

   on_pushButton_clear_clicked();
   pcRequestSendSlot(0x12,arr);

}


unsigned int MainWindow::pcAnalysisAmount(unsigned char data)
{

    unsigned int amount;
    unsigned char uint;
    if(data == 0)
        return 0;
    uint =  data >> 4;
    amount = data & 0x0f;
    while(uint)
    {
        amount = amount * 10;
        uint--;
    }
    return amount;
}

void MainWindow::timer_req_timeout()
{}

void MainWindow::on_pushButton_payout_clicked()
{
    QByteArray arr;
    QDataStream in(&arr,QIODevice::WriteOnly);

    bool ok;
    quint32 temp = ui->lineEdit->text().toUInt(&ok,10);
    if(!ok || temp == 0)
    {
        return;
    }

    in<<(quint8)0x02<<(quint32)0x00<<(quint32)temp<<(quint8)0x00;
    pcRequestSendSlot(0x14,arr);
}


void MainWindow::on_pushButton_billAction_clicked(bool checked)
{
    QByteArray arr;
    QDataStream in(&arr,QIODevice::WriteOnly);

    in<<(quint8)0x01;
    if(checked)
    {
        in<<(quint8)0x02<<(quint32)0x00<<(quint32)0x00;
        ui->pushButton_billAction->setText(tr("使能"));
    }
    else
    {
       in<<(quint8)0x01<<(quint32)0x00<<(quint32)0x00;
       ui->pushButton_billAction->setText(tr("禁能"));
    }
    pcRequestSendSlot(0x13,arr);
}

void MainWindow::on_pushButton_coinAction_clicked(bool checked)
{
    QByteArray arr;
    QDataStream in(&arr,QIODevice::WriteOnly);

    in<<(quint8)0x02;
    if(checked)
    {
        in<<(quint8)0x02<<(quint32)0x00<<(quint32)0x00;
        ui->pushButton_coinAction->setText(tr("使能"));
    }
    else
    {
       in<<(quint8)0x01<<(quint32)0x00<<(quint32)0x00;
       ui->pushButton_coinAction->setText(tr("禁能"));
    }
    pcRequestSendSlot(0x13,arr);
}
