#ifndef TEACHERWEEKLYCALENDAR_H
#define TEACHERWEEKLYCALENDAR_H

#include "WeeklyCalendar.h"
#include <QString>

class TeacherWeeklycalendar : public WeeklyCalendar
{
public:
    TeacherWeeklycalendar();

    virtual void loadCalendar(QString username);

    virtual void addUser(Json::Value data);
};

#endif // TEACHERWEEKLYCALENDAR_H
