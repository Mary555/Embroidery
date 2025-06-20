#include "elementvertikal.h"
#include "ui_elementvertikal.h"

ElementVertikal::ElementVertikal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElementVertikal)
{
    ui->setupUi(this);
}

ElementVertikal::~ElementVertikal()
{
    delete ui;
}

void ElementVertikal::addWidget(QWidget *parent)
{
    ui->verticalLayout->addWidget(parent);
}
