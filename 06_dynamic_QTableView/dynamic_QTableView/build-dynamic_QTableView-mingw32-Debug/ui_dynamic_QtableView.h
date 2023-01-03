/********************************************************************************
** Form generated from reading UI file 'dynamic_QtableView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DYNAMIC_QTABLEVIEW_H
#define UI_DYNAMIC_QTABLEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dynamic_QTableView
{
public:
    QAction *action;
    QAction *actionexport;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menuoption;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *dynamic_QTableView)
    {
        if (dynamic_QTableView->objectName().isEmpty())
            dynamic_QTableView->setObjectName(QString::fromUtf8("dynamic_QTableView"));
        dynamic_QTableView->resize(800, 600);
        action = new QAction(dynamic_QTableView);
        action->setObjectName(QString::fromUtf8("action"));
        actionexport = new QAction(dynamic_QTableView);
        actionexport->setObjectName(QString::fromUtf8("actionexport"));
        centralwidget = new QWidget(dynamic_QTableView);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        dynamic_QTableView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(dynamic_QTableView);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuoption = new QMenu(menubar);
        menuoption->setObjectName(QString::fromUtf8("menuoption"));
        dynamic_QTableView->setMenuBar(menubar);
        statusbar = new QStatusBar(dynamic_QTableView);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        dynamic_QTableView->setStatusBar(statusbar);

        menubar->addAction(menuoption->menuAction());
        menuoption->addAction(actionexport);

        retranslateUi(dynamic_QTableView);

        QMetaObject::connectSlotsByName(dynamic_QTableView);
    } // setupUi

    void retranslateUi(QMainWindow *dynamic_QTableView)
    {
        dynamic_QTableView->setWindowTitle(QCoreApplication::translate("dynamic_QTableView", "dynamic_QTableView", nullptr));
        action->setText(QCoreApplication::translate("dynamic_QTableView", "\351\200\211\351\241\271", nullptr));
        actionexport->setText(QCoreApplication::translate("dynamic_QTableView", "export", nullptr));
        menuoption->setTitle(QCoreApplication::translate("dynamic_QTableView", "option", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dynamic_QTableView: public Ui_dynamic_QTableView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DYNAMIC_QTABLEVIEW_H
