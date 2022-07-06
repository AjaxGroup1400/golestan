#ifndef TEACHERMAINMENU_H
#define TEACHERMAINMENU_H

#include <QDialog>
#include <QList>
#include <QMultiMap>
#include <QString>
#include <QObject>
#include <QWidget>

#include "User.h"
#include "Class.h"
#include"dist/json/json.h"

namespace Ui {
class TeacherMainMenu  ;
}

class TeacherMainMenu : public User
{
    Q_OBJECT

public:
    explicit TeacherMainMenu(QWidget *parent = nullptr);
    TeacherMainMenu(QString firstname , QString username);
    ~TeacherMainMenu();

//    QMap<QString, float> studentsList(QString classname);
    void deleteStudent(QString studentusername , Class Class);
    void setScores(Class Class);

    void sendingNotification(QString title , QString message , Class Class);

    void addNewTeacherToFile(QList<QString> lessons);
    void addNewLessonFile(Class new_class);
    void removeLessonFile(Class lesson);
    int teacherIsValidFile();
    bool lessonIsValid(QString lesson);
    Class getLesson(lesson lesson);
    QString lessonNameCheck(QString sentName);



private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TeacherMainMenu *ui;

    QList <Class> classes;

//    QList<QString> lessons;
    void initFile();
    Json::Reader dataReader;
    Json::Value dataHolder;
    QString filePath = "../data_resources/teacher_lessons.json";

//    QMultiMap < QString ,QMap<QString, float> > students;
//    QMap<QString , int> SurveyResult;

};

#endif // TEACHERMAINMENU_H
