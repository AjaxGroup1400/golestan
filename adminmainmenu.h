#ifndef ADMINMAINMENU_H
#define ADMINMAINMENU_H

#include <QWidget>

#include"User.h"

namespace Ui {
class AdminMainMenu;
}

class AdminMainMenu : public User
{
    Q_OBJECT

public:
    explicit AdminMainMenu(QWidget *parent = nullptr);
    ~AdminMainMenu();



private slots:
    void on_pushButton_5_clicked();


    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AdminMainMenu *ui;


};

#endif // ADMINMAINMENU_H
//having a def to change the button accessibility to the arzeshyabi part
