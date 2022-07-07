#ifndef STUDENTMESSAGES_H
#define STUDENTMESSAGES_H

#include <QWidget>

#include"studentmainmenu.h"

namespace Ui {
class studentMessages;
}

class studentMessages : public QWidget
{
    Q_OBJECT

public:
    explicit studentMessages(StudentMainMenu * member , QWidget *parent = nullptr);
    ~studentMessages();

private slots:
    void on_pushButton_clicked();

    void on_backToMenu_clicked();

    void on_msgbtn1_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::studentMessages *ui;

    StudentMainMenu * mainmenu;

    QList<QString>    unreadMessages;
    QList<QString>    unreadTitle;
    QList<QString>    unReadsender;
    QList<QString>    readMessages;
    QList<QString>    readTitle;
    QList<QString>    Readsender;

    Json::Value dataHolder;
    Json::Reader dataReader;
    QString filePath = "../data_resources/studentnotification" ;
};

#endif // STUDENTMESSAGES_H
