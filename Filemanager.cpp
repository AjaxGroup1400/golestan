#include <QFile>
#include <QString>
#include <QDir>

#include <string>
#include <iostream>
#include <sstream>

#include "Filemanager.h"

using namespace std;

void FileManager::init()
{
    QDir dir;

    if(!dir.exists(this->dirPath))
    {
        dir.mkdir(this->dirPath);
    }
}

FileManager::FileManager()
{
    this->init();
}

FileManager::FileManager(QString dirPath)
{
    this->dirPath = dirPath;

    this->init();
}

FileManager::~FileManager()
{

}

const QString &FileManager::getDirPath() const
{
    return this->dirPath;
}

void FileManager::create(QString filename)
{
    QFile file(this->dirPath + filename);

    if(file.exists())
    {
        cout << "File Found Successfuly" << endl;

        this->filename = this->dirPath + filename;

        file.close();

        return;
    }

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        cout << "File Created successfuly" << endl;

        this->filename = this->dirPath + filename;

        file.close();

        return;
    }
}

// loads all data in file into a list in class to have easier access
void FileManager::loadData()
{
    QFile file(this->filename);

    if(!file.open(QIODevice::ReadOnly))
    {
        cerr << "Coudln't open the file!" << endl;
        return;
    }

    QTextStream stream(&file);

    while(!stream.atEnd())
    {
        QString line = stream.readLine();

        this->data.push_back(line);
    }


    file.close();
}

// write the whole data into file
// NOTE: use it after appending, deleting, or updating to submit the changes into file
void FileManager::write()
{
    QFile file(this->filename);

    if(!file.open(QIODevice::WriteOnly))
    {
        cerr << "Couldn't open the file!" << endl;

        return;
    }


    QTextStream stream(&file);

    for(size_t i = 0; i < this->data.size(); i++)
    {
        stream << this->data.at(i) << "\n";
    }

    file.close();
}

void FileManager::append(QString record)
{
    this->data.push_back(record);
}

QString FileManager::getRecord(int index)
{
    return this->data.at(index);
}

void FileManager::deleteRecord(int index)
{
    this->data.removeAt(index);
}

QVector<QString> FileManager::parse(QString str, char delimiter)
{
    QVector<QString> splittedWords;

    istringstream stream(str.toStdString());

    string word;

    while(getline(stream, word, delimiter)) {
        splittedWords.push_back(QString::fromStdString(word));
    }

    return splittedWords;
}







