#ifndef ELEMENTROW_H
#define ELEMENTROW_H

#include <QWidget>
#include <QString>

namespace Ui {
class ElementRow;
}

class ElementRow : public QWidget
{
    Q_OBJECT

public:
    explicit ElementRow(QWidget *parent = nullptr);
    ~ElementRow();

    void setNumberrope(QString number);
    void setAmount(int amount);
    void setCheked(bool index);
    void setRGB(int r, int g, int b);
    void setId(int id);

    int getAmount();
    bool getCheked();
    QString getText();

signals:
    void valueChanged(int id);

private slots:
    void on_checkBox_clicked(bool checked);

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::ElementRow *ui;
    int id_;
};

#endif // ELEMENTROW_H
