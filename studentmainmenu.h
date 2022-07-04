#ifndef STUDENTMAINMENU_H
#define STUDENTMAINMENU_H

#include "dist/json/json.h"
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
    explicit StudentMainMenu(QWidget *parent = nullptr);
    //if student exists read it from file else write new student : Term = 1
    ~StudentMainMenu();

//    bool is_equal(Class lesson);

    void scores(); //file can be updated
    void registry(Class Class); //add class to student's file and term++
    void surveyOfTeachers(Class Class , int result);
    void deleteLesson(Class lesson);


private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::StudentMainMenu *ui;
    int Term;

//    QList < QMap <Class, float> > terms;

    QList <float> avereges;
    int currentAverege = avereges[Term-1];

//    QMap < QList <Class> , float> terms; //Averege: float

    QMap <Class,float> this_term_classes; //Score: float

    QList <Class> classes;
    QString filePath;
    Json::Value dataHolder;
    Json::Reader dataReader;

    // checks for existance of student related file or create it (should be called in cosntructor)
    void initFile();
};

//List[0]:{
//    bp:19
//    discrete: 18.5
//    ...
//}


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
