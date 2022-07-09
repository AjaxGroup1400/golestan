#ifndef TEACHERSTUDENTSETSCORE_H
#define TEACHERSTUDENTSETSCORE_H

#include <QWidget>
#include <QGroupBox>

namespace Ui {
class TeacherStudentSetScore;
}

class TeacherStudentSetScore : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherStudentSetScore(QWidget *parent = nullptr);
    ~TeacherStudentSetScore();
public slots:
    QGroupBox* showStudent();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_backToMenu_clicked();

    void on_SetScore_clicked();

private:

    float* scores;
    int numberOfStudents;
    Ui::TeacherStudentSetScore *ui;

    void setScore(int numberOfStudents, float score);


};

#endif // TEACHERSTUDENTSETSCORE_H
