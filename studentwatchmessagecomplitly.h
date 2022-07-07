#ifndef STUDENTWATCHMESSAGECOMPLITLY_H
#define STUDENTWATCHMESSAGECOMPLITLY_H
#include <QWidget>
#include<QString>


#include"dist/json/json.h"
#include"studentmainmenu.h"



namespace Ui {
class StudentWatchMessageComplitly;
}

class StudentWatchMessageComplitly : public QWidget
{
    Q_OBJECT

public:
    explicit StudentWatchMessageComplitly(QString title , QString message , QString sender , bool isread , StudentMainMenu * member , QWidget *parent = nullptr);
    ~StudentWatchMessageComplitly();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::StudentWatchMessageComplitly *ui;

    StudentMainMenu * mainmenu;

    Json::Value dataHolder;
    Json::Reader dataReader;
    QString filePath = "../data_resources/studentnotification" ;



};

#endif // STUDENTWATCHMESSAGECOMPLITLY_H
