#include "screen.h"
#include "ui_screen.h"


Screen::Screen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Screen)
{
    ui->setupUi(this);
    timer = 0;
    this->setAttribute(Qt::WA_AcceptTouchEvents, true);
    // cause segmentation fault when reactivate from mainwindow
    //this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->colorView->setText("Click to test screen");
    pal = ui->colorView->palette();
    /*pal.setColor(QPalette::Button, QColor(Qt::transparent));
    ui->colorView->setAutoFillBackground(true);
    ui->colorView->setPalette(pal);*/
    ui->colorView->update();
}

Screen::~Screen()
{
    delete ui;
}

void Screen::on_colorView_clicked()
{
    if(ui->colorView->text()!="")
        ui->colorView->setText("");
    timer++;
    try {
        switch(timer)
        {
            case 1:
                // use stylesheet makes the color flash per tap
                //ui->colorView->setStyleSheet("background-color: rgb(255,0,0);");
                pal.setColor(QPalette::Button, QColor(Qt::red));
                ui->colorView->setAutoFillBackground(true);
                ui->colorView->setPalette(pal);
                ui->colorView->update();
                break;
            case 2:
                //ui->colorView->setStyleSheet("background-color: rgb(0,255,0);");
                pal.setColor(QPalette::Button, QColor(Qt::green));
                ui->colorView->setAutoFillBackground(true);
                ui->colorView->setPalette(pal);
                ui->colorView->update();
                break;
            case 3:
                //ui->colorView->setStyleSheet("background-color: rgb(0,0,255);");
                pal.setColor(QPalette::Button, QColor(Qt::blue));
                ui->colorView->setAutoFillBackground(true);
                ui->colorView->setPalette(pal);
                ui->colorView->update();
                break;
            default:
                emit finishRunning();
                this->close();
                break;
        }
    } catch (std::exception e) {
        qDebug() << e.what();
    }

}
