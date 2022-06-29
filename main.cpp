#include "loginpage.h"
#include "Filemanager.h"
#include "TeacherWeeklyCalendar.h"
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

    cal.show("139924082");

    qDebug() << cal.getCalendar()[0]["name"];

    QApplication a(argc, argv);
    LoginPage w;
    w.show();
    return a.exec();
}
