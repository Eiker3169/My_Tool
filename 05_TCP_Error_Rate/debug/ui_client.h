/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QLabel *label_4;
    QTextEdit *sended_text;
    QLineEdit *error_byte;
    QLabel *label_10;
    QLineEdit *received_byte;
    QLineEdit *start_time;
    QLineEdit *sended_byte;
    QGroupBox *groupBox_5;
    QLabel *total_send_byte_;
    QLabel *label_7;
    QGroupBox *groupBox_2;
    QLabel *label_11;
    QLineEdit *port;
    QLabel *label_12;
    QLineEdit *server_ip;
    QPushButton *connect;
    QPushButton *send;
    QTextEdit *recevied_text;
    QPushButton *start;
    QLineEdit *total_send_byte;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *error_byte_;
    QLabel *label_9;
    QLineEdit *cumulative_time;
    QLineEdit *end_time;
    QLineEdit *error_rate_;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox;
    QPushButton *reset;
    QGroupBox *groupBox_6;
    QPushButton *reset_2;
    QGroupBox *groupBox_7;
    QPushButton *start_2;
    QPushButton *checkout;
    QGroupBox *groupBox_8;

    void setupUi(QWidget *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName(QString::fromUtf8("client"));
        client->resize(867, 707);
        label_4 = new QLabel(client);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 960, 69, 20));
        QFont font;
        font.setPointSize(11);
        label_4->setFont(font);
        sended_text = new QTextEdit(client);
        sended_text->setObjectName(QString::fromUtf8("sended_text"));
        sended_text->setGeometry(QRect(270, 40, 551, 271));
        error_byte = new QLineEdit(client);
        error_byte->setObjectName(QString::fromUtf8("error_byte"));
        error_byte->setGeometry(QRect(110, 250, 113, 21));
        error_byte->setReadOnly(true);
        label_10 = new QLabel(client);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(18, 210, 91, 20));
        label_10->setFont(font);
        received_byte = new QLineEdit(client);
        received_byte->setObjectName(QString::fromUtf8("received_byte"));
        received_byte->setGeometry(QRect(110, 370, 113, 21));
        received_byte->setReadOnly(true);
        start_time = new QLineEdit(client);
        start_time->setObjectName(QString::fromUtf8("start_time"));
        start_time->setGeometry(QRect(100, 880, 113, 21));
        start_time->setReadOnly(true);
        sended_byte = new QLineEdit(client);
        sended_byte->setObjectName(QString::fromUtf8("sended_byte"));
        sended_byte->setGeometry(QRect(110, 330, 113, 21));
        sended_byte->setReadOnly(true);
        groupBox_5 = new QGroupBox(client);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(250, 350, 591, 301));
        total_send_byte_ = new QLabel(client);
        total_send_byte_->setObjectName(QString::fromUtf8("total_send_byte_"));
        total_send_byte_->setGeometry(QRect(18, 290, 91, 20));
        total_send_byte_->setFont(font);
        label_7 = new QLabel(client);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(18, 330, 91, 20));
        label_7->setFont(font);
        groupBox_2 = new QGroupBox(client);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 231, 151));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 70, 69, 20));
        label_11->setFont(font);
        port = new QLineEdit(groupBox_2);
        port->setObjectName(QString::fromUtf8("port"));
        port->setGeometry(QRect(90, 70, 113, 21));
        port->setReadOnly(false);
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 30, 69, 20));
        label_12->setFont(font);
        server_ip = new QLineEdit(groupBox_2);
        server_ip->setObjectName(QString::fromUtf8("server_ip"));
        server_ip->setGeometry(QRect(90, 30, 113, 21));
        server_ip->setReadOnly(false);
        connect = new QPushButton(groupBox_2);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(20, 110, 81, 25));
        send = new QPushButton(groupBox_2);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(130, 110, 81, 25));
        recevied_text = new QTextEdit(client);
        recevied_text->setObjectName(QString::fromUtf8("recevied_text"));
        recevied_text->setGeometry(QRect(270, 380, 551, 251));
        start = new QPushButton(client);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(30, 450, 81, 29));
        total_send_byte = new QLineEdit(client);
        total_send_byte->setObjectName(QString::fromUtf8("total_send_byte"));
        total_send_byte->setGeometry(QRect(110, 290, 113, 21));
        label_8 = new QLabel(client);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(18, 370, 91, 20));
        label_8->setFont(font);
        label_6 = new QLabel(client);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 920, 69, 20));
        label_6->setFont(font);
        error_byte_ = new QLabel(client);
        error_byte_->setObjectName(QString::fromUtf8("error_byte_"));
        error_byte_->setGeometry(QRect(18, 250, 91, 20));
        error_byte_->setFont(font);
        label_9 = new QLabel(client);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 880, 69, 20));
        label_9->setFont(font);
        cumulative_time = new QLineEdit(client);
        cumulative_time->setObjectName(QString::fromUtf8("cumulative_time"));
        cumulative_time->setGeometry(QRect(100, 960, 113, 21));
        cumulative_time->setReadOnly(true);
        end_time = new QLineEdit(client);
        end_time->setObjectName(QString::fromUtf8("end_time"));
        end_time->setGeometry(QRect(100, 920, 113, 21));
        end_time->setReadOnly(true);
        error_rate_ = new QLineEdit(client);
        error_rate_->setObjectName(QString::fromUtf8("error_rate_"));
        error_rate_->setGeometry(QRect(110, 210, 113, 21));
        error_rate_->setReadOnly(true);
        groupBox_4 = new QGroupBox(client);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(250, 10, 591, 321));
        groupBox_3 = new QGroupBox(client);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 180, 231, 231));
        groupBox = new QGroupBox(client);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 850, 231, 151));
        reset = new QPushButton(client);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(130, 450, 81, 29));
        groupBox_6 = new QGroupBox(client);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 430, 231, 61));
        reset_2 = new QPushButton(client);
        reset_2->setObjectName(QString::fromUtf8("reset_2"));
        reset_2->setGeometry(QRect(130, 520, 81, 29));
        groupBox_7 = new QGroupBox(client);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 500, 231, 61));
        start_2 = new QPushButton(client);
        start_2->setObjectName(QString::fromUtf8("start_2"));
        start_2->setGeometry(QRect(30, 520, 81, 29));
        checkout = new QPushButton(client);
        checkout->setObjectName(QString::fromUtf8("checkout"));
        checkout->setGeometry(QRect(40, 590, 171, 41));
        groupBox_8 = new QGroupBox(client);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 570, 231, 71));
        groupBox_8->raise();
        groupBox_7->raise();
        groupBox->raise();
        groupBox_6->raise();
        groupBox_4->raise();
        groupBox_5->raise();
        recevied_text->raise();
        groupBox_3->raise();
        groupBox_2->raise();
        label_4->raise();
        sended_text->raise();
        error_byte->raise();
        label_10->raise();
        received_byte->raise();
        start_time->raise();
        sended_byte->raise();
        total_send_byte_->raise();
        label_7->raise();
        start->raise();
        total_send_byte->raise();
        label_8->raise();
        label_6->raise();
        error_byte_->raise();
        label_9->raise();
        cumulative_time->raise();
        end_time->raise();
        error_rate_->raise();
        reset->raise();
        reset_2->raise();
        start_2->raise();
        checkout->raise();

        retranslateUi(client);

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QWidget *client)
    {
        client->setWindowTitle(QCoreApplication::translate("client", "Client", nullptr));
        label_4->setText(QCoreApplication::translate("client", "\347\264\257\350\256\241\346\227\266\351\227\264\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("client", "    \350\257\257\347\240\201\347\216\207\357\274\232", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("client", "\346\216\245\346\224\266\346\225\260\346\215\256\357\274\232", nullptr));
        total_send_byte_->setText(QCoreApplication::translate("client", "\351\234\200\345\217\221\351\200\201\345\255\227\350\212\202\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("client", "\345\267\262\345\217\221\351\200\201\345\255\227\350\212\202\357\274\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("client", "IP\350\256\276\347\275\256", nullptr));
        label_11->setText(QCoreApplication::translate("client", "   Port:", nullptr));
        port->setText(QCoreApplication::translate("client", "8888", nullptr));
        label_12->setText(QCoreApplication::translate("client", "    I P:", nullptr));
        server_ip->setText(QCoreApplication::translate("client", "192.168.1.246", nullptr));
        connect->setText(QCoreApplication::translate("client", "connect", nullptr));
        send->setText(QCoreApplication::translate("client", "send", nullptr));
        start->setText(QCoreApplication::translate("client", "\345\274\200\345\247\213", nullptr));
        label_8->setText(QCoreApplication::translate("client", "\345\267\262\346\216\245\346\224\266\345\255\227\350\212\202\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("client", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", nullptr));
        error_byte_->setText(QCoreApplication::translate("client", "  \351\224\231\350\257\257\345\255\227\350\212\202\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("client", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("client", "\345\217\221\351\200\201\346\225\260\346\215\256\357\274\232", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("client", "\350\257\257\347\240\201\347\216\207\347\273\237\350\256\241\357\274\232", nullptr));
        groupBox->setTitle(QCoreApplication::translate("client", "\346\227\266\351\227\264\350\256\260\345\275\225\357\274\232", nullptr));
        reset->setText(QCoreApplication::translate("client", "\346\270\205\351\233\266", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("client", "\350\207\252\345\212\250", nullptr));
        reset_2->setText(QCoreApplication::translate("client", "\346\270\205\351\233\266", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("client", "\346\211\213\345\212\250", nullptr));
        start_2->setText(QCoreApplication::translate("client", "\345\274\200\345\247\213", nullptr));
        checkout->setText(QCoreApplication::translate("client", "\346\211\213\345\212\250\346\240\241\351\252\214", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("client", "\346\240\241\351\252\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
