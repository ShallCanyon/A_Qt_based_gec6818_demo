#include "util.h"
bool GetFileFromPath(QString &path, QStringList suffix, QList<QString> &receiveList)
{
    QDir *dir = new QDir(path);
    if(!dir->exists())
        return false;

    QList<QFileInfo> *dirInfoList = new QList<QFileInfo>(dir->entryInfoList(QDir::Dirs));
    QList<QFileInfo> *suffixInfoList = new QList<QFileInfo>(dir->entryInfoList(suffix));

    for(int i=0;i<dirInfoList->count();i++)
    {
        if(dirInfoList->at(i).fileName()=="." || dirInfoList->at(i).fileName()=="..")
            continue;
        QString childPath = dirInfoList->at(i).filePath();
        GetFileFromPath(childPath, suffix, receiveList);
    }
    for(int i=0;i<suffixInfoList->count();i++)
        receiveList << suffixInfoList->at(i).filePath();
    delete dirInfoList;
    delete suffixInfoList;
    return true;
}
