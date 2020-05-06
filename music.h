#ifndef MUSIC_H
#define MUSIC_H

#include <QWidget>
#include <QProcess> // the way to use system()
#include <QDebug>

namespace Ui {
class Music;
}

class Music : public QWidget
{
    Q_OBJECT

public:
    explicit Music(QWidget *parent = nullptr);
    ~Music();

signals:
    void finishRunning();

private slots:
    void on_start_pause_clicked();

    void on_prev_clicked();

    void on_next_clicked();

    void on_back_clicked();

private:
    Ui::Music *ui;
    QProcess *mp;
    //QProcess *cmd;
    QStringList args;

    QString baseAddr;
    QStringList suffix;
    QList<QString> filename;

    bool started;
    bool is_playing;
    unsigned int counter;

    void playMusic(unsigned int counter);
};

#endif // MUSIC_H
