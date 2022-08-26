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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_get_multicast
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *get_multicast)
    {
        if (get_multicast->objectName().isEmpty())
            get_multicast->setObjectName(QString::fromUtf8("get_multicast"));
        get_multicast->resize(800, 600);
        centralwidget = new QWidget(get_multicast);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        get_multicast->setCentralWidget(centralwidget);
        menubar = new QMenuBar(get_multicast);
        menubar->setObjectName(QString::fromUtf8("menubar"));
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
    } // retranslateUi

};

namespace Ui {
    class get_multicast: public Ui_get_multicast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GET_MULTICAST_H
