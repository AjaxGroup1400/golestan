#include "WeeklyCalendar.h"

#include <fstream>

using namespace std;

WeeklyCalendar::WeeklyCalendar()
{
    return;
}

const QList<QMap<QString, QString>> &WeeklyCalendar::getCalendar() const
{
    return calendar;
}

Json::Value WeeklyCalendar::formClassData(QString name, QString day, QString time)
{
    Json::Value classData;

    classData["name"] = name.toStdString();
    classData["day"] = day.toStdString();
    classData["time"] = time.toStdString();

    return classData;
}

void WeeklyCalendar::appendClass(Json::Value newClass, QString username, QString role)
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value wantedRoleData = dataHolder[role.toStdString()];

        for(int i = 0; i < wantedRoleData.size(); i++)
        {
            if(wantedRoleData[i]["username"] == username.toStdString())
            {
                Json::Value wantedUsernameClasses = wantedRoleData[i]["classes"];

                wantedUsernameClasses.append(newClass);

                Json::StyledWriter writer;

                ofstream jsonWriter(filePath.toStdString());

                dataHolder[role.toStdString()][i]["classes"] = wantedUsernameClasses;

                string serializedData = writer.write(dataHolder);

                jsonWriter << serializedData;

                jsonWriter.close();
            }
        }
    }
}

void WeeklyCalendar::deleteClass(QString name, QString username, QString role)
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value wantedRoleData = dataHolder[role.toStdString()];

        for(int i = 0; i < wantedRoleData.size(); i++)
        {
            if(wantedRoleData[i]["username"] == username.toStdString())
            {
                Json::Value wantedUsernameClasses = wantedRoleData[i]["classes"];

                Json::Value classesCopy;

                for(int j = 0; j < wantedUsernameClasses.size(); j++)
                {
                    if(wantedUsernameClasses[j]["name"] != name.toStdString())
                    {
                        classesCopy.append(wantedUsernameClasses[j]);
                    }
                }

                Json::StyledWriter writer;

                ofstream jsonWriter(filePath.toStdString());

                dataHolder[role.toStdString()][i]["classes"] = classesCopy;

                string serializedData = writer.write(dataHolder);

                jsonWriter << serializedData;

                jsonWriter.close();
            }
        }
    }

}



