#include "loginpage.h"
#include "Filemanager.h"
#include "TeacherWeeklyCalendar.h"
#include "CalendarCreator.h"
#include "studentmainmenu.h"
#include "Poll.h"
#include "Auth.h"
#include "Md5Hash.h"
#include"teachermainmenu.h"

#include <QApplication>
#include <iostream>
#include <fstream>
#include <functional>

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
                        "1287237406","@mir1990",
                        "Mamad","Mamadi",
                        "1273882407" ,"09921863951",
                        "Teacher"
                    ));

    userFile.append(Auth::formUserData(
        "1287237409", "@mir1990",
        "Asghar", "Mamadi",
        "1273882407", "09921863951",
        "Student"
    ));



    userFile.write();

    QApplication a(argc, argv);
    LoginPage w;
    w.show();
    return a.exec();
}
