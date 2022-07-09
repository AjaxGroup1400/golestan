#ifndef TEACHERCLASSSETSCORE_H
#define TEACHERCLASSSETSCORE_H

#include <QWidget>
#include <QGroupBox>

namespace Ui {
class TeacherClassSetScore;
}

class TeacherClassSetScore : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherClassSetScore(QWidget *parent = nullptr);
    ~TeacherClassSetScore();
public slots:
    QGroupBox* watchClass();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_backToMenu_clicked();

private:
    Ui::TeacherClassSetScore *ui;
    void goToClassInfo(QString className);
};

#endif // TEACHERCLASSSETSCORE_H
