#ifndef ADMINADDCLASS_H
#define ADMINADDCLASS_H

#include <QWidget>

#include"adminmainmenu.h"

namespace Ui {
class adminAddClass;
}

class adminAddClass : public QWidget
{
    Q_OBJECT

public:
    explicit adminAddClass(AdminMainMenu * member , QWidget *parent = nullptr);
    ~adminAddClass();

private slots:
    void on_backToMenu_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::adminAddClass *ui;
    AdminMainMenu * mainmenu;
};

#endif // ADMINADDCLASS_H
