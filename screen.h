#ifndef SCREEN_H
#define SCREEN_H

#define TIMER_RED 1
#define TIMER_GREEN 2
#define TIMER_BLUE 3

#include <QWidget>
#include <QPushButton>
#include <QDebug>

namespace Ui {
class Screen;
}

class Screen : public QWidget
{
    Q_OBJECT

public:
    explicit Screen(QWidget *parent = nullptr);
    ~Screen();

private slots:
    void on_colorView_clicked();

signals:
    void finishRunning();
private:
    Ui::Screen *ui;
    unsigned int timer;
    QPalette pal;
};

#endif // SCREEN_H
