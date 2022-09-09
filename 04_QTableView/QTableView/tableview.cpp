#include "tableview.h"
#include "ui_tableview.h"

TableView::TableView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableView)
{
    ui->setupUi(this);

    this->setWindowTitle("QTableView简单使用");

       //建立模型对象空间并指定父对象
       m_pModel = new QStandardItemModel(ui->tableView);
       //添加列标题
       m_pModel->setHorizontalHeaderLabels(QStringList() << "On Line IP" );
       //将数据模型设置到表对象上
       ui->tableView->setModel(m_pModel);


       //建立表头对象空间并指定父对象
       m_pHeaderView = new CHeaderView(Qt::Horizontal, ui->tableView);
       //将表对象的表头设为自定义表头
       ui->tableView->setHorizontalHeader(m_pHeaderView);
       //连接表头点击信号槽
       connect(m_pHeaderView, &CHeaderView::columnSectionClicked
               , this, &TableView::on_columnSectionClicked);

      ui->tableView->setColumnWidth(0,150);

//       //添加列
       for(int index = 0; index != 256; ++index)
       {
           m_pModel->appendRow(QList<QStandardItem *>()
                               << new QStandardItem(QString("")) );
       }

       //设置为可选
       this->setColumnCheckable(0, true);

}

TableView::~TableView()
{
    delete ui;
}




void TableView::on_columnSectionClicked(int column, bool checked)
{
    //遍历行
    for(int row = 0; row != m_pModel->rowCount(); ++row)
    {
        //获取指定列当前行的item,根据checked设置选中状态
        if(checked)
        {
            m_pModel->item(row, column)->setCheckState(Qt::Checked);
        }
        else
        {
            m_pModel->item(row, column)->setCheckState(Qt::Unchecked);
        }
    }
}

//后续添加
void TableView::setColumnCheckable(int column, bool checkable)
{
    m_pHeaderView->setColumnCheckable(column, checkable);
    for(int row = 0; row != m_pModel->rowCount(); ++row)
    {
        m_pModel->item(row, column)->setCheckable(checkable);
        m_pModel->item(row,column)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    }
}

int TableView::is_checked(int column, int row)
{
    if(m_pModel->item(column,row)->checkState() == Qt::Checked){
       return Qt::Checked;
    }
    else
    {

        return Qt::Unchecked;
    }
}

int TableView::column_checked_count(int column, QString *buf)
{
    int i = 0;
    for(int row = 0; row != m_pModel->rowCount(); ++row)
    {
        if(is_checked(column,row)==Qt::Checked)
        {
            buf[i] = m_pModel->item(row,column)->text();
            i++;
        }
    }
    return i;
}

void TableView::show_ip(QString ip, int useRow)
{
    m_pModel->item(useRow,0)->setText(ip);
}




