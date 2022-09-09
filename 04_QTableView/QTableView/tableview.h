#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>
#include <QStandardItem>  //数据模型

#include "cheaderview.h"


namespace Ui {
class TableView;
}

class TableView : public QWidget
{
    Q_OBJECT

public:
    explicit TableView(QWidget *parent = nullptr);
    ~TableView();

private:
    Ui::TableView *ui;

public:
    int checked_count;

public:
    /**
     * @brief setColumnCheckable 设置指定列是否可选（会一同设置model中同一列的单元格）
     * @param column 指定列
     * @param checkable 是否可选值
     */
    void setColumnCheckable(int column, bool checkable);


    /**
     * @brief is_checked 检查是否被勾选
     * @param column 列
     * @param row 行
     * @return 是否被勾选
     */
    int is_checked(int column,int row);

    /**
     * @brief column_checked_count 获取被勾选上选项的数据
     * @param column 第几列
     * @param buf 数据存放至buf
     * @return 被勾选上的数量
     */
    int column_checked_count(int column, QString * buf);

    /**
     * @brief show_ip 指定0列第几排显示数据
     * @param ip 需要显示的数据
     * @param useRow 第几排
     */
    void show_ip(QString ip,int useRow);

public slots:
    /**
     * @brief on_columnSectionClicked 列标题点击槽函数
     * @param column 所点击列
     * @param checked 点击列当前选中值
     */
    void on_columnSectionClicked(int column, bool checked);


private:

    QStandardItemModel  *m_pModel;      //数据模型对象指针

    CHeaderView         *m_pHeaderView; //表头对象指针
};



#endif // TABLEVIEW_H
