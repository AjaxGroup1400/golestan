#ifndef TEACHER_H
#define TEACHER_H

#include <QDialog>
#include <QList>
#include <QMultiMap>
#include <QString>
#include <QObject>
#include"User.h"

namespace Ui {
class Teacher;
}

class Teacher :  public  User
{
    Q_OBJECT

public:

    explicit Teacher(QWidget *parent = nullptr);
    ~Teacher();
    QMap<QString, float> studentsList(QString classname);

    void deletest(QString name , QString lesson);
    void sendingNotification(QString message , QString lesson , QList<QString> list);
private:
    Ui::Teacher *ui;
    QMultiMap < QString ,QMap<QString, float> > students;

signals:
    QString notificationSent(QString);
};

#endif // TEACHER_H
// bp calculus physics chemistry discrete
