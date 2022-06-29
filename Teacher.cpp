#include "Teacher.h"
#include "ui_Teacher.h"
#include <QList>
#include <QString>
#include <iterator>
#include <iostream>

Teacher::Teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Teacher)
{
    ui->setupUi(this);
}

Teacher::~Teacher()
{
    delete ui;
}

QList<QString> Teacher::studensList(QString classname)
{
    QList <QString> classlist;

for (auto i=this->students.begin(); i!=this->students.end(); i++){
    if (i.value()== classname){
        classlist.push_back(i.key());
    }
    return classlist;
}

}
