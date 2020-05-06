#ifndef LED_H
#define LED_H

#include <QDialog>
#include <QSocketNotifier>
#include <QFile>
#include <QDebug>

namespace Ui {
class LED;
}

class LED : public QDialog
{
    Q_OBJECT

public:
    explicit LED(QWidget *parent = nullptr);
    ~LED();

signals:
    void finishRunning();

private slots:
    void on_LED1_clicked();

    void on_LED2_clicked();

    void on_LED3_clicked();

    void on_LED4_clicked();

    void on_back_clicked();

private:
    Ui::LED *ui;
    QFile *led_fd = nullptr;
    QSocketNotifier *sn = nullptr;
    char led_flag[2];
    bool K7_opened;
    bool K8_opened;
    bool K9_opened;
    bool K10_opened;
};

#endif // LED_H
