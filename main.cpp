#include "loginpage.h"
#include "Filemanager.h"
#include "TeacherWeeklyCalendar.h"
#include "CalendarCreator.h"
#include "Poll.h"
#include "Auth.h"

#include <QApplication>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    // creates users.txt file for storing users data
    FileManager userFile;

    userFile.create("users.txt");

    userFile.loadData();

    userFile.append(Auth::formUserData(
        "1273882407", "@mir1990",
        "Amirhossein", "Mazaheri",
        "1273882407", "09921863951",
        "Admin"
   ));


    userFile.append(Auth::formUserData(
        "1287237408", "@mir1990",
        "Mamad", "Mamadi",
        "1273882407", "09921863951",
        "Teacher"
    ));


    userFile.append(Auth::formUserData(
        "1287237408", "@mir1990",
        "Asghar", "Mamadi",
        "1273882407", "09921863951",
        "Student"
        ));

    userFile.write();

    TeacherWeeklycalendar cal;

    CalendarCreator class01;

    class01.setUsername("1253982608");

    class01.append("Descrete Math", "Monday", "9:00");
    class01.append("Calculos", "Thursday", "8:00");
    class01.append("General", "Wensday", "11:00");

//    qDebug() << QString::fromStdString(class01.exportJson()["username"].asString());

//    for(int i = 0; i < class01.exportJson()["classes"].size(); i++)
//    {
//        qDebug() << QString::fromStdString(class01.exportJson()["classes"][i]["name"].asString());
//    }


    cal.addUser(class01.exportJson());

//    Json::Value newClass = cal.formClassData("Gosasteh123456", "Saturday", "11:00");

//    cal.appendClass(newClass, "128824073", "teachers");

//    cal.deleteClass("Fundamental Programing", "128824073", "teachers");


    Poll p;

//    p.addScore(4, "3546484", "calculus", "mahdavi");


    QApplication a(argc, argv);
    LoginPage w;
    w.show();
    return a.exec();
}
