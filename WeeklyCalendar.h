#ifndef WEEKLYCALENDAR_H
#define WEEKLYCALENDAR_H

#include "dist/json/json.h"

#include <QString>
#include <QList>
#include <QMap>

class WeeklyCalendar
{
protected:
    Json::Value dataHolder;
    Json::Reader dataReader;
    QList<QMap<QString, QString>> calendar;

    QString filePath = "../data_resources/weeklycalendar.json";

public:
    WeeklyCalendar();
    virtual void show(QString username) = 0;
    const QList<QMap<QString, QString> > &getCalendar() const;
};

#endif // WEEKLYCALENDAR_H
