#ifndef ADDDATABASE_H
#define ADDDATABASE_H

#include <QList>
#include <QtSql>

enum ThreadType{
    DMC=1,
    GAMMA,
    PNK,
    ANCHOR
};

class AddDataBase
{
public:
    AddDataBase();

    void connectDB();
    void disconnectDB();

    int getCount();
    QString getNumberrope(int id);
    int getAmount(int id);
    bool getIsCheked(int id);
    int getR(int id);
    int getG(int id);
    int getB(int id);

    void setId(int id);
    bool setUpdate(int id, QString numberrope, int amount, bool isvalue);

private:
    int id_;
    QSqlDatabase sdb;
    QString path;
};

#endif // ADDDATABASE_H
