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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_get_multicast
{
public:
    QWidget *centralwidget;
    QPushButton *scan_ip;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *get_multicast)
    {
        if (get_multicast->objectName().isEmpty())
            get_multicast->setObjectName(QString::fromUtf8("get_multicast"));
        get_multicast->resize(800, 600);
        centralwidget = new QWidget(get_multicast);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scan_ip = new QPushButton(centralwidget);
        scan_ip->setObjectName(QString::fromUtf8("scan_ip"));
        scan_ip->setGeometry(QRect(350, 10, 121, 29));
        get_multicast->setCentralWidget(centralwidget);
        menubar = new QMenuBar(get_multicast);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
    } // retranslateUi

};

namespace Ui {
    class get_multicast: public Ui_get_multicast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GET_MULTICAST_H
