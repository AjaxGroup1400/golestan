#ifndef TEACHER_H
#define TEACHER_H

#include <QDialog>
#include <QList>
#include <QMap>
#include <QString>

namespace Ui {
class Teacher;
}

class Teacher : public QDialog
{
    Q_OBJECT

public:

    explicit Teacher(QWidget *parent = nullptr);
    ~Teacher();
    QList<QString> studensList(QString classname);

private:
    Ui::Teacher *ui;
    QMap <QString, QString> students;

};

#endif // TEACHER_H
// bp calculus physics chemistry discrete
