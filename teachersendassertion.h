#ifndef TEACHERSENDASSERTION_H
#define TEACHERSENDASSERTION_H

#include <QWidget>

namespace Ui {
class TeacherSendAssertion;
}

class TeacherSendAssertion : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherSendAssertion(QWidget *parent = nullptr);
    ~TeacherSendAssertion();

private slots:
    void on_backToMenu_clicked();

    void on_pushButton_clicked();

private:
    Ui::TeacherSendAssertion *ui;

    int studentsState;
    int teachersState;
    void studentReciveState(int state);
    void teacherReciveState(int state);
};

#endif // TEACHERSENDASSERTION_H
