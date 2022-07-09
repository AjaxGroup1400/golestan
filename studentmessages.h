#ifndef STUDENTMESSAGES_H
#define STUDENTMESSAGES_H

#include <QWidget>
#include <QGroupBox>

#include"studentmainmenu.h"

namespace Ui {
class studentMessages;
}

class studentMessages : public QWidget
{
    Q_OBJECT

public:
    explicit studentMessages(StudentMainMenu * memeber , QWidget *parent = nullptr);
    ~studentMessages();

private:
    QGroupBox* showMessages(int i);

private slots:
    void on_pushButton_clicked();

    void on_backToMenu_clicked();

    //void on_msgbtn1_clicked();

    void on_pushButton_3_clicked();

    void on_msgBtn_clicked(QString title);
    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::studentMessages *ui;

    StudentMainMenu * mainmenu ;
};

#endif // STUDENTMESSAGES_H
