#include "WeeklyCalendar.h"

#include <fstream>

using namespace std;

WeeklyCalendar::WeeklyCalendar()
{
    return;
}

const QList<QMap<QString, QString> > &WeeklyCalendar::getCalendar() const
{
    return calendar;
}
