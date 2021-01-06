#include "Blocc.h"
#include<QMessageBox>





Blocc::Blocc()
{
    id_bloc="";
        nom_bloc="";
        equipement="";
        type_equipement="";
        numero_four="";
        date="";
        situation="";
}

Blocc::Blocc(QString id_bloc,QString nom_bloc,QString equipement,QString type_equipement,QString numero_four,QString date,QString situation)
{
    this->id_bloc=id_bloc;
        this->nom_bloc=nom_bloc;
        this->equipement=equipement;
        this->type_equipement=type_equipement;
        this->numero_four=numero_four;
        this->date=date;
        this->situation=situation;
}

bool Blocc::ajouterbloc()
{

    QSqlQuery qry ;
        qry.prepare("insert into BLOC (ID,NOM_BLOC,EQUIPEMENT,TYPE_EQUIPEMENT,NUMERO,DATE_A,SITUATION) values ('"+id_bloc+"','"+nom_bloc+"','"+equipement+"','"+type_equipement+"','"+numero_four+"','"+date+"','"+situation+"')") ;
    qry.bindValue(":ID",id_bloc);
    qry.bindValue(":NOM_BLOC",nom_bloc);
    qry.bindValue(":EQUIPEMENT",equipement);
    qry.bindValue(":TYPE_EQUIPEMENT",type_equipement);
    qry.bindValue(":NUMERO",numero_four);
    qry.bindValue(":DATE_A",date);
    qry.bindValue(":SITUATION",situation);

    return qry.exec();

}

QSqlQueryModel * Blocc::afficherbloc()
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    modal->setQuery("select * from BLOC");
        modal->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        modal->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_BLOC"));
        modal->setHeaderData(2, Qt::Horizontal, QObject::tr("EQUIPMENT"));
        modal->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_EQUIPEMENT"));
        modal->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMERO_FOUR"));
        modal->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_A"));
        modal->setHeaderData(6, Qt::Horizontal, QObject::tr("SITUATION"));
        return modal;

}

bool Blocc::modifierbloc()
{

    QSqlQuery query ;
//////////
       query.prepare("update BLOC set ID='"+id_bloc+"',NOM_BLOC='"+nom_bloc+"',EQUIPEMENT='"+equipement+"',TYPE_EQUIPEMENT='"+type_equipement+"',NUMERO='"+numero_four+"',DATE_A='"+date+"',SITUATION='"+situation+"' where ID='"+id_bloc+"' ");
       query.bindValue(":ID",id_bloc);
       query.bindValue(":NOM_BLOC",nom_bloc);
       query.bindValue(":EQUIPEMENT", equipement);
       query.bindValue(":TYPE_EQUIPEMENT",type_equipement);
       query.bindValue(":NUMERO_FOUR",numero_four);
       query.bindValue(":DATE_A",date);
       query.bindValue(":SITUATION",situation);

       return query.exec();
}

bool Blocc::supprimer(Ui::Dialog *ui)
{
    QString id;
        id=ui->lineEdit_id->text();
      QSqlQuery query ;
      query.prepare("DELETE FROM BLOC WHERE ID='"+id+"'");
      if(query.exec())
      {
                  return query.exec();
      }
      else return false;

}

void Blocc::recherche(Ui::Dialog *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    QString mot =ui->lineEdit_rechercher->text();
    q.prepare("select * from BLOC where (ID LIKE '%"+mot+"%' or NOM_BLOC LIKE '%"+mot+"%' or TYPE_EQUIPEMENT LIKE '%"+mot+"%' )");

    q.exec() ;
    modal->setQuery(q);
    ui->tableView->setModel(modal);
}

void Blocc::TRI1(Ui::Dialog *ui)
{
    QSqlQuery q;
       QSqlQueryModel *model=new QSqlQueryModel();
       q.prepare("select * from BLOC order by NOM_BLOC");
       q.exec();
       model->setQuery(q);
       ui->tableView->setModel(model);
}

void Blocc::TRI2(Ui::Dialog *ui)
{
    QSqlQuery q;
       QSqlQueryModel *model=new QSqlQueryModel();
       q.prepare("select * from BLOC order by ID");
       q.exec();
       model->setQuery(q);
       ui->tableView->setModel(model);
}

bool Blocc::verif_id(QString ch_id){
    bool test=true;
       int i;
       if(ch_id.length()!=6){
          test=false;
          return  test;
       }else{
           for(i=0;i<ch_id.length();i++){
               if(!((ch_id[i]>='0')&&(ch_id[i]<='9'))){
                   test=false;
                   return  test;
           }
           }
       }
    return test;}


bool Blocc::verif_nom(QString ch_nom){
    bool test=true;
    int i;
    if(true)
    {
        for(i=0;i<ch_nom.length();i++){
            if(!(((ch_nom[i]>='A')&&(equipement[i]<='Z'))||((equipement[i]>='a')&&(equipement[i]<='z')))){
                test=false;
                return  test;
        }
    }
  }
    return  test;
}


bool Blocc::verif_date(QString date_d)
{

    bool test=true;
    int i;
    if(date_d.length()!=10){
       test=false;
       return  test;
    }

         else{
       for(i=0;i<date_d.length();i++){
            if(!((date_d[1]>='0')&&(date_d[1]<='9'))&&(!((date_d[2]>='0')&&(date_d[2]<='9'))) && (!((date_d[4]>='0')&&(date_d[4]<='9'))) && (!((date_d[5]>='0')&&(date_d[5]<='9'))) && (!((date_d[7]>='0')&&(date_d[7]<='9'))) && (!((date_d[8]>='0')&&(date_d[8]<='9'))) && (!((date_d[9]>='0')&&(date_d[9]<='9'))) && (!((date_d[10]>='0')&&(date_d[10]<='9')))){
                test=false;
               return  test;
        }
        }
   }

 return test;}

//
bool Blocc::verif_numero(QString numero)
{

    bool test=true;
    int i;
    if(numero.length()!=8){
       test=false;
       return  test;
    }else{
        for(i=0;i<numero.length();i++){
            if(!((numero[i]>='0')&&(numero[i]<='9'))){
                test=false;
                return  test;
        }
        }
    }
 return test;}







