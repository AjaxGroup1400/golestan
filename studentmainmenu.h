#ifndef STUDENTMAINMENU_H
#define STUDENTMAINMENU_H

#include <QWidget>
#include <QMap>
#include <QString>
#include <QList>
#include "Class.h"
#include "User.h"


namespace Ui {
class StudentMainMenu;
}

class StudentMainMenu : public User
{
    Q_OBJECT

public:
    explicit StudentMainMenu(QWidget *parent = nullptr); //write student file that contains username and class and maybe scores
    ~StudentMainMenu();

    void scores(); //file can be updated
    void registry(Class Class); //add class to student's file
    void surveyOfTeachers(Class Class , int result);


private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::StudentMainMenu *ui;

    QList <Class> classes;
//    QMap<QString , QString> teachers;
};

#endif // STUDENTMAINMENU_H

/* watching scores
 * registery
 * arzeshyabi ostad

 * weekly calender
 */


/*proficiency of teacher
 *responsiveness of the teacher
 *management of the class
 *creativity
 *dicipline
*/
