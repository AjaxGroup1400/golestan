#include "studentmainmenu.h"
#include "ui_studentmainmenu.h"
#include "loginpage.h"
#include "studentprofile.h"

#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include <iterator>
#include <string>
#include <fstream>

using std::ifstream, std::string;
using std::ofstream;

StudentMainMenu::StudentMainMenu(QWidget *parent) :
//    QWidget(parent),
    ui(new Ui::StudentMainMenu)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->label_8->setStyleSheet("background-color: #f0f0f0; border-radius: 20px;");

    // initialize file(s)
    initFile();
}

StudentMainMenu::~StudentMainMenu()
{
    delete ui;
}

void StudentMainMenu::scores()
{
//    for(auto i = this->classes.begin(); i!= this->classes.end(); i++ ){

//        for(auto j = i->getList().begin(); j!=i->getList().end(); i++){

//            if(j.key()==this->get_username()){
//                float score = j.value();

//                if(score!=-1){
//                    //show...
//                }
//            }
//        }
//    }
}


void StudentMainMenu::surveyOfTeachers(Class Class, int result )
{
    //    Class.addSurveyResult(this->get_username(), result);
}

//bool StudentMainMenu:: is_equal(Class i){i.getLesson() == lesson.getLesson();}

void StudentMainMenu::deleteLesson(Class lesson)
{
//    QMultiMap <Class, float> helper;
//    for(auto i=this_term_classes.cbegin(); i!=this_term_classes.cend(); i++){
//        helper.insert(i.key(),i.value());
////        helper[i.key()]=i.value();
//    }
//    this_term_classes.erase(this_term_classes.begin(),this_term_classes.end());

//    for(auto j=helper.begin(); j!=helper.end(); j++){
//        auto &class_to_delete =j.key();
//        if(class_to_delete.getLesson() != lesson.getLesson())
//            this->this_term_classes.insert (j,j.key(),j.value());

//    }

//        auto &class_to_delete =i.key();
////        this->this_term_classes.removeIf(,this_term_classes.end(),class_to_delete.getLesson() == lesson.getLesson());
//        if(class_to_delete.getLesson() ==lesson.getLesson()){
//            this->this_term_classes.erase(i.key()) ;

}
void StudentMainMenu::registry(Class Class)
{
//    Class.addStudent(this->get_username());
//    this->classes.push_back(Class);
}





void StudentMainMenu::on_pushButton_5_clicked()
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


void StudentMainMenu::on_pushButton_clicked()
{
    StudentProfile* sp = new StudentProfile;
    sp->show();
    close();
}

void StudentMainMenu::initFile()
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {

        return;
    }

    ofstream ofs(filePath.toStdString());

    Json::StyledWriter writer;

    Json::Value baseData = Json::arrayValue;

    string serializedData = writer.write(baseData);

    ofs << serializedData;

    ofs.close();
}



