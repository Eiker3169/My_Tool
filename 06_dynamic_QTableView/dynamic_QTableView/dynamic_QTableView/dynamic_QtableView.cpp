#include "dynamic_QtableView.h"
#include "ui_dynamic_QtableView.h"

dynamic_QTableView::dynamic_QTableView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dynamic_QTableView)
{
    ui->setupUi(this);
    tableview_init();
    test_auto_add();
}

dynamic_QTableView::~dynamic_QTableView()
{
    delete ui;
}

void dynamic_QTableView::tableview_init()
{
    this->setWindowTitle("dynamic_qtableview");

    //建立模型对象空间并指定父对象
    m_pModel = new QStandardItemModel(ui->tableView);
    //添加列标题
    m_pModel->setHorizontalHeaderLabels(QStringList() << "confidence"
                                        <<"propertys[0]"
                                        <<"propertys[1]"
                                        <<"propertys[2]"
                                        <<"propertys[3]"
                                        <<"propertys[4]"
                                        <<"propertys[5]"
                                        <<"propertys[6]"
                                        <<"propertys[7]"
                                        <<"propertys[8]"
                                        <<"propertys[9]"
                                        <<"propertys[10]"
                                        <<"propertys[11]"
                                        <<"propertys[12]"
                                        <<"propertys[13]");

    //将数据模型设置到表对象上
    ui->tableView->setModel(m_pModel);
    //建立表头对象空间并指定父对象
    m_pHeaderView = new CHeaderView(Qt::Horizontal, ui->tableView);
    //将表对象的表头设为自定义表头
    ui->tableView->setHorizontalHeader(m_pHeaderView);
    //连接表头点击信号槽
    connect(m_pHeaderView, &CHeaderView::columnSectionClicked
            , this, &dynamic_QTableView::on_columnSectionClicked);

    //设置为可选
    this->setColumnCheckable(0, true);
}

void dynamic_QTableView::setColumnCheckable(int column, bool checkable)
{
    m_pHeaderView->setColumnCheckable(column, checkable);
    for(int row = 0; row != m_pModel->rowCount(); ++row)
    {
        m_pModel->item(row, column)->setCheckable(checkable);


    }
}

int dynamic_QTableView::is_checked(int column, int row)
{
    if(m_pModel->item(row,column)->checkState() == Qt::Checked){
       return Qt::Checked;
    }
    else
    {

        return Qt::Unchecked;
    }
}

void dynamic_QTableView::export_data()
{

    for(int row = 0; row != m_pModel->rowCount(); ++row)
    {
        if(is_checked(0,row)==Qt::Checked)
        {
            QString str = m_pModel->item(row,0)->text();
            write_text(str);
        }
    }



    QMessageBox msgBox;
    msgBox.warning(this, "导出数据", "导出已完成");


//    for(int row = 0; row != m_pModel->rowCount(); ++row)
//    {
//        if(is_checked(0,row)==Qt::Checked)
//        {
//            m_pModel->item(0,row)->setCheckState(Qt::Unchecked);
//        }
//    }


}

bool dynamic_QTableView::write_text(QString str)
{
    QString fileName = "export.txt";

    QFile file(fileName);

    if(!file.exists()){
        return false;
    }
    if(clear_text == true){
        clear_text = false;
        if(!file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate )){
            return false;
        }

    }
    else{
        if(!file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append )){
            return false;
        }

    }

    QTextStream stream(&file);

    QDateTime dateTime= QDateTime::currentDateTime();

    QString tmp_str = dateTime .toString("yyyy-MM-dd hh:mm:ss");


    tmp_str = tmp_str + "  " + str;

    stream<<tmp_str<<Qt::endl;

    file.close();

    return true;
}

int dynamic_QTableView::column_checked_count(int column, QString *buf)
{
    int i = 0;
    for(int row = 0; row != m_pModel->rowCount(); ++row)
    {
        if(is_checked(column,row)==Qt::Checked)
        {
            if(m_pModel->item(row,column)->text()!="")
            {
            buf[i] = m_pModel->item(row,column)->text();
            i++;
            }
        }
    }
    return i;
}

void dynamic_QTableView::add_row()
{
    test_add++;

    QString str[15] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"};

//    for(int i = 0; i < 15; i++){
//        QList<QStandardItem *>()<< new QStandardItem(QString("A"));
//    }
    m_pModel->appendRow(QList<QStandardItem *>()<< new QStandardItem(str[0])
                                                << new QStandardItem(str[1])
                                                << new QStandardItem(str[2])
                                                   << new QStandardItem(str[3])
                                                      << new QStandardItem(str[4])
                                                         << new QStandardItem(str[5])
                                                            << new QStandardItem(str[6])
                                                               << new QStandardItem(str[7])
                                                                  << new QStandardItem(str[8])
                                                                     << new QStandardItem(str[9])
                                                                        << new QStandardItem(str[10])
                                                                           << new QStandardItem(str[11])
                                                                              << new QStandardItem(str[12])
                                                                                 << new QStandardItem(str[13])
                                                                                    << new QStandardItem(str[14])

                        );

    for(int i = 0; i < 15; i++){
        if((row_index % 7) == 0){
            m_pModel->item(row_index,i)->setForeground(QBrush(QColor(255, 0, 0)));   //红
        }
        if((row_index % 7) == 1){
            m_pModel->item(row_index,i)->setForeground(QBrush(QColor(160, 32, 240))); //紫色
        }
        if((row_index % 7) == 2){
            m_pModel->item(row_index,i)->setForeground(QBrush(QColor(0, 0, 255)));    //蓝色
        }
        if((row_index % 7) == 3){
            m_pModel->item(row_index,i)->setForeground(QBrush(QColor(0, 255, 0)));    //绿色
        }
        if((row_index % 7) == 4){
            m_pModel->item(row_index,i)->setForeground(QBrush(QColor(128, 42, 42)));  //棕色
        }
        if((row_index % 7) == 5){
            m_pModel->item(row_index,i)->setForeground(QBrush(QColor(64, 224, 208))); //青绿色
        }
        if((row_index % 7) == 6){
            m_pModel->item(row_index,i)->setForeground(QBrush(QColor(221, 160, 221))); //梅红色
        }
        m_pModel->item(row_index,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }
    row_index++;

    this->setColumnCheckable(0, true);

    if(test_add == 20){
        QObject::disconnect(&timer, SIGNAL(timeout()), this, SLOT(add_row()));
        test_add = 0;
    }


}

void dynamic_QTableView::test_auto_add()
{
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(add_row()));
    timer.start(1000);
}

void dynamic_QTableView::on_columnSectionClicked(int column, bool checked)
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



void dynamic_QTableView::on_actionexport_triggered()
{
    clear_text = true;
    export_data();

}

