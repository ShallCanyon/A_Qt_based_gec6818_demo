#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "music.h"
#include "led.h"
#include "screen.h"
#include "gallery.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btn_screen_clicked();

    void on_btn_led_clicked();

    void on_btn_music_clicked();

    void on_btn_gallery_clicked();

    void on_btn_close_clicked();

private:
    Ui::MainWindow *ui;
    Screen *scr = nullptr;
    Music *music = nullptr;

    ////bugged/////
    LED *led = nullptr;
    Gallery *gal = nullptr;
};
#endif // MAINWINDOW_H
