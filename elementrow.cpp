#include "elementrow.h"
#include "ui_elementrow.h"

ElementRow::ElementRow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElementRow)
{
    ui->setupUi(this);
}

ElementRow::~ElementRow()
{
    delete ui;
}

void ElementRow::setNumberrope(QString number)
{
    ui->checkBox->setText(number);
}

void ElementRow::setAmount(int amount)
{
    ui->spinBox->setValue(amount);
}

void ElementRow::setCheked(bool index)
{
    ui->checkBox->setChecked(index);
}

void ElementRow::setId(int id)
{
    id_=id;
}

int ElementRow::getAmount()
{
    return ui->spinBox->value();
}

bool ElementRow::getCheked()
{
    return ui->checkBox->isChecked();
}

QString ElementRow::getText()
{
    return ui->checkBox->text();
}

void ElementRow::on_checkBox_clicked(bool checked)
{
    if(checked==false)
        setAmount(0);
    emit valueChanged(id_);
}

void ElementRow::on_spinBox_valueChanged(int arg1)
{
    if(arg1!=0)
        setCheked(true);
    else
        setCheked(false);
    emit valueChanged(id_);
}
