#include "widget.h"
#include <QVBoxLayout>
#include <qdebug.h>
#include <QTableWidgetItem>
#include <QScrollBar>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    this->resize(800,600);
    m_pTableWgt=new MyTableWgt(this);
    m_pTableWgt->Run();
    m_pTableWgt->setColumnCount(15);
    QStringList headerList;
    for(int i=0;i<15;i++)
    {
        headerList.append(QString::fromLocal8Bit(DefQSReceiverInfoTableSize[i][0]));
    }
    m_pTableWgt->setHorizontalHeaderLabels(headerList);

    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(m_pTableWgt);
    mainLayout->setMargin(0);
    this->setLayout(mainLayout);

}

Widget::~Widget()
{

}



