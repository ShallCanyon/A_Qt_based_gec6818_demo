#include "led.h"
#include "ui_led.h"

LED::LED(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LED)
{
    ui->setupUi(this);
    led_fd->setFileName("/dev/led_drv");
    if(!led_fd->exists())
    {
        qDebug() << "LED_DRV not exist";
    }

    //bugged
    led_fd->open(QIODevice::ReadWrite);
    if(!led_fd->isOpen())
    {
        qDebug() << "LED_DRV open failed";
    }
    /*
    K7_opened = K8_opened = K9_opened = K10_opened = false;
    sn = new QSocketNotifier(led_fd->handle(), QSocketNotifier::Write, this);*/
}

LED::~LED()
{
    delete ui;
}

void LED::on_LED1_clicked()
{
    /*led_flag[1] = 7;
    if(K7_opened)
        led_flag[0] = 0;
    else
        led_flag[1] = 1;
    led_fd->write(led_flag, sizeof(led_flag));*/
}

void LED::on_LED2_clicked()
{
    /*led_flag[1] = 8;
    if(K8_opened)
        led_flag[0] = 0;
    else
        led_flag[1] = 1;
    led_fd->write(led_flag, sizeof(led_flag));*/
}

void LED::on_LED3_clicked()
{
    /*led_flag[1] = 9;
    if(K9_opened)
        led_flag[0] = 0;
    else
        led_flag[1] = 1;
    led_fd->write(led_flag, sizeof(led_flag));*/
}

void LED::on_LED4_clicked()
{
    /*led_flag[1] = 10;
    if(K10_opened)
        led_flag[0] = 0;
    else
        led_flag[1] = 1;
    led_fd->write(led_flag, sizeof(led_flag));*/
}

void LED::on_back_clicked()
{
    emit finishRunning();
    this->close();
}
