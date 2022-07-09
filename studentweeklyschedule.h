#ifndef STUDENTWEEKLYSCHEDULE_H
#define STUDENTWEEKLYSCHEDULE_H

#include <QWidget>

#include"studentmainmenu.h"

namespace Ui {
class studentWeeklySchedule;
}

class studentWeeklySchedule : public QWidget
{
    Q_OBJECT

public:
    explicit studentWeeklySchedule(StudentMainMenu * member , QWidget *parent = nullptr);
    ~studentWeeklySchedule();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::studentWeeklySchedule *ui;
    StudentMainMenu * mainmenu ;
};

#endif // STUDENTWEEKLYSCHEDULE_H
