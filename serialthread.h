#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QThread>
#include <QMutex>
#include "./serial/win_qextserialport.h"
#include "./serial/qextserialenumerator.h"
#include "config.h"
#include <QFile>


#define HEAD_EF     0xE6
#define HEAD_LEN    5
#define VER_F0_1    0x41
#define VER_F0_0    0x40
//VMC-->PC
#define ACK_RPT    0x01
#define NAK_RPT    0x02
#define POLL       0x03
#define VMC_SETUP  0x05
#define PAYIN_RPT 0x06
#define HUODAO_RPT 0x0E
#define VENDOUT_RPT 0x08
#define INFO_RPT 0x11
#define ACTION_RPT 0x0B
#define BUTTON_RPT  0x0C
#define STATUS_RPT  0x0D
//PC-->VMC
#define ACK      0x80
#define NAK      0x81
#define GET_SETUP   0x90
#define GET_HUODAO   0x8A
#define HUODAO_IND  0x87
#define SALEPRICE_IND 0x8E
#define HUODAO_SET_IND 0x8F
#define PRICE_SET_IND  0x8E
#define VENDOUT_IND   0x83
#define CONTROL_IND   0x85
#define GET_INFO 0x8C
#define GET_INFO_EXP 0x92
#define SET_HUODAO  0x93
#define GET_STATUS  0x86


//VMC当前状态

#define VMC_INITTING    1  //正在初始化
#define VMC_NORMAL    2   //正常
#define VMC_FAULT    3  //故障
#define VMC_MANTAIN   4 //维护



class SerialThread : public QThread
{
    Q_OBJECT
public:
    explicit SerialThread(QObject *parent = 0);
    ~SerialThread();
    void stopSerialThread();
    void startSerialThread();
    bool init(const QString &portName = "COM1");
    bool openCom(const QString &portName);
    inline void updatePcCmdType(quint8 type){pcType = type;}
    inline void updatePcSendArr(QByteArray sendArr){pcSendArr = sendArr;}
    inline void setPcRequestFlag(bool flag)
    {
        pcRequestMutex.lock();
        pcRequestFlag = flag;
        pcRequestMutex.unlock();

    }


    void setVMCState(const bool flag)
    {
        vmcStateMutex.lock();
        this->vmcStatus = flag;
        vmcStateMutex.unlock();
    }
    inline bool getVMCState(){return this->vmcStatus;}
    inline QString getPortErrInfo()
    {
        return portErrInfo;
    }

    QString getPortName(){return port->portName();}
signals:
    void dbReadySignal(bool flag);
    void dbSerialRptSignal(unsigned char type,const QByteArray &arr);
protected:
    void run();
public slots:


private:
    Win_QextSerialPort *port;
    bool vmcStatus;
    QMutex vmcStateMutex;
    bool stopped;
    bool  pcRequestFlag;
    quint8 pcType;
    quint8 snNo;

    quint8 billInforx,coinInforx;
    QMutex pcRequestMutex;
    unsigned char recvbuf[256];
    unsigned char sendbuf[256];
    QByteArray pcSendArr,pcRecvArr;

    quint8  xorCheck(unsigned char *pstr,unsigned short len);
    quint8  xorCheck(const QByteArray &dataArr);

    bool serialRead();



    void poll();
    QString portErrInfo;
    QTextStream *out;



};

#endif // SERIALTHREAD_H
