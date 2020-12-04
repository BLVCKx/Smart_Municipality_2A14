#include "equipement.h"
#include<QPrinter>

Equipement::Equipement()
{
    id="";
    nom="";
    nombre="";
    adresse="";
    prix="";
    marque="";

}

Equipement::Equipement(QString id,QString nom, QString nombre , QString adresse , QString prix , QString marque )
{
    this->id=id ;
    this->nom=nom ;
    this->nombre=nombre ;
    this->adresse=adresse;
    this->prix=prix;
    this->marque=marque ;
}

bool Equipement::ajouterequipement()
{
    QSqlQuery qry ;
qry.prepare("insert into EQUIPEMENT (ID_E,NOM,NOMBRE,ADRESSE,PRIX,MARQUE) values ('"+id+"','"+nom+"','"+nombre+"','"+adresse+"','"+prix+"','"+marque+"')") ;
   qry.bindValue(":ID_E",id);
   qry.bindValue(":NOM",nom);
   qry.bindValue(":NOMBRE",nombre);
   qry.bindValue(":ADRESSE",adresse);
   qry.bindValue(":PRIX",prix);
   qry.bindValue(":MARQUE",marque);

       return qry.exec();

}

void Equipement::afficherequipement(Ui::Dialog *ui)
{

        QSqlQuery q;
        QSqlQueryModel *modal=new QSqlQueryModel();
        q.prepare("select * from EQUIPEMENT");
        q.exec();
        modal->setQuery(q);
        ui->tableView_2->setModel(modal);

}

void Equipement::selectionnerequipement(Ui::Dialog *ui, const QModelIndex &index)
{ QSqlQuery qry;
    QString val;
   val=ui->tableView_2->model()->data(index).toString();

   qry.prepare("SELECT * FROM EQUIPEMENT  where ID_E='"+val+"' or NOM='"+val+"' or NOMBRE='"+val+"' or ADRESSE='"+val+"' or PRIX='"+val+"'or MARQUE='"+val+"' ");
       if(qry.exec())
       {
           while (qry.next())

           {

               ui->lineEdit_id_equipement->setText(qry.value(0).toString());
                ui->lineEdit_nom_equipement->setText(qry.value(1).toString());
                ui->lineEdit_nombre_equipement->setText(qry.value(2).toString());
                ui->lineEdit_adresse_equipement->setText(qry.value(3).toString());
                ui->lineEdit_prix_equipement->setText(qry.value(4).toString());
                ui->lineEdit_marque_equipement->setText(qry.value(5).toString());
           }

       }


}
bool Equipement::modifierequipement()
{
    QSqlQuery qry ;

       qry.prepare("update EQUIPEMENT set ID_E='"+id+"',NOM='"+nom+"',NOMBRE='"+nombre+"',ADRESSE='"+adresse+"',PRIX='"+prix+"',MARQUE='"+marque+"' where ID_E='"+id+"' ");
       qry.bindValue(":ID_E",id);
       qry.bindValue(":NOM",nom);
       qry.bindValue(":NOMBRE",nombre);
       qry.bindValue(":ADRESSE",adresse);
       qry.bindValue(":PRIX",prix);
       qry.bindValue(":MARQUE",marque);

          return qry.exec();
}

bool Equipement::supprimerequipement(Ui::Dialog *ui)
{
    QString id;
    id=ui->lineEdit_id_equipement->text();
  QSqlQuery query ;
  query.prepare("DELETE FROM EQUIPEMENT WHERE ID_E='"+id+"'");
  if(query.exec())
  {
              return query.exec();
  }
  else return false;


}

void Equipement::creationpdf()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM RESERVATION ");
        q.exec();
        QString pdf="<br> <h1  style='color:red'>LISTE DES EQUIPEMENT  <br></h1>\n <br> <table>  <tr>  <th> ID  </th> <th> NOM GP MUSIC </th> <th> NOM GP SERVEUR </th> <th> NOM GP DECO </th> <th> NOM GP PATISERIE </th> <th> NOM GP PHOTOGRAPHIE </th></tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(4).toString()+" " "ans "  " " "</td>   <td>"+q.value(5).toString()+" </td> <td>"+q.value(5).toString()+" </td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}
bool Equipement::verif_id(QString ch_id){
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
