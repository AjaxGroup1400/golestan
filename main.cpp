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

    TeacherWeeklycalendar cal;

//    CalendarCreator class01;

//    class01.setUsername("1253982608");

//    class01.append("Descrete Math", "Monday", "9:00");
//    class01.append("Calculos", "Thursday", "8:00");
//    class01.append("General", "Wensday", "11:00");

//    cal.addUser(class01.exportJson());

    qDebug() << QString::fromStdString(md5("grape"));



//    cal.loadCalendar("1253982608");

//    auto sep = cal.getCalendarDayByDay();

//    qDebug() << cal.getCalendar();

//    for(auto& days: sep)
//    {
//        for(auto& day: days)
//        {
//            std::cout << day["day"].toStdString() << "\t" << day["name"].toStdString() << "\t" << day["time"].toStdString() << std::endl;
//        }

//        std::cout << "//////////\\\\\\\\\\" << std::endl;
//    }



    QApplication a(argc, argv);
    LoginPage w;
    w.show();
    return a.exec();
}
