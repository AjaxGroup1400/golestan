#ifndef TEACHER_H
#define TEACHER_H

#include <QDialog>

namespace Ui {
class Teacher;
}

class Teacher : public QDialog
{
    Q_OBJECT

public:
    explicit Teacher(QWidget *parent = nullptr);
    ~Teacher();

private:
    Ui::Teacher *ui;
};

#endif // TEACHER_H
