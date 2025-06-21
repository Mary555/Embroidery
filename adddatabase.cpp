#include "adddatabase.h"
#include <QtSql>
#include <QDir>

AddDataBase::AddDataBase()
{

}

void AddDataBase::connectDB()
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    QDir dir;
    QString path = dir.absolutePath();
    qDebug() << path+"/CheckList.sqlite";
    sdb.setDatabaseName(path+"/CheckList.sqlite");
    if (!sdb.open()) {
        qDebug() << sdb.lastError().text();
    }
}

int AddDataBase::getCount()
{
    QSqlQuery qry;
    int count = 0;
    if(id_==ThreadType::DMC){
        qry.prepare( "SELECT * FROM dmc;" );
    }
    else if(id_==ThreadType::GAMMA){
        qry.prepare( "SELECT * FROM gamma;" );
    }
    else if(id_==ThreadType::PNK){
        qry.prepare( "SELECT * FROM kirova;" );
    }
    else if(id_==ThreadType::ANCHOR){
        qry.prepare( "SELECT * FROM anchor;" );
    }

    if( !qry.exec() )
        qDebug() << qry.lastError().text();
    else{
        qDebug() <<QString::number(id_)+" Selected!";

        QSqlRecord rec = qry.record();

        int cols = rec.count();

//        for( int c=0; c<cols; c++ )
//            qDebug() << QString( "Column %1: %2" ).arg( c ).arg( rec.fieldName(c) );

        for( int r=0; qry.next(); r++ )
            for( int c=0; c<cols; c++ ){
//                qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( qry.value(c).toString() );
                count = r;
            }
    }
    return count;
}

