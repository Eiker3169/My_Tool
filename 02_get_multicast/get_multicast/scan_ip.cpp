#include "scan_ip.h"
#include "ui_scan_ip.h"
#include "QDebug"

scan_ip::scan_ip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scan_ip)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(255);
  //  show_ip("192.168.3.10",0);

}

scan_ip::~scan_ip()
{
    delete ui;

}

void scan_ip::show_ip(QString ip,int useRow)
{
    QTableWidgetItem *ipItem = new QTableWidgetItem;
    ipItem->setText(ip);
    ui->tableWidget->setItem(useRow, 0, ipItem);
}
