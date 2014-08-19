#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialthread.h"
#include "yocdialog.h"

class QTimer;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void uiInit();

    void showTips(const bool flag,const QString &text);
    unsigned int pcAnalysisAmount(unsigned char data);
private slots:
    void on_pushButton_clicked(bool checked);
    void dbSerialRptSlot(unsigned char type,const QByteArray &arr);
    void pcRequestSendSlot(quint8 type,QByteArray arr);
private:
    Ui::MainWindow *ui;
    SerialThread *port;

    quint32 billAmount,coinAmount,payoutNum,billChange,coinChange;
    QTimer *timer_dialog,*timer_req;
    YocDialog *dialog;
private slots:
    void dbReadySlot(bool flag);
    void on_pushButton_clear_clicked();
    void timer_dialog_timeout();
    void timer_req_timeout();


    void on_pushButton_init_clicked();
    void on_pushButton_payout_clicked();

    void on_pushButton_billAction_clicked(bool checked);
    void on_pushButton_coinAction_clicked(bool checked);
};

#endif // MAINWINDOW_H
