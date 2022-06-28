#include "Permission.h"

Permission::Permission(QObject *parent)
    : QObject{parent}
{

}

QString Permission::get_permission()
{
    return this->allowed_tasks ;
}
