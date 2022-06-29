#ifndef WEEKLYCALENDER_H
#define WEEKLYCALENDER_H

#include "dist/json/json.h"

#include <QString>
#include <QList>
#include <QVector>

class WeeklyCalender
{
protected:
    Json::Value dataHolder;
    Json::Reader dataReader;
    QList<QVector<QString>> calender;

    QString filePath = "../data_resources/weeklycalender.json";

public:
    WeeklyCalender();
    virtual void show(QString username) = 0;
    const QList<QVector<QString> > &getCalender() const;
};

#endif // WEEKLYCALENDER_H
