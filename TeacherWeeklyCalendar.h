#ifndef TEACHERWEEKLYCALENDAR_H
#define TEACHERWEEKLYCALENDAR_H

#include "WeeklyCalendar.h"
#include <QString>

class TeacherWeeklycalendar : public WeeklyCalendar
{
public:
    TeacherWeeklycalendar();

    virtual void show(QString username);
};

#endif // TEACHERWEEKLYCALENDAR_H
