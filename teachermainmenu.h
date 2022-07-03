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

namespace Ui {
class TeacherMainMenu  ;
}

class TeacherMainMenu : public User
{
    Q_OBJECT

public:
    explicit TeacherMainMenu(QWidget *parent = nullptr);
    ~TeacherMainMenu();

//    QMap<QString, float> studentsList(QString classname);
    void deleteStudent(QString studentusername , Class Class);
    void setScores(Class Class);


    void sendingNotification(QString title , QString message , QString lesson , QList<QString> list);

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::TeacherMainMenu *ui;

    QList <Class> classes;
//    QMultiMap < QString ,QMap<QString, float> > students;
//    QMap<QString , int> SurveyResult;

};

#endif // TEACHERMAINMENU_H