QString AddDataBase::getNumberrope(int id)
{
    QSqlQuery qry;
    QString number;
    QString id1=QString::number(id);
    if(id_==ThreadType::DMC){
        qry.prepare( "SELECT numberrope FROM dmc WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::GAMMA){
        qry.prepare( "SELECT numberrope FROM gamma WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::PNK){
        qry.prepare( "SELECT numberrope FROM kirova WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::ANCHOR){
        qry.prepare( "SELECT numberrope FROM anchor WHERE id='"+id1+"';" );
    }

    if( !qry.exec() )
        qDebug() << qry.lastError().text();
    else{
        if(id_==ThreadType::PNK||id_==ThreadType::GAMMA){
            while(qry.next()){
//                qDebug() << QString( "%1" ).arg( qry.value(0).toString().rightJustified(4,'0'));
                number=qry.value(0).toString().rightJustified(4,'0');
            }
        }
        else{
            while(qry.next()){
//                qDebug() << QString( "%1" ).arg( qry.value(0).toString() );
                number=qry.value(0).toString();
            }
        }
    }
    return number;
}

int AddDataBase::getAmount(int id)
{
    QSqlQuery qry;
    int amount_=0;
    QString id1=QString::number(id);
    if(id_==ThreadType::DMC){
        qry.prepare( "SELECT amount FROM dmc WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::GAMMA){
        qry.prepare( "SELECT amount FROM gamma WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::PNK){
        qry.prepare( "SELECT amount FROM kirova WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::ANCHOR){
        qry.prepare( "SELECT amount FROM anchor WHERE id='"+id1+"';" );
    }

    if( !qry.exec() ){
        qDebug() << qry.lastError().text();
    }
    else{
        while(qry.next()){
//            qDebug() << QString( "%1" ).arg( qry.value(0).toString() );
            amount_=qry.value(0).toInt();
        }
    }
    return amount_;
}

bool AddDataBase::getIsCheked(int id)
{
    QSqlQuery qry;
    bool isCheked=0;
    QString id1=QString::number(id);

    if(id_==ThreadType::DMC){
        qry.prepare( "SELECT isvalue FROM dmc WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::GAMMA){
        qry.prepare( "SELECT isvalue FROM gamma WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::PNK){
        qry.prepare( "SELECT isvalue FROM kirova WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::ANCHOR){
        qry.prepare( "SELECT isvalue FROM anchor WHERE id='"+id1+"';" );
    }

    if( !qry.exec() ){
        qDebug() << qry.lastError().text();
    }
    else{
        while(qry.next()){
            int val = qry.value(0).toInt();
            if(val==0)
                isCheked=false;
            else
                isCheked=true;
        }
    }
    return isCheked;
}

int AddDataBase::getR(int id)
{
    QSqlQuery qry;
    int r_=0;
    QString id1=QString::number(id);
    if(id_==ThreadType::DMC){
        qry.prepare( "SELECT r FROM dmc WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::GAMMA){
        qry.prepare( "SELECT r FROM gamma WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::PNK){
        qry.prepare( "SELECT r FROM kirova WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::ANCHOR){
        qry.prepare( "SELECT r FROM anchor WHERE id='"+id1+"';" );
    }

    if( !qry.exec() ){
        qDebug() << qry.lastError().text();
    }
    else{
        while(qry.next()){
            //            qDebug() << QString( "%1" ).arg( qry.value(0).toString() );
            r_=qry.value(0).toInt();
        }
    }
    return r_;
}

int AddDataBase::getG(int id)
{
    QSqlQuery qry;
    int g_=0;
    QString id1=QString::number(id);
    if(id_==ThreadType::DMC){
        qry.prepare( "SELECT g FROM dmc WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::GAMMA){
        qry.prepare( "SELECT g FROM gamma WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::PNK){
        qry.prepare( "SELECT g FROM kirova WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::ANCHOR){
        qry.prepare( "SELECT g FROM anchor WHERE id='"+id1+"';" );
    }

    if( !qry.exec() ){
        qDebug() << qry.lastError().text();
    }
    else{
        while(qry.next()){
            //            qDebug() << QString( "%1" ).arg( qry.value(0).toString() );
            g_=qry.value(0).toInt();
        }
    }
    return g_;
}

int AddDataBase::getB(int id)
{
    QSqlQuery qry;
    int b_=0;
    QString id1=QString::number(id);
    if(id_==ThreadType::DMC){
        qry.prepare( "SELECT b FROM dmc WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::GAMMA){
        qry.prepare( "SELECT b FROM gamma WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::PNK){
        qry.prepare( "SELECT b FROM kirova WHERE id='"+id1+"';" );
    }
    else if(id_==ThreadType::ANCHOR){
        qry.prepare( "SELECT b FROM anchor WHERE id='"+id1+"';" );
    }

    if( !qry.exec() ){
        qDebug() << qry.lastError().text();
    }
    else{
        while(qry.next()){
            //            qDebug() << QString( "%1" ).arg( qry.value(0).toString() );
            b_=qry.value(0).toInt();
        }
    }
    return b_;
}

void AddDataBase::setId(int id)
{
    id_=id;
}

bool AddDataBase::setUpdate(int id, QString numberrope, int amount, bool isvalue)
{
    QSqlQuery qry;
    QString id1=QString::number(id);

    if(id_==ThreadType::DMC){
        qry.prepare( "UPDATE dmc SET numberrope=:numberrope, amount=:amount, isvalue=:isvalue, id_type=:id_type WHERE id=:id;" );
    }
    else if(id_==ThreadType::GAMMA){
        qry.prepare( "UPDATE gamma SET numberrope=:numberrope, amount=:amount, isvalue=:isvalue, id_type=:id_type WHERE id=:id;" );
    }
    else if(id_==ThreadType::PNK){
        qry.prepare( "UPDATE kirova SET numberrope=:numberrope, amount=:amount, isvalue=:isvalue, id_type=:id_type WHERE id=:id;" );
    }
    else if(id_==ThreadType::ANCHOR){
        qry.prepare( "UPDATE anchor SET numberrope=:numberrope, amount=:amount, isvalue=:isvalue, id_type=:id_type WHERE id=:id;" );
    }

    qry.bindValue(":id", id);
    qry.bindValue(":numberrope", numberrope);//VARCHAR(20)
    qry.bindValue(":amount", amount);//VARCHAR(30)
    qry.bindValue(":isvalue", isvalue);
    qry.bindValue(":id_type", id_);

    return qry.exec();
}
