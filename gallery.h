#ifndef GALLERY_H
#define GALLERY_H

#include <QWidget>
#include <QLabel>
#include <QScrollArea>
#include <QDebug>

namespace Ui {
class Gallery;
}

class Gallery : public QWidget
{
    Q_OBJECT

public:
    explicit Gallery(QWidget *parent = nullptr);
    ~Gallery();

signals:
    void finishRunning();

private slots:
    void on_btn_prev_clicked();

    void on_btn_quit_clicked();

    void on_btn_next_clicked();

private:
    Ui::Gallery *ui;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QString basePath;
    QStringList suffix;
    QList<QString> filename;
    bool isEmpty;
    unsigned int counter;
};

#endif // GALLERY_H
