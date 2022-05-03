#ifndef GAMEWIDGE_H
#define GAMEWIDGE_H
#include "diamond.h"
#include <QWidget>
#include <QTimer>
#include <QQueue>
#include <QLabel>
class GameWidge : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidge(QWidget *parent = nullptr);//
    void drawWidge(QPainter *pain);//绘制主窗口
    void drawSocreWidge(QPainter *pain);//绘制积分栏
    void drawnextDiamond(QPainter *pain);//绘制下一个方块
    void clearDiamond();//消除方块
    void isgameOver();//判断游戏是否结束

signals:
    void gameOver();//退出游戏返回开始界面信号
    void sentdata(int **size);//当前界面方块可移动大小
public slots:
    void startgame(int level,QPoint poin);//游戏开始槽函数
    void paintEvent(QPaintEvent *event);//绘图事件
    void keyPressEvent(QKeyEvent *event);//鼠标事件

private:
    int level;//当前等级
    Diamond *diamond;//方块类   抽象类
    Diamond *nextdoamond;
    QTimer *tim;//定时器
    int **widgetsize;//方块可移动空间
    int score;//分数
    QLabel *scorelable;
};

#endif // GAMEWIDGE_H
