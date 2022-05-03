#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <gamewidge.h>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_startbtn_clicked();

    void on_levelbtn_clicked();

    void on_exitbtn_clicked();
signals:
    void startgame(int level,QPoint poin);
private:
    Ui::Widget *ui;
    int level;
    GameWidge *game;
};

#endif // WIDGET_H
