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
    explicit StudentMainMenu(QString firstname , StudentMainMenu * member = nullptr , QWidget *parent = nullptr);
    //if student exists read it from file else write new student : Term = 1
    ~StudentMainMenu();

    QList<float> getAverages();

    void getScores(int term); //file can be updated

    // adds class at the end of term classes in file
    void registry(Class Class);

    // adds term into the list of target student in file
    void addTerm();

    // it should be called when student remove a Class or his/her teacher does
    void unregistery(Class Class);

//    bool is_equal(Class lesson);

    void surveyOfTeachers(Class Class , int result);
//    void deleteLesson(Class lesson);

    void load();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::StudentMainMenu *ui;

    QString filePath = "../data_resources/student_term.json";
    Json::Value dataHolder;
    Json::Reader dataReader;
    StudentMainMenu * mainmenu;

    int Term;
    int currentAverege;

    QList <float> avereges;

//    QMap < QList <Class> , float> terms; //Averege: float

    // whenever the user wants to see the details of term this method will be called
    QList <Class> currentClasses;

};


#endif // STUDENTMAINMENU_H
