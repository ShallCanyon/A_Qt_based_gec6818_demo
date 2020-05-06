#include "music.h"
#include "ui_music.h"
#include "util.h"

Music::Music(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Music)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_AcceptTouchEvents, true);
    started = false;
    is_playing = false;
    counter = 0;

    mp = new QProcess();
    //cmd = new QProcess();
    baseAddr = "./";
    suffix << "*.mp3";
    GetFileFromPath(baseAddr, suffix, filename);
}

Music::~Music()
{
    delete mp;
    //delete cmd;
    delete ui;
}

void Music::on_start_pause_clicked()
{
    if(!started)
    {
        if(filename.count()<=0)
        {
            qDebug()<<"No song found\n";
            return;
        }
        //args << filename.at(0) << "&";
        // mp->execute block other threads
        //mp->startDetached("madplay", args);
        playMusic(0);
        started = true;
        is_playing = true;
    }
    else
    {
        if(is_playing) // pause songs
        {
            QProcess p(0);
            p.start("killall", QStringList()<<"-STOP"<<"madplay"<<"&");
            p.waitForStarted();
            p.waitForFinished();
            is_playing = false;
        }else          // resume songs
        {
            QProcess p(0);
            p.start("killall", QStringList()<<"-CONT"<<"madplay"<<"&");
            p.waitForStarted();
            p.waitForFinished();
            is_playing = true;
        }
    }
}

void Music::on_prev_clicked()
{
    if(filename.count()>0)
    {
        counter = (filename.count() + counter - 1) % filename.count();
    //    args.clear();
    //    args << filename.at(counter) << "&";
    //    mp->startDetached("madplay", args);
        playMusic(counter);
    }
}

void Music::on_next_clicked()
{
    if(filename.count()>0)
    {
        counter = (filename.count() + counter + 1) % filename.count();
    //    args.clear();
    //    args << filename.at(counter) << "&";
    //    mp->startDetached("madplay", args);
        playMusic(counter);
    }
}

void Music::on_back_clicked()
{
    emit finishRunning();
    this->close();
}


void Music::playMusic(unsigned int counter)
{
    args.clear();
    QString song_path = filename.at(counter);
    QFileInfo fi(song_path);
    QString song_name = fi.fileName();
    args << song_path << "&";
    ui->info_show->setText(song_name);
    if(mp->isOpen())
        mp->close();
    mp->start("madplay", args);
}
