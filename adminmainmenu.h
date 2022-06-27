#ifndef ADMINMAINMENU_H
#define ADMINMAINMENU_H

#include <QWidget>

namespace Ui {
class AdminMainMenu;
}

class AdminMainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AdminMainMenu(QWidget *parent = nullptr);
    ~AdminMainMenu();

private:
    Ui::AdminMainMenu *ui;
};

#endif // ADMINMAINMENU_H
