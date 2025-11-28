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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    for(int i = 0; i<elementRowList.size(); i++){
        elementRowList[i]->deleteLater();
    }
    elementRowList.clear();
    index += 1;
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
        ui->gridLayout_3->addWidget(elementRow, row, col, Qt::AlignJustify);
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
    if(checked==false){
        ui->toolButton->setText("Показать все");
        for(int i = 0; i<elementRowList.size(); i++){
            if(elementRowList[i]->getCheked()==true){
                elementRowList[i]->show();
            }
            else{
                elementRowList[i]->hide();
            }
        }
    }
    else{
        ui->toolButton->setText("Показать отмеченные");
        for(int i = 0; i<elementRowList.size(); i++){
            elementRowList[i]->show();
        }
    }
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
    for(int i = 0; i<elementRowList.size(); i++){
        QString str = elementRowList[i]->getText();
        if(str.contains(serch)){
            elementRowList[i]->show();
        }
        else{
            elementRowList[i]->hide();
        }

        if (serch.isEmpty()){
            elementRowList[i]->show();
        }
    }
}

