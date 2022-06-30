#include "TeacherWeeklyCalendar.h"

#include <fstream>

using namespace std;

TeacherWeeklycalendar::TeacherWeeklycalendar()
    : WeeklyCalendar()
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

                // clear(empty) calendar before filling it with new data
                calendar.clear();

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

void TeacherWeeklycalendar::addUser(Json::Value data)
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value dataHolderCopy = dataHolder["teachers"];

        dataHolderCopy.append(data);

        dataHolder["teachers"] = dataHolderCopy;

        Json::StyledWriter writer;

        ofstream jsonWriter(filePath.toStdString());

        string serializedData = writer.write(dataHolder);

        jsonWriter << serializedData;

        jsonWriter.close();
    }
}



