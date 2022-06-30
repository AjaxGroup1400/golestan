#ifndef STUDENTMAINMENU_H
#define STUDENTMAINMENU_H

#include <QWidget>
#include<QMap>
#include<QString>>

#include"User.h"


namespace Ui {
class StudentMainMenu;
}

class StudentMainMenu : public User
{
    Q_OBJECT

public:
    explicit StudentMainMenu(QWidget *parent = nullptr);
    ~StudentMainMenu();

    void surveyOfTeachers(QString lesson , int result);


private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::StudentMainMenu *ui;

    QMap<QString , QString> teachers;
};

#endif // STUDENTMAINMENU_H

/*watching scores
 * registery
 * arzeshyabi ostad
 * weekly calender
 *
 *
 */


/*
 *domination of teacher
 *responsiveness of the teacher
 *management of the class
 *creativity
 *dicipline
*/
