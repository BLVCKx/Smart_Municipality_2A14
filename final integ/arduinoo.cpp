#include "arduinoo.h"
#include "ui_arduinoo.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>
#include <string>
#include <QMessageBox>

arduinoo::arduinoo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arduinoo)
{
    counter = 0;
ui->setupUi(this);
arduino_is_available = false;
arduino_port_name = "";
arduino = new QSerialPort;

foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
       if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
           if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
               if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                   arduino_port_name = serialPortInfo.portName();
                   arduino_is_available = true;
               }
           }
       }
   }

   if(arduino_is_available){
       // open and configure the serialport
       arduino->setPortName(arduino_port_name);

       arduino->setBaudRate(QSerialPort::Baud9600);
       arduino->setDataBits(QSerialPort::Data8);

       arduino->setParity(QSerialPort::NoParity);
       arduino->setStopBits(QSerialPort::OneStop);
       arduino->setFlowControl(QSerialPort::NoFlowControl);
       arduino->open(QSerialPort::ReadWrite);

         QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
   }else{
       // give error message if not available
       QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
   }
}



arduinoo::~arduinoo()
{
if(arduino->isOpen()){
        arduino->close();
    }
    delete ui;

}

void arduinoo::readSerial(){


QStringList buffer_split = serialBuffer.split("\r\n");
        // no parsed value yet so continue accumulating bytes from serial in the buffer.
        serialData = arduino->readAll();
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
        serialData.clear();
                qDebug() <<buffer_split;

}
void arduinoo::updateRamp(QString command)
{
if(arduino->isWritable()){
    arduino->write(command.toStdString().c_str());
}else{
    qDebug() << "Couldn't write to serial!";
}}


void arduinoo::on_pushButton_clicked()
{
arduinoo::updateRamp(QString("o"));
}

void arduinoo::on_pushButton_2_clicked()
{
arduinoo::updateRamp(QString("c"));
}


void arduinoo::on_pushButton_5_clicked()
{
arduinoo::updateRamp(QString("+"));
}

void arduinoo::on_pushButton_4_clicked()
{
arduinoo::updateRamp(QString("-"));
}

void arduinoo::on_pushButton_3_clicked()
{


counter++;
QString s = QString::number(counter);
ui -> lineEdit_6->setText(s);
arduinoo::updateRamp(QString("l"));
arduinoo::updateRamp(QString("+"));

}



void arduinoo::on_pushButton_6_clicked()
{
counter = 0;
QString s = QString::number(counter);
ui -> lineEdit_6->setText(s);
}
