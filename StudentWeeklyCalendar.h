#ifndef STUDENTWEEKLYCALENDAR_H
#define STUDENTWEEKLYCALENDAR_H

#include "WeeklyCalendar.h"


class StudentWeeklyCalendar : public WeeklyCalendar
{
public:
    StudentWeeklyCalendar();

    virtual void loadCalendar(QString username);

    virtual void addUser(Json::Value data);

    virtual void getCalendarDayByDay();
};

#endif // STUDENTWEEKLYCALENDAR_H
