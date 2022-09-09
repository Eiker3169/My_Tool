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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QLabel *label;
    QGroupBox *groupBox_2;
    QTextEdit *write_text;
    QPushButton *send;
    QGroupBox *groupBox;
    QTextEdit *read_text;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *server_ip;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *port;

    void setupUi(QWidget *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName(QString::fromUtf8("client"));
        client->resize(451, 379);
        label = new QLabel(client);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 10, 69, 20));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        groupBox_2 = new QGroupBox(client);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 30, 431, 151));
        write_text = new QTextEdit(groupBox_2);
        write_text->setObjectName(QString::fromUtf8("write_text"));
        write_text->setGeometry(QRect(10, 20, 411, 81));
        send = new QPushButton(groupBox_2);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(10, 110, 411, 29));
        groupBox = new QGroupBox(client);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 190, 431, 121));
        read_text = new QTextEdit(groupBox);
        read_text->setObjectName(QString::fromUtf8("read_text"));
        read_text->setGeometry(QRect(10, 20, 411, 81));
        pushButton = new QPushButton(client);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 320, 71, 51));
        layoutWidget = new QWidget(client);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 320, 207, 53));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        server_ip = new QLineEdit(layoutWidget);
        server_ip->setObjectName(QString::fromUtf8("server_ip"));

        horizontalLayout->addWidget(server_ip);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(64, 0));
        label_3->setMaximumSize(QSize(64, 16777215));

        horizontalLayout_2->addWidget(label_3);

        port = new QLineEdit(layoutWidget);
        port->setObjectName(QString::fromUtf8("port"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(port->sizePolicy().hasHeightForWidth());
        port->setSizePolicy(sizePolicy1);
        port->setMinimumSize(QSize(132, 0));
        port->setMaximumSize(QSize(132, 16777215));

        horizontalLayout_2->addWidget(port);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(client);

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QWidget *client)
    {
        client->setWindowTitle(QCoreApplication::translate("client", "Client", nullptr));
        label->setText(QCoreApplication::translate("client", "Client", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("client", "Write", nullptr));
        send->setText(QCoreApplication::translate("client", "send", nullptr));
        groupBox->setTitle(QCoreApplication::translate("client", "Read", nullptr));
        pushButton->setText(QCoreApplication::translate("client", "connect", nullptr));
        label_2->setText(QCoreApplication::translate("client", "Server IP\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("client", "Port\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
