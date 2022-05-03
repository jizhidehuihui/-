#ifndef DIAMOND_H
#define DIAMOND_H
#include <QPoint>
#include <QKeyEvent>
#include <QPainter>
#include <QObject>
#include <QDebug>
#define RED 1           //红色
#define YELLO 2         //黄色
#define BLUE 3          //蓝色
#define GREED 4         //绿色
#define ORANGE 5        //橙色
#define PINK 6          //粉色
#define VIOLET 7        //紫色
class Diamond:public QObject
{
public:
    Diamond();
    QPoint xy1;//
    QPoint xy2;
    QPoint xy3;
    QPoint xy4;
    virtual void drawDiamond(QPainter *paint);//绘制方块
    virtual void drawDiamond(QPainter *paint,int x,int y);
    virtual void automoveDiamond();//方块自动下落
    virtual void moveDiamond(QKeyEvent *event);//方块平行移动
    virtual int getDiamondColor()=0;//获取方块颜色
    virtual void getBoundaty();//获取方块边界
    virtual void getdata(int **size);//获取主界面大小
    virtual bool crashDiamond();//判断方块是否落地
    virtual bool crashleft();//判断方块是否可以左移
    virtual bool crashright();//判断方块是否可以右移
    virtual bool isgamveOver();//判断游戏是否结束
    virtual void changeDiamond()=0;//更改方块方向
    void test()
    {
        qDebug()<<"xy1"<<xy1.x()<<xy1.y();
        qDebug()<<"xy2"<<xy2.x()<<xy2.y();
        qDebug()<<"xy3"<<xy3.x()<<xy3.y();
        qDebug()<<"xy4"<<xy4.x()<<xy4.y();
    }

protected:
    int state=1;
    int bottom;//方块底部
    int left;//方块左侧边界
    int right;//方块右侧边界
    int **widgeSize;//主界面大小

};

class Diamond_L:public Diamond
{
public:
    Diamond_L();
    virtual void automoveDiamond();
   // virtual void moveDiamond(QKeyEvent *event);
    virtual int getDiamondColor();
    virtual void changeDiamond();
private:


};

class Diamond_J:public Diamond
{
public:
    Diamond_J();
    virtual int getDiamondColor();
    virtual void changeDiamond();
};
class Diamond_I:public Diamond
{
public:
    Diamond_I();
    virtual int getDiamondColor();
    virtual void changeDiamond();
};
class Diamond_T:public Diamond
{
public:
    Diamond_T();
    virtual int getDiamondColor();
    virtual void changeDiamond();
};
class Diamond_Z:public Diamond
{
public:
    Diamond_Z();
    virtual int getDiamondColor();
    virtual void changeDiamond();
};
class Diamond_S:public Diamond
{
public:
    Diamond_S();
    virtual int getDiamondColor();
    virtual void changeDiamond();
};
class Diamond_O:public Diamond
{
public:
    Diamond_O();
    virtual int getDiamondColor();
    virtual void changeDiamond();
};
#endif // DIAMOND_H
