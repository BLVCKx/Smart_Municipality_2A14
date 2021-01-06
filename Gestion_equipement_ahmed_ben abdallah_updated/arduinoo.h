#ifndef ARDUINOO_H
#define ARDUINOO_H

#include <QDialog>
#include <QSerialPort>
#include <QByteArray>

namespace Ui {
class arduinoo;
}

class arduinoo : public QDialog
{
    Q_OBJECT

public:
    explicit arduinoo(QWidget *parent = nullptr);
    ~arduinoo();
private slots:
    void updateRamp(QString);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

        void readSerial();
        void on_plainTextEdit_copyAvailable(bool b);

        void on_plainTextEdit_blockCountChanged(int newBlockCount);

        void on_pushButton_5_clicked();

        void on_pushButton_4_clicked();

        void on_pushButton_3_clicked();

        void on_lineEdit_6_cursorPositionChanged(int arg1, int arg2);

        void on_lineEdit_cursorPositionChanged(int arg1, int arg2);




        void on_pushButton_6_clicked();

private:
    Ui::arduinoo *ui;
    QSerialPort *arduino;
        static const quint16 arduino_uno_vendor_id = 9025;
        static const quint16 arduino_uno_product_id = 67;
        QByteArray serialData;
            QString serialBuffer;
            QString parsed_data;
            int car_count;
        QString arduino_port_name;
        bool arduino_is_available;
 int counter;
};

#endif // ARDUINOO_H
