#include "mytablewgt.h"
#include <QScrollBar>
#include <qdebug.h>
#include <QWheelEvent>

MyTableWgt::MyTableWgt(QWidget *parent) : QTableWidget(parent)
{
    connect(this->verticalScrollBar(),&QScrollBar::valueChanged,this,&MyTableWgt::OnVertivalValueChanged);
    m_pDeal= new MyDeal();

    m_pDeal->moveToThread(&m_thread);
    connect(this,&MyTableWgt::startRunning,m_pDeal,&MyDeal::CreateData);
    connect(&m_thread,&QThread::finished,m_pDeal,&QObject::deleteLater);
    connect(m_pDeal,&MyDeal::sSendFinished,this,&MyTableWgt::ReceiverData);
    connect(m_pDeal,&MyDeal::sSendValueChanaged,this,&MyTableWgt::ReceiverChanged);

    m_thread.start();
}

MyTableWgt::~MyTableWgt()
{
    m_thread.quit();
    m_thread.wait();
}

void MyTableWgt::ClearAllRow()
{
    for(int i=this->rowCount();i>0;i--)
    {
        this->removeRow(i);
    }
}

void MyTableWgt::Run()
{
    emit startRunning("aaa.txt");
}

void MyTableWgt::wheelEvent(QWheelEvent *event)
{
    int delta= event->delta();

    int row=m_pDeal->GetCurrentRow();
    if(delta>0)
    {
        if(row<5)
        {
            return;
        }
        else
        {
            row=row-5;  //每次滚动滚轮，向上加载5个
        }
    }
    else
    {
        if(row>m_pDeal->GetDataSize()-100)
        {
            row=m_pDeal->GetDataSize()-100;
        }
        else
        {
            row=row+5;
        }

    }

   m_pDeal->LoadData(row);
}

void MyTableWgt::OnVertivalValueChanged(int i_value)
{
    if(i_value==this->verticalScrollBar()->maximum())
    {
        int row=m_pDeal->GetCurrentRow();

        if(row>m_pDeal->GetDataSize()-200)
        {
            row=m_pDeal->GetDataSize()-100;
        }
        else
        {
            row=row+100;
            this->verticalScrollBar()->setValue(this->verticalScrollBar()->maximum()*0.9);
        }
        qDebug()<<"row::"<<row;
        m_pDeal->LoadData(row);
    }
    if(i_value==this->verticalScrollBar()->minimum())
    {
        int row=m_pDeal->GetCurrentRow();
        if(row>=100)
        {
            row=row-100;
            if(row<100)
            {
                row=0;
            }
            this->verticalScrollBar()->setValue(this->verticalScrollBar()->maximum()*0.1);
        }
        qDebug()<<"row::"<<row;
        m_pDeal->LoadData(row);
    }
}

void MyTableWgt::ReceiverData()
{
    this->ClearAllRow();
    QList<myData> dataList=m_pDeal->GetFirstData();
    this->setRowCount(dataList.size());
    for(int i=0;i<dataList.size();i++)  //首次加载100个
    {
        myData data=dataList[i];
        this->setItem(i,0,new QTableWidgetItem(data.str0));
        this->setItem(i,1,new QTableWidgetItem(data.str1));
        this->setItem(i,2,new QTableWidgetItem(data.str2));
        this->setItem(i,3,new QTableWidgetItem(data.str3));
        this->setItem(i,4,new QTableWidgetItem(data.str4));
        this->setItem(i,5,new QTableWidgetItem(data.str5));
        this->setItem(i,6,new QTableWidgetItem(data.str6));
        this->setItem(i,7,new QTableWidgetItem(data.str7));
        this->setItem(i,8,new QTableWidgetItem(data.str8));
        this->setItem(i,9,new QTableWidgetItem(data.str9));
        this->setItem(i,10,new QTableWidgetItem(data.str10));
    }
}

void MyTableWgt::ReceiverChanged()
{
    this->ClearAllRow();
    this->setRowCount(100);
    //int currentRowcount=this->rowCount();

    QList<myData> dataList=m_pDeal->GetSendData();
    this->setRowCount(100);
    int k=0;
    for(int i=0;i<dataList.size();i++)
    {
        myData data=dataList[i];
        this->setItem(i,0,new QTableWidgetItem(data.str0));
        this->setItem(i,1,new QTableWidgetItem(data.str1));
        this->setItem(i,2,new QTableWidgetItem(data.str2));
        this->setItem(i,3,new QTableWidgetItem(data.str3));
        this->setItem(i,4,new QTableWidgetItem(data.str4));
        this->setItem(i,5,new QTableWidgetItem(data.str5));
        this->setItem(i,6,new QTableWidgetItem(data.str6));
        this->setItem(i,7,new QTableWidgetItem(data.str7));
        this->setItem(i,8,new QTableWidgetItem(data.str8));
        this->setItem(i,9,new QTableWidgetItem(data.str9));
        this->setItem(i,10,new QTableWidgetItem(data.str10));
        k++;
    }
}
