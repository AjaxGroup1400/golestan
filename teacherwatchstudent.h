#ifndef TEACHERWATCHSTUDENT_H
#define TEACHERWATCHSTUDENT_H

#include <QWidget>
#include <QGroupBox>

#include"teachermainmenu.h"

namespace Ui {
class TeacherWatchStudent;
}

class TeacherWatchStudent : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherWatchStudent(TeacherMainMenu * member , QWidget *parent = nullptr);
    ~TeacherWatchStudent();

private slots:
    void on_backToMenu_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::TeacherWatchStudent *ui;

    QGroupBox* students();

    TeacherMainMenu * mainmenu ;
};

#endif // TEACHERWATCHSTUDENT_H
