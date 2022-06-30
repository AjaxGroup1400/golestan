#include "CalendarCreator.h"

CalendarCreator::CalendarCreator()
{
    Json::Value initData;

    initData["username"] = Json::stringValue;

    initData["classes"] = Json::arrayValue;

    jsonCalendar = initData;

    return;
}

void CalendarCreator::setUsername(QString username)
{
    jsonCalendar["username"] = username.toStdString();

    return;
}

void CalendarCreator::append(QString name, QString day, QString time)
{
    Json::Value modifiedClasses = jsonCalendar["classes"];

    Json::Value classData;

    classData["name"] = name.toStdString();
    classData["day"] = day.toStdString();
    classData["time"] = time.toStdString();

    modifiedClasses.append(classData);

    jsonCalendar["classes"] = modifiedClasses;

    return;
}

const Json::Value CalendarCreator::exportJson() const
{
    return jsonCalendar;
}



