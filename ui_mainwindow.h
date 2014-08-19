/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label_portInfo;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_init;
    QPushButton *pushButton_clear;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_bill_2;
    QLabel *label_billState;
    QPushButton *pushButton_billAction;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_bill;
    QLCDNumber *lcdNumber_bill;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_billChange;
    QLCDNumber *lcdNumber_billChange;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_bill_3;
    QLabel *label_coinState;
    QPushButton *pushButton_coinAction;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_coin;
    QLCDNumber *lcdNumber_coin;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_coinChange;
    QLCDNumber *lcdNumber_coinChange;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_billchannel;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_coinchannel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_payout;
    QLineEdit *lineEdit;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_payButton;
    QLCDNumber *lcdNumbe;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(592, 467);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setCheckable(true);

        horizontalLayout_8->addWidget(pushButton);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(comboBox);

        label_portInfo = new QLabel(centralWidget);
        label_portInfo->setObjectName(QString::fromUtf8("label_portInfo"));

        horizontalLayout_8->addWidget(label_portInfo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        pushButton_init = new QPushButton(centralWidget);
        pushButton_init->setObjectName(QString::fromUtf8("pushButton_init"));

        horizontalLayout_8->addWidget(pushButton_init);

        pushButton_clear = new QPushButton(centralWidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));

        horizontalLayout_8->addWidget(pushButton_clear);


        verticalLayout_5->addLayout(horizontalLayout_8);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_bill_2 = new QLabel(groupBox);
        label_bill_2->setObjectName(QString::fromUtf8("label_bill_2"));

        horizontalLayout_9->addWidget(label_bill_2);

        label_billState = new QLabel(groupBox);
        label_billState->setObjectName(QString::fromUtf8("label_billState"));

        horizontalLayout_9->addWidget(label_billState);

        pushButton_billAction = new QPushButton(groupBox);
        pushButton_billAction->setObjectName(QString::fromUtf8("pushButton_billAction"));
        pushButton_billAction->setCheckable(true);

        horizontalLayout_9->addWidget(pushButton_billAction);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_bill = new QLabel(groupBox);
        label_bill->setObjectName(QString::fromUtf8("label_bill"));

        horizontalLayout_2->addWidget(label_bill);

        lcdNumber_bill = new QLCDNumber(groupBox);
        lcdNumber_bill->setObjectName(QString::fromUtf8("lcdNumber_bill"));
        lcdNumber_bill->setMinimumSize(QSize(120, 40));
        lcdNumber_bill->setSmallDecimalPoint(true);
        lcdNumber_bill->setDigitCount(6);
        lcdNumber_bill->setSegmentStyle(QLCDNumber::Filled);
        lcdNumber_bill->setProperty("value", QVariant(8888.8));

        horizontalLayout_2->addWidget(lcdNumber_bill);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_billChange = new QLabel(groupBox);
        label_billChange->setObjectName(QString::fromUtf8("label_billChange"));

        horizontalLayout_5->addWidget(label_billChange);

        lcdNumber_billChange = new QLCDNumber(groupBox);
        lcdNumber_billChange->setObjectName(QString::fromUtf8("lcdNumber_billChange"));
        lcdNumber_billChange->setMinimumSize(QSize(120, 40));
        lcdNumber_billChange->setSmallDecimalPoint(true);
        lcdNumber_billChange->setDigitCount(6);

        horizontalLayout_5->addWidget(lcdNumber_billChange);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_bill_3 = new QLabel(groupBox_2);
        label_bill_3->setObjectName(QString::fromUtf8("label_bill_3"));

        horizontalLayout_10->addWidget(label_bill_3);

        label_coinState = new QLabel(groupBox_2);
        label_coinState->setObjectName(QString::fromUtf8("label_coinState"));

        horizontalLayout_10->addWidget(label_coinState);

        pushButton_coinAction = new QPushButton(groupBox_2);
        pushButton_coinAction->setObjectName(QString::fromUtf8("pushButton_coinAction"));
        pushButton_coinAction->setCheckable(true);

        horizontalLayout_10->addWidget(pushButton_coinAction);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_coin = new QLabel(groupBox_2);
        label_coin->setObjectName(QString::fromUtf8("label_coin"));

        horizontalLayout_3->addWidget(label_coin);

        lcdNumber_coin = new QLCDNumber(groupBox_2);
        lcdNumber_coin->setObjectName(QString::fromUtf8("lcdNumber_coin"));
        lcdNumber_coin->setMinimumSize(QSize(120, 40));
        lcdNumber_coin->setAutoFillBackground(false);
        lcdNumber_coin->setFrameShape(QFrame::Box);
        lcdNumber_coin->setFrameShadow(QFrame::Raised);
        lcdNumber_coin->setLineWidth(1);
        lcdNumber_coin->setMidLineWidth(0);
        lcdNumber_coin->setSmallDecimalPoint(true);
        lcdNumber_coin->setDigitCount(6);
        lcdNumber_coin->setSegmentStyle(QLCDNumber::Filled);
        lcdNumber_coin->setProperty("value", QVariant(8888.8));

        horizontalLayout_3->addWidget(lcdNumber_coin);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_coinChange = new QLabel(groupBox_2);
        label_coinChange->setObjectName(QString::fromUtf8("label_coinChange"));

        horizontalLayout_6->addWidget(label_coinChange);

        lcdNumber_coinChange = new QLCDNumber(groupBox_2);
        lcdNumber_coinChange->setObjectName(QString::fromUtf8("lcdNumber_coinChange"));
        lcdNumber_coinChange->setMinimumSize(QSize(120, 40));
        lcdNumber_coinChange->setSmallDecimalPoint(true);
        lcdNumber_coinChange->setDigitCount(6);

        horizontalLayout_6->addWidget(lcdNumber_coinChange);


        verticalLayout_2->addLayout(horizontalLayout_6);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_billchannel = new QLabel(groupBox_3);
        label_billchannel->setObjectName(QString::fromUtf8("label_billchannel"));
        label_billchannel->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(label_billchannel);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_coinchannel = new QLabel(groupBox_4);
        label_coinchannel->setObjectName(QString::fromUtf8("label_coinchannel"));
        label_coinchannel->setMinimumSize(QSize(0, 50));

        verticalLayout_4->addWidget(label_coinchannel);


        gridLayout->addWidget(groupBox_4, 1, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 26, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_payout = new QPushButton(centralWidget);
        pushButton_payout->setObjectName(QString::fromUtf8("pushButton_payout"));

        horizontalLayout->addWidget(pushButton_payout);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(lineEdit);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);


        horizontalLayout_7->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_payButton = new QLabel(centralWidget);
        label_payButton->setObjectName(QString::fromUtf8("label_payButton"));

        horizontalLayout_4->addWidget(label_payButton);

        lcdNumbe = new QLCDNumber(centralWidget);
        lcdNumbe->setObjectName(QString::fromUtf8("lcdNumbe"));
        lcdNumbe->setMinimumSize(QSize(0, 30));
        lcdNumbe->setDigitCount(4);

        horizontalLayout_4->addWidget(lcdNumbe);


        horizontalLayout_7->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_7);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0, QApplication::UnicodeUTF8));
        label_portInfo->setText(QString());
        pushButton_init->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", 0, QApplication::UnicodeUTF8));
        pushButton_clear->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\270\205\351\233\266", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\272\270\345\270\201\345\231\250", 0, QApplication::UnicodeUTF8));
        label_bill_2->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_billState->setText(QApplication::translate("MainWindow", "\346\234\252\347\237\245", 0, QApplication::UnicodeUTF8));
        pushButton_billAction->setText(QApplication::translate("MainWindow", "\347\246\201\350\203\275", 0, QApplication::UnicodeUTF8));
        label_bill->setText(QApplication::translate("MainWindow", "\347\272\270\345\270\201\346\216\245\346\224\266\357\274\232", 0, QApplication::UnicodeUTF8));
        label_billChange->setText(QApplication::translate("MainWindow", "\347\272\270\345\270\201\346\211\276\351\233\266\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\347\241\254\345\270\201\345\231\250", 0, QApplication::UnicodeUTF8));
        label_bill_3->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_coinState->setText(QApplication::translate("MainWindow", "\346\234\252\347\237\245", 0, QApplication::UnicodeUTF8));
        pushButton_coinAction->setText(QApplication::translate("MainWindow", "\347\246\201\350\203\275", 0, QApplication::UnicodeUTF8));
        label_coin->setText(QApplication::translate("MainWindow", "\347\241\254\345\270\201\346\216\245\346\224\266\357\274\232", 0, QApplication::UnicodeUTF8));
        label_coinChange->setText(QApplication::translate("MainWindow", "\347\241\254\345\270\201\346\211\276\351\233\266\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\347\272\270\345\270\201\345\231\250\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_billchannel->setText(QApplication::translate("MainWindow", "channel", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\347\241\254\345\270\201\345\231\250\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_coinchannel->setText(QApplication::translate("MainWindow", "channel", 0, QApplication::UnicodeUTF8));
        pushButton_payout->setText(QApplication::translate("MainWindow", "\345\207\272\345\270\201", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("MainWindow", "100", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\345\210\206", 0, QApplication::UnicodeUTF8));
        label_payButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\270\201\346\214\211\351\222\256\350\247\246\345\217\221\346\254\241\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
