/********************************************************************************
** Form generated from reading UI file 'serial_port_test.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAL_PORT_TEST_H
#define UI_SERIAL_PORT_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Serial_port_test
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *baudrateCbx;
    QComboBox *serialPortCbx;
    QLabel *label_2;
    QComboBox *dataBitCbx;
    QComboBox *stopBitCbx;
    QLabel *label_6;
    QComboBox *checkBitCbx;
    QLabel *label;
    QPushButton *openSerialBtn;
    QLabel *label_5;
    QComboBox *streamControlCbx;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QTextEdit *logtextEdit;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLineEdit *msg_filtering;
    QLineEdit *should_accept;
    QLineEdit *received;
    QLineEdit *received_rate;
    QPushButton *clear_data;
    QPushButton *start_test;
    QPushButton *close_test;
    QPushButton *stop_filtering;
    QPushButton *start_filtering;
    QGroupBox *groupBox_4;
    QPushButton *start_message_filtering;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *Serial_port_test)
    {
        if (Serial_port_test->objectName().isEmpty())
            Serial_port_test->setObjectName(QString::fromUtf8("Serial_port_test"));
        Serial_port_test->resize(877, 603);
        groupBox = new QGroupBox(Serial_port_test);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(11, 11, 201, 301));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        baudrateCbx = new QComboBox(groupBox);
        baudrateCbx->addItem(QString());
        baudrateCbx->addItem(QString());
        baudrateCbx->addItem(QString());
        baudrateCbx->setObjectName(QString::fromUtf8("baudrateCbx"));

        gridLayout_2->addWidget(baudrateCbx, 1, 1, 1, 1);

        serialPortCbx = new QComboBox(groupBox);
        serialPortCbx->setObjectName(QString::fromUtf8("serialPortCbx"));

        gridLayout_2->addWidget(serialPortCbx, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        dataBitCbx = new QComboBox(groupBox);
        dataBitCbx->addItem(QString());
        dataBitCbx->setObjectName(QString::fromUtf8("dataBitCbx"));

        gridLayout_2->addWidget(dataBitCbx, 3, 1, 1, 1);

        stopBitCbx = new QComboBox(groupBox);
        stopBitCbx->addItem(QString());
        stopBitCbx->setObjectName(QString::fromUtf8("stopBitCbx"));

        gridLayout_2->addWidget(stopBitCbx, 4, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 5, 0, 1, 1);

        checkBitCbx = new QComboBox(groupBox);
        checkBitCbx->addItem(QString());
        checkBitCbx->setObjectName(QString::fromUtf8("checkBitCbx"));

        gridLayout_2->addWidget(checkBitCbx, 2, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        openSerialBtn = new QPushButton(groupBox);
        openSerialBtn->setObjectName(QString::fromUtf8("openSerialBtn"));

        gridLayout_2->addWidget(openSerialBtn, 6, 0, 1, 2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        streamControlCbx = new QComboBox(groupBox);
        streamControlCbx->addItem(QString());
        streamControlCbx->setObjectName(QString::fromUtf8("streamControlCbx"));

        gridLayout_2->addWidget(streamControlCbx, 5, 1, 1, 1);

        groupBox_2 = new QGroupBox(Serial_port_test);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(230, 11, 631, 511));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        logtextEdit = new QTextEdit(groupBox_2);
        logtextEdit->setObjectName(QString::fromUtf8("logtextEdit"));

        gridLayout->addWidget(logtextEdit, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(Serial_port_test);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 320, 201, 271));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        msg_filtering = new QLineEdit(groupBox_3);
        msg_filtering->setObjectName(QString::fromUtf8("msg_filtering"));

        gridLayout_3->addWidget(msg_filtering, 0, 0, 1, 3);

        should_accept = new QLineEdit(groupBox_3);
        should_accept->setObjectName(QString::fromUtf8("should_accept"));

        gridLayout_3->addWidget(should_accept, 4, 0, 1, 2);

        received = new QLineEdit(groupBox_3);
        received->setObjectName(QString::fromUtf8("received"));

        gridLayout_3->addWidget(received, 4, 2, 1, 1);

        received_rate = new QLineEdit(groupBox_3);
        received_rate->setObjectName(QString::fromUtf8("received_rate"));

        gridLayout_3->addWidget(received_rate, 5, 0, 1, 3);

        clear_data = new QPushButton(groupBox_3);
        clear_data->setObjectName(QString::fromUtf8("clear_data"));

        gridLayout_3->addWidget(clear_data, 2, 0, 1, 3);

        start_test = new QPushButton(groupBox_3);
        start_test->setObjectName(QString::fromUtf8("start_test"));

        gridLayout_3->addWidget(start_test, 3, 0, 1, 3);

        close_test = new QPushButton(groupBox_3);
        close_test->setObjectName(QString::fromUtf8("close_test"));
        close_test->setEnabled(false);

        gridLayout_3->addWidget(close_test, 6, 0, 1, 3);

        stop_filtering = new QPushButton(groupBox_3);
        stop_filtering->setObjectName(QString::fromUtf8("stop_filtering"));

        gridLayout_3->addWidget(stop_filtering, 1, 2, 1, 1);

        start_filtering = new QPushButton(groupBox_3);
        start_filtering->setObjectName(QString::fromUtf8("start_filtering"));

        gridLayout_3->addWidget(start_filtering, 1, 0, 1, 2);

        groupBox_4 = new QGroupBox(Serial_port_test);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(230, 530, 631, 61));
        start_message_filtering = new QPushButton(groupBox_4);
        start_message_filtering->setObjectName(QString::fromUtf8("start_message_filtering"));
        start_message_filtering->setGeometry(QRect(10, 20, 71, 29));
        lineEdit_2 = new QLineEdit(groupBox_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 20, 521, 25));

        retranslateUi(Serial_port_test);

        QMetaObject::connectSlotsByName(Serial_port_test);
    } // setupUi

    void retranslateUi(QWidget *Serial_port_test)
    {
        Serial_port_test->setWindowTitle(QCoreApplication::translate("Serial_port_test", "Serial_port_tool", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Serial_port_test", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("Serial_port_test", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Serial_port_test", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        baudrateCbx->setItemText(0, QCoreApplication::translate("Serial_port_test", "1000000", nullptr));
        baudrateCbx->setItemText(1, QCoreApplication::translate("Serial_port_test", "115200", nullptr));
        baudrateCbx->setItemText(2, QCoreApplication::translate("Serial_port_test", "9600", nullptr));

        label_2->setText(QCoreApplication::translate("Serial_port_test", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        dataBitCbx->setItemText(0, QCoreApplication::translate("Serial_port_test", "8", nullptr));

        stopBitCbx->setItemText(0, QCoreApplication::translate("Serial_port_test", "1", nullptr));

        label_6->setText(QCoreApplication::translate("Serial_port_test", "\346\265\201\346\216\247\345\210\266\357\274\232", nullptr));
        checkBitCbx->setItemText(0, QCoreApplication::translate("Serial_port_test", "NONE", nullptr));

        label->setText(QCoreApplication::translate("Serial_port_test", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        openSerialBtn->setText(QCoreApplication::translate("Serial_port_test", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_5->setText(QCoreApplication::translate("Serial_port_test", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        streamControlCbx->setItemText(0, QCoreApplication::translate("Serial_port_test", "NONE", nullptr));

        groupBox_2->setTitle(QCoreApplication::translate("Serial_port_test", "\346\216\245\351\200\201\346\225\260\346\215\256", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Serial_port_test", "\346\265\213\350\257\225", nullptr));
        msg_filtering->setPlaceholderText(QCoreApplication::translate("Serial_port_test", "\350\276\223\345\205\245\351\234\200\350\246\201\350\277\207\346\273\244\347\232\204\346\225\260\346\215\256", nullptr));
        should_accept->setText(QCoreApplication::translate("Serial_port_test", "\345\272\224\346\216\245\345\217\227\357\274\232", nullptr));
        received->setText(QCoreApplication::translate("Serial_port_test", "\345\256\236\346\216\245\345\217\227\357\274\232", nullptr));
        received_rate->setText(QCoreApplication::translate("Serial_port_test", "\346\216\245\345\217\227\347\216\207\357\274\232", nullptr));
        clear_data->setText(QCoreApplication::translate("Serial_port_test", "\346\270\205\351\231\244\346\225\260\346\215\256", nullptr));
        start_test->setText(QCoreApplication::translate("Serial_port_test", "\345\274\200\345\247\213\346\265\213\350\257\225", nullptr));
        close_test->setText(QCoreApplication::translate("Serial_port_test", "\345\201\234\346\255\242\346\265\213\350\257\225", nullptr));
        stop_filtering->setText(QCoreApplication::translate("Serial_port_test", "\345\205\263\351\227\255\350\277\207\346\273\244", nullptr));
        start_filtering->setText(QCoreApplication::translate("Serial_port_test", "\345\274\200\345\220\257\350\277\207\346\273\244", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Serial_port_test", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        start_message_filtering->setText(QCoreApplication::translate("Serial_port_test", "\345\217\221\351\200\201", nullptr));
#if QT_CONFIG(accessibility)
        lineEdit_2->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("Serial_port_test", "\350\276\223\345\205\245\351\234\200\350\246\201\345\217\221\351\200\201\347\232\204\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Serial_port_test: public Ui_Serial_port_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_PORT_TEST_H
