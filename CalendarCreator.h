#ifndef CALENDARCREATOR_H
#define CALENDARCREATOR_H

#include "dist/json/json.h"

#include <QString>
#include <QList>
#include <QMap>

class CalendarCreator
{
private:
    QList<QMap<QString, QString>> classList;
    Json::Value jsonCalendar;

public:
    CalendarCreator();

    void setUsername(QString username);

    void append(QString name, QString day, QString time);

    const Json::Value exportJson() const;
};

#endif // CALENDARCREATOR_H
