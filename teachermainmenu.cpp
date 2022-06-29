#include<QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include <QVector>
#include <QMultiMap>

#include "teachermainmenu.h"
#include "ui_teachermainmenu.h"
#include "loginpage.h"
#include "teacherprofile.h"
#include "ui_Teacher.h"
#include "Auth.h"
#include "Filemanager.h"
#include "User.h"





TeacherMainMenu::TeacherMainMenu(QWidget *parent) :
//    QWidget(parent),
    ui(new Ui::TeacherMainMenu)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->label_13->setStyleSheet("background-color: #f0f0f0; border-radius: 20px;");

    FileManager userFile;

    userFile.create("teacher.txt");

    userFile.loadData();

    for(const QString& item: userFile.getData()){
        auto parse = userFile.parse(item);

        if (parse[0] == this->get_username()){
            QMap <QString, float> studentscore;
            studentscore.insert(parse[2],parse[3].toFloat()) ;
            this->students.insert( parse[1] , studentscore ) ;
        }
    }

}

TeacherMainMenu::~TeacherMainMenu()
{
    delete ui;
}

void TeacherMainMenu::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Close Window","Do you want to close this window?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        LoginPage* lg = new LoginPage;
        lg->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}





void TeacherMainMenu::on_pushButton_clicked()
{
    teacherProfile* tp = new teacherProfile;
    tp->show();
    close();
}

QMap<QString, float> TeacherMainMenu::studentsList(QString classname)
{
    QMap <QString, float> classlist;

for (auto i=this->students.begin(); i!=this->students.end(); i++){
    auto j = i.value().begin();

    if (j.key() == classname){

        classlist.insert( i.key(), j.value() );
    }
}
    return classlist;

}

void TeacherMainMenu::deletest(QString name , QString lesson)
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


void TeacherMainMenu::sendingNotification(QString message , QString lesson , QList<QString> list)
{
    QString finalmessage = "Lesson" + lesson + "from" + this->get_first_name() + this->get_last_name() +": \n" + message;

    for (auto i = list.begin() ; i != list.end() ; i++ )
    {
//        QObject::connect (this, &Teacher::notificationSent, , )

    }
    emit (TeacherMainMenu:: notificationSent(finalmessage) );

}








void TeacherMainMenu::on_pushButton_3_clicked()
{
    QMap<QString , float> chemistry = this->studentsList("chemistry");
    QMap<QString , float> physics = this->studentsList("physics");
    QMap<QString , float> bp = this->studentsList("bp");
    QMap<QString , float> calculus = this->studentsList("calculus");
    QMap<QString , float> discrete = this->studentsList("discrete");


    //  new page(chemistry , chemistry.size , ...)
//  class name , number of students , students' names , class location

}


void TeacherMainMenu::on_pushButton_6_clicked()
{
    QMap<QString , float> chemistry = this->studentsList("chemistry");
    QMap<QString , float> physics = this->studentsList("physics");
    QMap<QString , float> bp = this->studentsList("bp");
    QMap<QString , float> calculus = this->studentsList("calculus");
    QMap<QString , float> discrete = this->studentsList("discrete");




}

