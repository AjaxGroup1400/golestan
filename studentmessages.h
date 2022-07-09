#ifndef STUDENTMESSAGES_H
#define STUDENTMESSAGES_H

#include <QWidget>
#include <QGroupBox>
#include <memory>

#include"studentmainmenu.h"
#include "Notification.h"

namespace Ui {
class studentMessages;
}

using std::unique_ptr, std::make_unique;

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

    unique_ptr<Notification> notification;

    void showMeassages();

    QGroupBox *createMessageBox(QString messageTitle, QString messageDescription, int id);



};

#endif // STUDENTMESSAGES_H
