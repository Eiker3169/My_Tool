#include "mydeal.h"
#include <QFile>

MyDeal::MyDeal(QObject *parent) : QObject(parent)
{

}

MyDeal::~MyDeal()
{

}

int MyDeal::GetCurrentRow()
{
    return m_CurrentRow;
}

QList<myData> MyDeal::GetDataList()
{
    return  m_DataList;
}

void MyDeal::LoadData(int row)
{
    m_SendData.clear();
    for(int i=row;i<row+100;i++)
    {
        myData data=m_DataList[i];
        m_SendData.append(data);
    }
    m_CurrentRow=row;
    emit sSendValueChanaged();



//    m_SendData.clear();
//    for(int i=row+m_CurrentRow;i<100;i++)
//    {
//        myData data=m_DataList[i];
//        m_SendData.append(data);
//    }
//    m_CurrentRow=row;
//    emit sSendValueChanaged();



}

QList<myData> MyDeal::GetSendData()
{
    return m_SendData;
}

QList<myData> MyDeal::GetFirstData()
{
    return m_FirstData;
}

int MyDeal::GetDataSize()
{
    return m_DataSize;
}

void MyDeal::CreateData(QString i_path)
{
    m_CurrentRow=0;
    QFile file(i_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    int i=0;
    while (!file.atEnd())
    {
        QString strLine=file.readLine();

        QStringList strList=strLine.split("&");

        myData data;
        data.str0=strList[0];
        data.str1=strList[1];
        data.str2=strList[2];
        data.str3=strList[3];
        data.str4=strList[4];
        data.str5=strList[5];
        data.str6=strList[6];
        data.str7=strList[7];
        data.str8=strList[8];
        data.str9=strList[9];
        data.str10=strList[10];
        m_DataList.append(data);

        if(i<=100)
        {
            m_FirstData.append(data);
        }

        if(i==100)
        {
           emit sSendFinished();
        }

        i++;

    }
    m_DataSize=m_DataList.size();
}
