#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <adddatabase.h>
#include <elementrow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_toolButton_clicked(bool checked);

    void on_pushButton_clicked();

    void on_pushButtonSave_clicked();

    void saveChanget(int idRow);

    void on_pushButtonReset_clicked();

private:
    Ui::MainWindow *ui;

    void addComboBox();
    void addWidget();
    void filling();
    void serch(QString serch);
    void serchList();

    AddDataBase *addDataBase;
    QList<ElementRow *> elementRowList;
    QList<ElementRow *> serchRowList;

    int id_;
};

#endif // MAINWINDOW_H
