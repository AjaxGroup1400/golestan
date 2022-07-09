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

    void on_pushButton_5_clicked();


    void on_comboBox_4_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::adminAddClass *ui;
    AdminMainMenu * mainmenu;
    int lesson = 0;
    QString teacherusername;
    QString location;
    QString time;
    int day=0;
};

#endif // ADMINADDCLASS_H
