#ifndef TEACHERMESSAGES_H
#define TEACHERMESSAGES_H

#include <QWidget>

#include"teachermainmenu.h"

namespace Ui {
class teacherMessages;
}

class teacherMessages : public QWidget
{
    Q_OBJECT

public:
    explicit teacherMessages(TeacherMainMenu * member , QWidget *parent = nullptr);
    ~teacherMessages();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_backToMenu_clicked();

    void on_msgbtn1_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::teacherMessages *ui;

    TeacherMainMenu * mainmenu;
};

#endif // TEACHERMESSAGES_H
