#include "TeacherWeeklyCalendar.h"

#include <fstream>

using namespace std;

TeacherWeeklycalendar::TeacherWeeklycalendar()
{
    return;
}

void TeacherWeeklycalendar::loadCalendar(QString username)
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value teacherClasses = dataHolder["teachers"];

        for(int i = 0; i < teacherClasses.size(); i++)
        {
            if(teacherClasses[i]["username"] == username.toStdString())
            {
                Json::Value wantedTeacherClasses = teacherClasses[i]["classes"];

                for(int j = 0; j < wantedTeacherClasses.size(); j++)
                {
                    QMap<QString, QString> classData;

                    classData.insert("name", QString::fromStdString(wantedTeacherClasses[j]["name"].asString()));
                    classData.insert("day", QString::fromStdString(wantedTeacherClasses[j]["day"].asString()));
                    classData.insert("time", QString::fromStdString(wantedTeacherClasses[j]["time"].asString()));

                    calendar.push_back(classData);
                }
            }
        }
    }
}
