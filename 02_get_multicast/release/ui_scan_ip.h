/********************************************************************************
** Form generated from reading UI file 'scan_ip.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCAN_IP_H
#define UI_SCAN_IP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scan_ip
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *scan_ip)
    {
        if (scan_ip->objectName().isEmpty())
            scan_ip->setObjectName(QString::fromUtf8("scan_ip"));
        scan_ip->resize(322, 340);
        tableWidget = new QTableWidget(scan_ip);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 10, 191, 321));

        retranslateUi(scan_ip);

        QMetaObject::connectSlotsByName(scan_ip);
    } // setupUi

    void retranslateUi(QWidget *scan_ip)
    {
        scan_ip->setWindowTitle(QCoreApplication::translate("scan_ip", "\345\234\250\347\272\277\345\237\272\347\253\231", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("scan_ip", "IP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class scan_ip: public Ui_scan_ip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCAN_IP_H
