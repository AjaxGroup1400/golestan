#ifndef WEEKLYCALENDAR_H
#define WEEKLYCALENDAR_H

#include "dist/json/json.h"

#include <QString>
#include <QList>
#include <QMap>

class WeeklyCalendar
{
private:
    bool isClassExist(Json::Value classData);

protected:
    Json::Value dataHolder;
    Json::Reader dataReader;
    QList<QMap<QString, QString>> calendar;

    QString filePath = "../data_resources/weeklycalendar.json";

public:
    WeeklyCalendar();

    virtual void loadCalendar(QString username) = 0;

    // initialize data for calendar
    virtual void addUser(Json::Value data) = 0;

    const QList<QMap<QString, QString> > &getCalendar() const;

    // name is the name of class(class means learning class)
    Json::Value formClassData(QString name, QString day, QString time);

    // adds class to target user based on username and user role
    void appendClass(Json::Value newClass, QString username, QString role);

    // deletes class from target user based on class name
    void deleteClass(QString name, QString username, QString role);
};

#endif // WEEKLYCALENDAR_H
