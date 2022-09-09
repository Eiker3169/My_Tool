/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_server
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QTextEdit *read_text;
    QGroupBox *groupBox_2;
    QTextEdit *write_text;
    QPushButton *send;
    QLabel *label_2;

    void setupUi(QWidget *server)
    {
        if (server->objectName().isEmpty())
            server->setObjectName(QString::fromUtf8("server"));
        server->resize(451, 379);
        label = new QLabel(server);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 10, 81, 20));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        groupBox = new QGroupBox(server);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 431, 141));
        read_text = new QTextEdit(groupBox);
        read_text->setObjectName(QString::fromUtf8("read_text"));
        read_text->setGeometry(QRect(10, 20, 411, 111));
        groupBox_2 = new QGroupBox(server);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 190, 431, 181));
        write_text = new QTextEdit(groupBox_2);
        write_text->setObjectName(QString::fromUtf8("write_text"));
        write_text->setGeometry(QRect(10, 20, 411, 111));
        send = new QPushButton(groupBox_2);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(10, 140, 411, 29));
        label_2 = new QLabel(server);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 20, 69, 20));

        retranslateUi(server);

        QMetaObject::connectSlotsByName(server);
    } // setupUi

    void retranslateUi(QWidget *server)
    {
        server->setWindowTitle(QCoreApplication::translate("server", "Server", nullptr));
        label->setText(QCoreApplication::translate("server", "Server", nullptr));
        groupBox->setTitle(QCoreApplication::translate("server", "Read", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("server", "Write", nullptr));
        send->setText(QCoreApplication::translate("server", "send", nullptr));
        label_2->setText(QCoreApplication::translate("server", "Port:8888", nullptr));
    } // retranslateUi

};

namespace Ui {
    class server: public Ui_server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
