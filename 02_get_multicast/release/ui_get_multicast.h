/********************************************************************************
** Form generated from reading UI file 'get_multicast.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GET_MULTICAST_H
#define UI_GET_MULTICAST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_get_multicast
{
public:
    QWidget *centralwidget;
    QPushButton *scan_ip;
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *n_1;
    QLineEdit *x_1;
    QLineEdit *data_1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *n_2;
    QLineEdit *x_2;
    QLineEdit *data_2;
    QLabel *label_5;
    QGroupBox *groupBox_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *port;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *IP;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *get_multicast)
    {
        if (get_multicast->objectName().isEmpty())
            get_multicast->setObjectName(QString::fromUtf8("get_multicast"));
        get_multicast->resize(800, 469);
        centralwidget = new QWidget(get_multicast);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scan_ip = new QPushButton(centralwidget);
        scan_ip->setObjectName(QString::fromUtf8("scan_ip"));
        scan_ip->setGeometry(QRect(630, 30, 60, 131));
        scan_ip->setMinimumSize(QSize(60, 0));
        scan_ip->setMaximumSize(QSize(60, 16777215));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(380, 30, 241, 131));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 216, 108));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(label_3);

        n_1 = new QLineEdit(widget);
        n_1->setObjectName(QString::fromUtf8("n_1"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(n_1->sizePolicy().hasHeightForWidth());
        n_1->setSizePolicy(sizePolicy1);
        n_1->setMinimumSize(QSize(16, 25));
        n_1->setMaximumSize(QSize(16, 25));
        n_1->setStyleSheet(QString::fromUtf8("QLineEdit{qproperty-alignment:AlignHCenter;}\n"
"edit->setAlignment( Qt::AlignHCenter);"));

        horizontalLayout_3->addWidget(n_1);

        x_1 = new QLineEdit(widget);
        x_1->setObjectName(QString::fromUtf8("x_1"));
        sizePolicy1.setHeightForWidth(x_1->sizePolicy().hasHeightForWidth());
        x_1->setSizePolicy(sizePolicy1);
        x_1->setMinimumSize(QSize(16, 25));
        x_1->setMaximumSize(QSize(16, 25));
        x_1->setStyleSheet(QString::fromUtf8("QLineEdit{qproperty-alignment:AlignHCenter;}\n"
"edit->setAlignment( Qt::AlignHCenter);"));

        horizontalLayout_3->addWidget(x_1);

        data_1 = new QLineEdit(widget);
        data_1->setObjectName(QString::fromUtf8("data_1"));
        sizePolicy1.setHeightForWidth(data_1->sizePolicy().hasHeightForWidth());
        data_1->setSizePolicy(sizePolicy1);
        data_1->setMinimumSize(QSize(80, 25));
        data_1->setMaximumSize(QSize(80, 25));
        data_1->setStyleSheet(QString::fromUtf8("QLineEdit{qproperty-alignment:AlignHCenter;}\n"
"edit->setAlignment( Qt::AlignHCenter);"));

        horizontalLayout_3->addWidget(data_1);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_4->addWidget(label_4);

        n_2 = new QLineEdit(widget);
        n_2->setObjectName(QString::fromUtf8("n_2"));
        sizePolicy1.setHeightForWidth(n_2->sizePolicy().hasHeightForWidth());
        n_2->setSizePolicy(sizePolicy1);
        n_2->setMinimumSize(QSize(16, 25));
        n_2->setMaximumSize(QSize(16, 25));
        n_2->setStyleSheet(QString::fromUtf8("QLineEdit{qproperty-alignment:AlignHCenter;}\n"
"edit->setAlignment( Qt::AlignHCenter);"));

        horizontalLayout_4->addWidget(n_2);

        x_2 = new QLineEdit(widget);
        x_2->setObjectName(QString::fromUtf8("x_2"));
        sizePolicy1.setHeightForWidth(x_2->sizePolicy().hasHeightForWidth());
        x_2->setSizePolicy(sizePolicy1);
        x_2->setMinimumSize(QSize(16, 25));
        x_2->setMaximumSize(QSize(16, 25));
        x_2->setStyleSheet(QString::fromUtf8("QLineEdit{qproperty-alignment:AlignHCenter;}\n"
"edit->setAlignment( Qt::AlignHCenter);"));

        horizontalLayout_4->addWidget(x_2);

        data_2 = new QLineEdit(widget);
        data_2->setObjectName(QString::fromUtf8("data_2"));
        sizePolicy1.setHeightForWidth(data_2->sizePolicy().hasHeightForWidth());
        data_2->setSizePolicy(sizePolicy1);
        data_2->setMinimumSize(QSize(80, 25));
        data_2->setMaximumSize(QSize(80, 25));
        data_2->setStyleSheet(QString::fromUtf8("QLineEdit{qproperty-alignment:AlignHCenter;}\n"
"edit->setAlignment( Qt::AlignHCenter);"));

        horizontalLayout_4->addWidget(data_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(25);
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMaximumSize(QSize(16777215, 25));

        verticalLayout_3->addWidget(label_5);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(140, 30, 221, 131));
        widget1 = new QWidget(groupBox_2);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 30, 191, 84));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(60, 0));
        label->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(label);

        port = new QLineEdit(widget1);
        port->setObjectName(QString::fromUtf8("port"));
        port->setStyleSheet(QString::fromUtf8("QLineEdit{qproperty-alignment:AlignHCenter;}\n"
"edit->setAlignment( Qt::AlignHCenter);"));

        horizontalLayout->addWidget(port);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(label_2);

        IP = new QLineEdit(widget1);
        IP->setObjectName(QString::fromUtf8("IP"));
        IP->setStyleSheet(QString::fromUtf8("QLineEdit{qproperty-alignment:AlignHCenter;}\n"
"edit->setAlignment( Qt::AlignHCenter);"));

        horizontalLayout_2->addWidget(IP);


        verticalLayout->addLayout(horizontalLayout_2);

        get_multicast->setCentralWidget(centralwidget);
        menubar = new QMenuBar(get_multicast);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        get_multicast->setMenuBar(menubar);
        statusbar = new QStatusBar(get_multicast);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        get_multicast->setStatusBar(statusbar);

        retranslateUi(get_multicast);

        QMetaObject::connectSlotsByName(get_multicast);
    } // setupUi

    void retranslateUi(QMainWindow *get_multicast)
    {
        get_multicast->setWindowTitle(QCoreApplication::translate("get_multicast", "get_multicast", nullptr));
        scan_ip->setText(QCoreApplication::translate("get_multicast", "\346\211\253\346\217\217", nullptr));
        groupBox->setTitle(QCoreApplication::translate("get_multicast", "\346\225\260\346\215\256\347\255\233\351\200\211\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("get_multicast", "\346\225\260\346\215\256\347\255\233\351\200\2111\357\274\232", nullptr));
        n_1->setText(QCoreApplication::translate("get_multicast", "n", nullptr));
        x_1->setText(QCoreApplication::translate("get_multicast", "x", nullptr));
        data_1->setText(QCoreApplication::translate("get_multicast", "data", nullptr));
        label_4->setText(QCoreApplication::translate("get_multicast", "\346\225\260\346\215\256\347\255\233\351\200\2112\357\274\232", nullptr));
        n_2->setText(QCoreApplication::translate("get_multicast", "n", nullptr));
        x_2->setText(QCoreApplication::translate("get_multicast", "x", nullptr));
        data_2->setText(QCoreApplication::translate("get_multicast", "data", nullptr));
        label_5->setText(QCoreApplication::translate("get_multicast", "data\345\234\250\346\225\260\346\215\256\344\275\215\347\232\204\347\254\254n\344\275\215\357\274\214\350\277\236\347\273\255x\344\275\215", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("get_multicast", "\347\253\257\345\217\243\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("get_multicast", "\347\273\204\346\222\255\347\253\257\345\217\243:", nullptr));
        label_2->setText(QCoreApplication::translate("get_multicast", "\347\273\204\346\222\255  IP:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class get_multicast: public Ui_get_multicast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GET_MULTICAST_H
