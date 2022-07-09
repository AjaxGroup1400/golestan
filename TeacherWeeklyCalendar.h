#ifndef TEACHERWEEKLYCALENDAR_H
#define TEACHERWEEKLYCALENDAR_H

#include "WeeklyCalendar.h"
#include <QString>
#include <QMap>
#include <QList>

class TeacherWeeklycalendar : public WeeklyCalendar
{
public:
    TeacherWeeklycalendar();

    virtual void loadCalendar(QString username);

    virtual void addUser(Json::Value data);

//    virtual void getCalendarDayByDay();
};

#endif // TEACHERWEEKLYCALENDAR_H
