 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    led = new LED();
    music = new Music();
    connect(led, &LED::finishRunning, this, &MainWindow::show);
    connect(music, &Music::finishRunning, this, &MainWindow::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_screen_clicked()
{
    // initialized after clicked
    // to avoid the backgroud color is not set as default
    scr = new Screen();
    connect(scr, &Screen::finishRunning, this, &MainWindow::show);
    this->hide();
    scr->show();
}

void MainWindow::on_btn_led_clicked()
{
    this->hide();
    led->show();
}

void MainWindow::on_btn_music_clicked()
{
    this->hide();
    music->show();
}

void MainWindow::on_btn_gallery_clicked()
{
    gal = new Gallery();
    connect(gal, &Gallery::finishRunning, this, &MainWindow::show);
    this->hide();
    gal->show();
}

void MainWindow::on_btn_close_clicked()
{
    this->close();
}
