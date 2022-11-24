#ifndef DYNAMIC_QTABLEVIEW_H
#define DYNAMIC_QTABLEVIEW_H

#include <QMainWindow>
#include <QStandardItem>  //数据模型
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QMessageBox>

#include "cheaderview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class dynamic_QTableView; }
QT_END_NAMESPACE

class dynamic_QTableView : public QMainWindow
{
    Q_OBJECT

public:
    dynamic_QTableView(QWidget *parent = nullptr);
    ~dynamic_QTableView();

private:
    Ui::dynamic_QTableView *ui;

private:
    QStandardItemModel  *m_pModel;      //数据模型对象指针
    CHeaderView         *m_pHeaderView; //表头对象指针

public:
    QTimer timer;

    bool clear_text = false;

    int row_index = 0;
    int test_add = 0;



public:
    /**
     * @brief tableview_init table初始化
     */
    void tableview_init(void);

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
     * @brief export_data 导出选中数据
     */
    void export_data(void);

    /**
     * @brief write_text 导出数据至text文件
     * @param str
     */
    bool write_text(QString str);

    /**
     * @brief column_checked_count 获取被勾选上选项的数据
     * @param column 第几列
     * @param buf 数据存放至buf
     * @return 被勾选上的数量
     */
    int column_checked_count(int column, QString * buf);

    /**
     * @brief test_auto_add 测试自动添加
     */
    void test_auto_add(void);

public slots:
    /**
     * @brief on_columnSectionClicked 列标题点击槽函数
     * @param column 所点击列
     * @param checked 点击列当前选中值
     */
    void on_columnSectionClicked(int column, bool checked);

    /**
     * @brief add_row 添加一行
     */
    void add_row(void);
private slots:
    void on_actionexport_triggered();
};
#endif // DYNAMIC_QTABLEVIEW_H
