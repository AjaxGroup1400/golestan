#include "Weeklycalender.h"

#include <fstream>

using namespace std;

const QList<QVector<QString> > &WeeklyCalender::getCalender() const
{
    return calender;
}

WeeklyCalender::WeeklyCalender()
{

}
