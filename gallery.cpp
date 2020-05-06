#include "gallery.h"
#include "ui_gallery.h"
#include "util.h"

Gallery::Gallery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gallery)
{
    ui->setupUi(this);
    imageLabel = ui->imageLabel;
    scrollArea = ui->scrollArea;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea->setAlignment(Qt::AlignHCenter);

    counter = 0;
    basePath = "./";
    suffix << "*.png" << "*.jpg" << "*.bmp";
    /*bool png = GetFileFromPath(basePath, QStringList()<<"*.png", filename);
    bool jpg = GetFileFromPath(basePath, QStringList()<<"*.jpg", filename);
    bool bmp = GetFileFromPath(basePath, QStringList()<<"*.bmp", filename);*/
    if(!GetFileFromPath(basePath, suffix, filename))
    // if(png||jpg||bmp)
    {
        qDebug() << "No image found.\n";
        isEmpty = true;
        ui->btn_next->setEnabled(false);
        ui->btn_prev->setEnabled(false);
        imageLabel->setText(tr("No image found"));
    }
    else
    {
        isEmpty = false;
        imageLabel->setPixmap(QPixmap(filename.at(0)));
    }
}

Gallery::~Gallery()
{
    delete ui;
}

void Gallery::on_btn_prev_clicked()
{
    if(!isEmpty)
    {
        counter = (filename.count() + counter - 1)%filename.count();
        imageLabel->setPixmap(QPixmap(filename.at(counter)));
    }
}

void Gallery::on_btn_quit_clicked()
{
    emit finishRunning();
    this->close();
}

void Gallery::on_btn_next_clicked()
{
    if(!isEmpty)
    {
        counter = (filename.count() + counter + 1)%filename.count();
        imageLabel->setPixmap(QPixmap(filename.at(counter)));
    }
}
