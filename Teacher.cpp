#include<QMessageBox>

#include "Teacher.h"
#include "ui_Teacher.h"
#include"Auth.h"
#include"Filemanager.h"
#include"User.h"
#include <QAbstractButton>

Teacher::Teacher(QWidget *parent) :
//    QWidget(parent),
    ui(new Ui::Teacher)
{
//    ui->setupUi(this);
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
void Teacher::deletest(QString name , QString lesson)
{
    int index = Auth::validStudent(name , lesson);
//    if (newPass != confirmNewPass)
//    {
//        QMessageBox * confirmPassDoesntMatch = new QMessageBox(QMessageBox::Icon::Critical , "Error" , "field \"new password\" doesn't equal field \"confirm new password\"" , QMessageBox::Button::Ok);
//        confirmPassDoesntMatch->show();
//        connect(confirmPassDoesntMatch , &QMessageBox::buttonClicked , confirmPassDoesntMatch, &QMessageBox::deleteLater);
//        return;
//    }

    FileManager userFile;

    userFile.create("teacher.txt");

    userFile.loadData();


    userFile.deleteRecord(index);


    userFile.write();

    QMessageBox * studentdeleted = new QMessageBox(QMessageBox::Icon::Information, "Student deleted", "the student was deleted succesfuly", QMessageBox::Button::Ok);
//    studentdeleted->setParent(this);

    studentdeleted->show();

    QObject::connect(studentdeleted , &QMessageBox::buttonClicked , studentdeleted , &QMessageBox::deleteLater);

//    LoginPage* lg = new LoginPage;

//    connect(studentdeleted, &QMessageBox::buttonClicked, lg, &LoginPage::show);

    //    connect(studentdeleted, &QMessageBox::buttonClicked, this, &EntereNewPass::close);
}

void Teacher::sendingNotification(QString message , QString lesson , QList<QString> list)
{
    QString finalmessage = "from teacher" + this->get_first_name() ;
    for (auto i = list.begin() ; i != list.end() ; i++ )
    {

    }

}

