#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->hide();
    ui->pushButtonSave->hide();
    addDataBase=new AddDataBase();
    addDataBase->connectDB();
    addComboBox();
    setWindowTitle("Чек-лист для вышивки");
}

MainWindow::~MainWindow()
{
    if(!elementRowList.empty()){
        for(int i = 0; i<elementRowList.size(); i++){
            elementRowList[i]->deleteLater();
        }
        elementRowList.clear();
    }
    if(!serchRowList.empty()){
        for(int i = 0; i<serchRowList.size(); i++){
            serchRowList[i]->deleteLater();
        }
        serchRowList.clear();
    }
    addDataBase->disconnectDB();
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(!elementRowList.empty()){
        for(int i = 0; i<elementRowList.size(); i++){
            elementRowList[i]->deleteLater();
        }
        elementRowList.clear();
    }
    index++;
    if(index==ThreadType::DMC){
        addDataBase->setId(index);
    }
    else if(index==ThreadType::GAMMA){
        addDataBase->setId(index);
    }
    else if(index==ThreadType::PNK){
        addDataBase->setId(index);
    }
    else if(index==ThreadType::ANCHOR){
        addDataBase->setId(index);
    }
    addWidget();
    filling();
}

void MainWindow::addWidget()
{
    int rows = addDataBase->getCount()+1;
    int idRow =1;
    int i = 0;
    int colums = rows/9;
    for(; i<rows; i++){
        ElementRow *elementRow = new ElementRow();
        connect(elementRow,SIGNAL(valueChanged(int)), this, SLOT(saveChanget(int)));
        elementRowList.append(elementRow);
        elementRow->setId(idRow);
        idRow++;
        int row = i%colums;
        int col = i/colums;
        ui->gridLayout_3->addWidget(elementRow, row, col, Qt::AlignTop);
    }
}

void MainWindow::filling()
{
    for(int i = 0; i<elementRowList.size(); i++){
        int k = i;
        elementRowList[i]->setNumberrope(addDataBase->getNumberrope(k+1));
        elementRowList[i]->setAmount(addDataBase->getAmount(k+1));
        elementRowList[i]->setCheked(addDataBase->getIsCheked(k+1));
        elementRowList[i]->setRGB(addDataBase->getR(k+1),addDataBase->getG(k+1),addDataBase->getB(k+1));
    }
}

void MainWindow::addComboBox()
{
    ui->comboBox->addItem("DMC");
    ui->comboBox->addItem("Гамма");
    ui->comboBox->addItem("ПНК Кирова");
    ui->comboBox->addItem("Anchor");
}

void MainWindow::on_toolButton_clicked(bool checked)
{
    on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
    if(!serchRowList.empty()){
        for(int i = 0; i<serchRowList.size(); i++){
            serchRowList[i]->deleteLater();
        }
        serchRowList.clear();
    }
    if(checked==false){
        for(int i = 0; i<elementRowList.size(); i++){
            if(elementRowList[i]->getCheked()==true){                
                serchRowList.append(elementRowList[i]);
            }
        }
    }
    if(!serchRowList.empty()){
        ui->toolButton->setText("Показать все");
    }
    else{
        ui->toolButton->setChecked(true);
        ui->toolButton->setText("Показать отмеченные");
    }
    serchList();
}

void MainWindow::on_pushButton_clicked()
{
    serch(ui->lineEdit->text());
}

void MainWindow::on_pushButtonSave_clicked()
{

}

void MainWindow::saveChanget(int idRow)
{
    // int id, QString numberrope, int amount, bool isvalue
    addDataBase->setUpdate(idRow, elementRowList[idRow-1]->getText(), elementRowList[idRow-1]->getAmount(), elementRowList[idRow-1]->getCheked());
}

void MainWindow::on_pushButtonReset_clicked()
{
    serch("");
}

void MainWindow::serch(QString serch)
{
    on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
    if(!serchRowList.empty()){
        for(int i = 0; i<serchRowList.size(); i++){
            serchRowList[i]->deleteLater();
        }
        serchRowList.clear();
    }
    for(int i = 0; i<(elementRowList.size()); i++){
        QString str = elementRowList[i]->getText();
        if(str.contains(serch) && !serch.isEmpty()){
            serchRowList.append(elementRowList[i]);
        }
    }
    serchList();
}

void MainWindow::serchList()
{
    if(!serchRowList.empty()){
        for(int i = 0; i<(elementRowList.size()); i++){
            ui->gridLayout_3->removeWidget(elementRowList[i]);
            elementRowList[i]->hide();
        }
        int colums = serchRowList.size()/9;
        if(colums==0) colums++;
        for(int i = 0; i<serchRowList.size(); i++){
            int col = i%colums;
            int row = i/colums;
            ui->gridLayout_3->addWidget(serchRowList[i], row, col, Qt::AlignTop);
            serchRowList[i]->show();
        }
    }
}

