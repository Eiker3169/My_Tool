/********************************************************************************
** Form generated from reading UI file 'tableview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEVIEW_H
#define UI_TABLEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableView
{
public:
    QTableView *tableView;

    void setupUi(QWidget *TableView)
    {
        if (TableView->objectName().isEmpty())
            TableView->setObjectName(QString::fromUtf8("TableView"));
        TableView->resize(643, 531);
        tableView = new QTableView(TableView);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(60, 10, 501, 481));

        retranslateUi(TableView);

        QMetaObject::connectSlotsByName(TableView);
    } // setupUi

    void retranslateUi(QWidget *TableView)
    {
        TableView->setWindowTitle(QCoreApplication::translate("TableView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableView: public Ui_TableView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEVIEW_H
