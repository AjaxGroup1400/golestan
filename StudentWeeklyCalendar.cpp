#include "StudentWeeklyCalendar.h"

#include <fstream>


using namespace std;

StudentWeeklyCalendar::StudentWeeklyCalendar()
    : WeeklyCalendar()
{
    return;
}

void StudentWeeklyCalendar::loadCalendar(QString username)
{
    ifstream ifs(filePath.toStdString());

    // clear(empty) calendar before filling it with new data
    calendar.clear();

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value teacherClasses = dataHolder["students"];

        for(int i = 0; i < teacherClasses.size(); i++)
        {
            if(teacherClasses[i]["username"].asString() == username.toStdString())
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

void StudentWeeklyCalendar::addUser(Json::Value data)
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value dataHolderCopy = dataHolder["students"];

        dataHolderCopy.append(data);

        dataHolder["students"] = dataHolderCopy;

        Json::StyledWriter writer;

        ofstream jsonWriter(filePath.toStdString());

        string serializedData = writer.write(dataHolder);

        jsonWriter << serializedData;

        jsonWriter.close();
    }
}

void StudentWeeklyCalendar::getCalendarDayByDay()
{
    QList<QList<QMap<QString, QString>>> seperatedDays;

    QList<QMap<QString, QString>> Saturday;
    QList<QMap<QString, QString>> Sunday;
    QList<QMap<QString, QString>> Monday;
    QList<QMap<QString, QString>> Tuesday;
    QList<QMap<QString, QString>> Wednsday;
    QList<QMap<QString, QString>> Thursday;
    QList<QMap<QString, QString>> Friday;

    for(auto calendarItem : calendar)
    {
        if(calendarItem["day"] == "Saturday")
            Saturday.push_back(calendarItem);
        else if(calendarItem["day"] == "Sunday")
            Sunday.push_back(calendarItem);
        else if(calendarItem["day"] == "Monday")
            Monday.push_back(calendarItem);
        else if(calendarItem["day"] == "Tuesday")
            Tuesday.push_back(calendarItem);
        else if(calendarItem["day"] == "Wednsday")
            Wednsday.push_back(calendarItem);
        else if(calendarItem["day"] == "Thursday")
            Thursday.push_back(calendarItem);
        else
            Friday.push_back(calendarItem);
    }

    seperatedDays.push_back(Saturday);
    seperatedDays.push_back(Sunday);
    seperatedDays.push_back(Monday);
    seperatedDays.push_back(Tuesday);
    seperatedDays.push_back(Wednsday);
    seperatedDays.push_back(Thursday);
    seperatedDays.push_back(Friday);

    this->seperatedCalendar = seperatedDays;
}



