#ifndef TEACHER_H
#define TEACHER_H

#include <QDialog>
#include <QList>
#include <QMap>
#include <QString>
#include<QString>

#include"User.h"

namespace Ui {
class Teacher;
}

class Teacher :  public  User ,  public QDialog
{
    Q_OBJECT

public:

    explicit Teacher(QWidget *parent = nullptr);
    ~Teacher();
    QList<QString> studensList(QString classname);

    void deletest(QString name , QString lesson);
    void sendingNotification(QString message , QString lesson , QList<QString> list);
private:
    Ui::Teacher *ui;
    QMap <QString, QString> students;

};

#endif // TEACHER_H
// bp calculus physics chemistry discrete
