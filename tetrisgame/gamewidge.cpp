#include "gamewidge.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#define RED 1           //红色
#define YELLOW 2         //黄色
#define BLUE 3          //蓝色
#define GREEN 4         //绿色
#define ORANGE 5        //橙色
#define PINK 6          //粉色
#define VIOLET 7        //紫色
GameWidge::GameWidge(QWidget *parent) : QWidget(parent),
    tim(new QTimer),
    score(0)
{
    widgetsize=new int*[15];
    for(int a=0;a<15;a++)
    {
        widgetsize[a]=new int[15];
    }
    for(int a=0;a<15;a++)
        for(int b=0;b<15;b++)
        {
            widgetsize[a][b]=-1;
        }

     this->resize(800,600);
    scorelable=new QLabel(this);
     QLabel *writer=new QLabel(this);
     writer->setText("by:机智的阿辉");
     writer->move(700,580);
    scorelable->setText(QString("当前分数为：%1").arg(score));
    scorelable->move(650,500);

    //定时器,自动移动，消除方块，判断游戏结束
    connect(tim,&QTimer::timeout,this,[=](){
        clearDiamond();
        update();
        diamond->automoveDiamond();
        if(diamond->isgamveOver())
        {
            tim->stop();
            QMessageBox::information(NULL,"游戏结束",QString("你的得分为%1").arg(score));
            score=0;
            for(int a=0;a<15;a++)
                delete[] widgetsize[a];
            delete tim;
            this->close();
        };});


}

void GameWidge::drawWidge(QPainter *pain)
{
    for(int a=0;a<15;a++)
        for(int b=0;b<15;b++)
        {
            if(widgetsize[a][b]!=-1)
            {
                pain->save();
                QBrush bru;
                bru.setStyle(Qt::SolidPattern);
                if(widgetsize[a][b]==RED)
                        bru.setColor(Qt::red);
                else if(widgetsize[a][b]==YELLOW)
                    bru.setColor(Qt::yellow);
                else if(widgetsize[a][b]==BLUE)
                    bru.setColor(Qt::blue);
                else if(widgetsize[a][b]==GREEN)
                    bru.setColor(Qt::green);
                else if(widgetsize[a][b]==ORANGE)
                    bru.setColor(QColor(255, 140, 83));
                else if(widgetsize[a][b]==PINK)
                    bru.setColor(QColor(255, 170, 204));
                else if(widgetsize[a][b]==VIOLET)
                    bru.setColor(QColor(255,0,255));
                pain->setBrush(bru);
                pain->drawRect(QRect(QPoint(a*40,b*40),QSize(40,40)));
                pain->restore();
            }
        }

}

void GameWidge::drawSocreWidge(QPainter *pain)
{
    pain->save();
    QPen pen(Qt::black);
    pen.setWidth(3);
    pain->setPen(pen);
    pain->drawLine(QPoint(40*15,0),QPoint(15*40,40*15));
    QBrush bru(QColor(197,197,197));
    pain->setBrush(bru);
    pain->drawRect(603,0,200,600);
    pain->restore();
}

void GameWidge::drawnextDiamond(QPainter *paint)
{
    paint->save();
    QBrush bru(Qt::red);
    paint->setBrush(bru);
    paint->drawRect(QRect(nextdoamond->xy1*40+QPoint(400,150),QSize(40,40)));
    paint->drawRect(QRect(nextdoamond->xy2*40+QPoint(400,150),QSize(40,40)));
    paint->drawRect(QRect(nextdoamond->xy3*40+QPoint(400,150),QSize(40,40)));
    paint->drawRect(QRect(nextdoamond->xy4*40+QPoint(400,150),QSize(40,40)));
    paint->restore();
}

void GameWidge::clearDiamond()
{
    for(int a=14;a>=0;a--)
    {
        int count=0;
        for(int b=0;b<15;b++)
        {
            if(widgetsize[b][a]==-1)
                break;
            else
                count++;
        }
        if(count==15)
        {
            this->score++;
            scorelable->setText(QString("当前分数为：%1").arg(score));
            for(int c=0;c<15;c++)
            {
                for(int d=a;d>0;d--)
                widgetsize[c][d]=widgetsize[c][d-1];
            }
            a++;
        }
    }
//    for(int y=0;y<15;y++)
//    {
//        int count=0;
//        for(int x=0;x<15;x++)
//        {
//            if(widgetsize[x][y]==-1)

//        }
//    }
}

void GameWidge::startgame(int level, QPoint poin)
{

    this->level=level;
    tim->setInterval(level);
    this->move(poin);
    this->show();
    this->diamond=new Diamond_J;
    //添加随机方块
    {
        int temp=rand()%7+1;
        if(temp==1)
        nextdoamond=new Diamond_J;
        else if(temp==2)
            nextdoamond=new Diamond_L;
        else if(temp==3)
            nextdoamond=new Diamond_I;
        else if(temp==4)
            nextdoamond=new Diamond_O;
        else if(temp==5)
            nextdoamond=new Diamond_S;
        else if(temp==6)
            nextdoamond=new Diamond_T;
        else if(temp==7)
            nextdoamond=new Diamond_Z;
    }
    tim->start();
    connect(this,&GameWidge::sentdata,diamond,&Diamond::getdata);
    emit sentdata(widgetsize);
}

void GameWidge::paintEvent(QPaintEvent *event)
{
    QPainter pain(this);
    this->drawSocreWidge(&pain);
     diamond->drawDiamond(&pain);
    if(diamond->crashDiamond())
    {
        widgetsize[diamond->xy1.x()][diamond->xy1.y()]=diamond->getDiamondColor();
        widgetsize[diamond->xy2.x()][diamond->xy2.y()]=diamond->getDiamondColor();
        widgetsize[diamond->xy3.x()][diamond->xy3.y()]=diamond->getDiamondColor();
        widgetsize[diamond->xy4.x()][diamond->xy4.y()]=diamond->getDiamondColor();

        qDebug()<<diamond->getDiamondColor();
         delete diamond;
        //this->diamond=new Diamond_L;
        diamond=nextdoamond;
        //生成下一个随机方块
            int temp=rand()%7+1;
           // int temp=3;
            if(temp==1)
            nextdoamond=new Diamond_J;
            else if(temp==2)
                nextdoamond=new Diamond_L;
            else if(temp==3)
                nextdoamond=new Diamond_I;
            else if(temp==4)
                nextdoamond=new Diamond_O;
            else if(temp==5)
                nextdoamond=new Diamond_S;
            else if(temp==6)
                nextdoamond=new Diamond_T;
            else if(temp==7)
                nextdoamond=new Diamond_Z;
            connect(this,&GameWidge::sentdata,diamond,&Diamond::getdata);
        sentdata(widgetsize);
    }
    drawWidge(&pain);
    // this->drawnextDiamond(&pain);
    nextdoamond->drawDiamond(&pain,400,150);
   // qDebug()<<widgetsize[7][14];
}

void GameWidge::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Space)
    {
        diamond->changeDiamond();
    }
    if(event->key()==Qt::Key_Down)
    {
        while (!diamond->crashDiamond())
        {
            diamond->automoveDiamond();
        }
        update();
    }
    diamond->moveDiamond(event);
    QPainter pain(this);
    diamond->drawDiamond(&pain);
    update();
}
