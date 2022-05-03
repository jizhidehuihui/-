#include "diamond.h"

#include <QTimer>
#include <QDebug>
#define RED 1           //红色
#define YELLOW 2         //黄色
#define BLUE 3          //蓝色
#define GREEN 4         //绿色
#define ORANGE 5        //橙色
#define PINK 6          //粉色
#define VIOLET 7        //紫色
Diamond::Diamond()
{

}

void Diamond::drawDiamond(QPainter *paint)
{
    paint->save();
    QBrush bru;
    bru.setStyle(Qt::SolidPattern);
    if(getDiamondColor()==RED)
        bru.setColor(Qt::red);
    else if(getDiamondColor()==YELLOW)
        bru.setColor(Qt::yellow);
    else if(getDiamondColor()==BLUE)
        bru.setColor(Qt::blue);
    else if(getDiamondColor()==GREEN)
        bru.setColor(Qt::green);
    else if(getDiamondColor()==ORANGE)
        bru.setColor(QColor(255, 140, 83));
    else if(getDiamondColor()==PINK)
        bru.setColor(QColor(255, 170, 204));
    else if(getDiamondColor()==VIOLET)
        bru.setColor(QColor(255,0,255));
    paint->setBrush(bru);
    paint->drawRect(QRect(xy1*40,QSize(40,40)));
    paint->drawRect(QRect(xy2*40,QSize(40,40)));
    paint->drawRect(QRect(xy3*40,QSize(40,40)));
    paint->drawRect(QRect(xy4*40,QSize(40,40)));
    paint->restore();
}

void Diamond::drawDiamond(QPainter *paint, int x, int y)
{
    paint->save();
    QBrush bru;
    bru.setStyle(Qt::SolidPattern);
    if(getDiamondColor()==RED)
        bru.setColor(Qt::red);
    else if(getDiamondColor()==YELLOW)
        bru.setColor(Qt::yellow);
    else if(getDiamondColor()==BLUE)
        bru.setColor(Qt::blue);
    else if(getDiamondColor()==GREEN)
        bru.setColor(Qt::green);
    else if(getDiamondColor()==ORANGE)
        bru.setColor(QColor(255, 140, 83));
    else if(getDiamondColor()==PINK)
        bru.setColor(QColor(255, 170, 204));
    else if(getDiamondColor()==VIOLET)
        bru.setColor(QColor(255,0,255));
    paint->setBrush(bru);
    paint->drawRect(QRect(xy1*40+QPoint(x,y),QSize(40,40)));
    paint->drawRect(QRect(xy2*40+QPoint(x,y),QSize(40,40)));
    paint->drawRect(QRect(xy3*40+QPoint(x,y),QSize(40,40)));
    paint->drawRect(QRect(xy4*40+QPoint(x,y),QSize(40,40)));
    paint->restore();
}

void Diamond::automoveDiamond()
{
    this->xy1.setY(xy1.y()+1);
    this->xy2.setY(xy2.y()+1);
    this->xy3.setY(xy3.y()+1);
    this->xy4.setY(xy4.y()+1);
    getBoundaty();
    //qDebug()<<xy1.y();
    //    if(xy1.x()>0&&xy1.y()>0)
    //    qDebug()<<widgeSize[xy1.x()][xy1.y()];
    qDebug()<<left<<right<<bottom;
    // qDebug()<<widgeSize[7][14]<<widgeSize[8][14]<<widgeSize[7][13]<<widgeSize[7][12];
}

void Diamond::moveDiamond(QKeyEvent *event)
{
    //this->getBoundaty();
    if(event->key()==Qt::Key_Left&&this->left>0)
    {
        if(this->crashleft()&&bottom>2)
            return;
        this->xy1.setX(xy1.x()-1);
        this->xy2.setX(xy2.x()-1);
        this->xy3.setX(xy3.x()-1);
        this->xy4.setX(xy4.x()-1);
    }
    if(event->key()==Qt::Key_Right&&right<14)
    {
        if(this->crashright()&&bottom>2)
            return ;
        this->xy1.setX((xy1.x()+1));
        this->xy2.setX((xy2.x()+1));
        this->xy3.setX((xy3.x()+1));
        this->xy4.setX((xy4.x()+1));
    }
    this->getBoundaty();
}

void Diamond::getBoundaty()
{
    left=xy1.x();right=xy1.x();bottom=xy1.y();
    if(left>xy1.x())
        left=xy1.x();
    if(left>xy2.x())
        left=xy2.x();
    if(left>xy3.x())
        left=xy3.x();
    if(left>xy4.x())
        left=xy4.x();

    if(right<xy1.x())
        right=xy1.x();
    if(right<xy2.x())
        right=xy2.x();
    if(right<xy3.x())
        right=xy3.x();
    if(right<xy4.x())
        right=xy4.x();

    if(bottom<xy1.y())
        bottom=xy1.y();
    if(bottom<xy2.y())
        bottom=xy2.y();
    if(bottom<xy3.y())
        bottom=xy3.y();
    if(bottom<xy4.y())
        bottom=xy4.y();

}

void Diamond::getdata(int **size)
{
    this->widgeSize =size;
}

bool Diamond::crashDiamond()
{
    if(this->bottom==14)
    {
        return true;
    }
    if(xy1.y()>-2)
    {
        if(widgeSize[xy1.x()][xy1.y()+1]!=-1)
            return true;
    }
    if(xy2.y()>-2)
    {
        if(widgeSize[xy2.x()][xy2.y()+1]!=-1)
            return true;
    }
    if(xy3.y()>-2)
    {
        if(widgeSize[xy3.x()][xy3.y()+1]!=-1)
            return true;
    }
    if(xy4.y()>-2)
    {
        if(widgeSize[xy4.x()][xy4.y()+1]!=-1)
            return true;
    }
    return false;
}

bool Diamond::crashleft()
{
    if(widgeSize[xy1.x()-1][xy1.y()]==-1&&widgeSize[xy2.x()-1][xy2.y()]==-1&&widgeSize[xy3.x()-1][xy3.y()]==-1&&widgeSize[xy4.x()-1][xy4.y()]==-1)
        return false;
    else
        return true;
}
bool Diamond::crashright()
{
    if(widgeSize[xy1.x()+1][xy1.y()]==-1&&widgeSize[xy2.x()+1][xy2.y()]==-1&&widgeSize[xy3.x()+1][xy3.y()]&&widgeSize[xy4.x()+1][xy4.y()]==-1)
        return false;
    else
        return true;
}

bool Diamond::isgamveOver()
{
    if(crashDiamond())
    {
        if(xy1.y()<=0||xy2.y()<=0||xy3.y()<=0||xy4.y()<=0)
        {
            return true;
        }
        else
            return false;
    }
}



//15*15
Diamond_L::Diamond_L()
{
    xy1=QPoint(7,-3);
    xy2=QPoint(7,-2);
    xy3=QPoint(7,-1);
    xy4=QPoint(8,-1);
    this->getBoundaty();
}

void Diamond_L::automoveDiamond()
{
    this->xy1.setY(xy1.y()+1);
    this->xy2.setY(xy2.y()+1);
    this->xy3.setY(xy3.y()+1);
    this->xy4.setY(xy4.y()+1);
    getBoundaty();
    //qDebug()<<xy1.y();
    //    if(xy1.x()>0&&xy1.y()>0)
    //    qDebug()<<widgeSize[xy1.x()][xy1.y()];
    qDebug()<<left<<right<<bottom;
    // qDebug()<<widgeSize[7][14]<<widgeSize[8][14]<<widgeSize[7][13]<<widgeSize[7][12];
}

//void Diamond_L::moveDiamond(QKeyEvent *event)
//{
//    if(event->key()==Qt::Key_Left&&this->left>0)
//    {
//        if(this->crashleft()&&bottom>2)
//            return;
//        this->xy1.setX(xy1.x()-1);
//        this->xy2.setX(xy2.x()-1);
//        this->xy3.setX(xy3.x()-1);
//        this->xy4.setX(xy4.x()-1);
//    }
//    else if(event->key()==Qt::Key_Right&&right<15)
//    {
//        if(this->crashright()&&bottom>2)
//            return ;
//        this->xy1.setX((xy1.x()+1));
//        this->xy2.setX((xy2.x()+1));
//        this->xy3.setX((xy3.x()+1));
//        this->xy4.setX((xy4.x()+1));
//    }
//    this->getBoundaty();
//}

int Diamond_L::getDiamondColor()
{
    return 5;
}

void Diamond_L::changeDiamond()
{
    if(state==1)
    {
        QPoint temp1(xy1.x()+1,xy1.y()+1);
        QPoint temp2(xy4.x()+1,xy4.y()-1);
        if(temp2.x()<=14&&(temp1.y()<1||temp2.y()<1||xy3.y()<1||xy4.y()<1))
        {
            xy1=temp1;
            xy4=temp2;
            state=2;
        }
        else if(temp2.x()<=14&& widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1)
        {
            xy1=temp1;
            xy4=temp2;
            state=2;
        }
        else
            return;
    }
    else if(state==2)
    {
        QPoint temp1(xy2.x()+1,xy2.y()-1);
        QPoint temp2(xy3.x(),xy3.y()-2);
        QPoint temp3(xy4.x()-1,xy4.y()+1);
        if(xy1.y()<1||temp1.y()<1||temp2.y()<1||temp3.y()<1)
        {
            xy2=temp1;
            xy3=temp2;
            xy4=temp3;
            state=3;
        }
        else if(widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1&&widgeSize[temp3.x()][temp3.y()]==-1)
        {
            xy2=temp1;
            xy3=temp2;
            xy4=temp3;
            state=3;

        }
        else
            return;
    }
    else if(state==3)
    {
        QPoint temp1(xy2.x()-1,xy2.y()+2);
        QPoint temp2(xy3.x()-1,xy3.y()+2);
        if(temp2.x()>=0&&(xy1.y()<1||temp1.y()<1||temp2.y()<1||xy4.y()<1))
        {
            xy2=temp1;
            xy3=temp2;
            state=4;

        }
        else if(temp2.x()>=0&& widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1)
        {
            xy2=temp1;
            xy3=temp2;
            state=4;

        }
        else
            return;
    }
    else if(state==4)
    {
        QPoint temp1(xy1.x()-1,xy1.y()-1);
        QPoint temp2(xy2.x(),xy2.y()-1);
        QPoint temp3(xy3.x()+1,xy3.y());
        if(temp1.y()<1||temp2.y()<1||temp3.y()<1||xy4.y()<1)
        {
            xy1=temp1;
            xy2=temp2;
            xy3=temp3;
            state=1;

        }
        else if(widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1&&widgeSize[temp3.x()][temp3.y()]==-1)
        {
            xy1=temp1;
            xy2=temp2;
            xy3=temp3;
            state=1;

        }
        else
            return;
    }
};


Diamond_J::Diamond_J()
{
    xy1=QPoint(8,-3);
    xy2=QPoint(8,-2);
    xy3=QPoint(8,-1);
    xy4=QPoint(7,-1);
    left=xy1.x();
    right=xy4.x();
    bottom=xy4.y();
}

int Diamond_J::getDiamondColor()
{
    return 6;
}

void Diamond_J::changeDiamond()
{
    if(state==1)
    {
        QPoint temp1(xy1.x()-1,xy1.y()+1);
        QPoint temp2(xy2.x()+1,xy2.y()+1);
        if(temp1.y()<1||temp2.y()<1||xy3.y()<1||xy4.y()<1)
        {
            xy1=temp1;
            xy2=temp2;
            state=2;
        }
        else if(temp2.x()<=14&&widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1)
        {
            xy1=temp1;
            xy2=temp2;
            state=2;
        }
        else
            return;
    }
    else if(state==2)
    {
        QPoint temp1(xy2.x()-2,xy2.y()-2);
        QPoint temp2(xy3.x(),xy3.y()-2);
        if(xy1.y()<1||xy2.y()<1||xy3.y()<1||xy4.y()<1)
        {
            xy2=temp1;
            xy3=temp2;
            state=3;

        }
        else if(widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1)
        {
            xy2=temp1;
            xy3=temp2;
            state=3;

        }
        else
            return;
    }
    else if(state==3)
    {
        QPoint temp1(xy2.x()+1,xy2.y()+1);
        QPoint temp2(xy3.x(),xy3.y()+2);
        QPoint temp3(xy4.x()-1,xy4.y()-1);
        if(temp3.x()>=0&&(xy1.y()<1||xy2.y()<1||xy3.y()<1||xy4.y()<1))
        {
            xy2=temp1;
            xy3=temp2;
            xy4=temp3;
            state=4;
        }
        else if(temp3.x()>=0&&widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1&&widgeSize[temp3.x()][temp3.y()]==-1)
        {
            xy2=temp1;
            xy3=temp2;
            xy4=temp3;
            state=4;
        }
    }
    else if(state==4)
    {
        QPoint temp1(xy1.x()+1,xy1.y()-1);
        QPoint temp2(xy4.x()+1,xy4.y()+1);
        if(xy1.y()<1||xy2.y()<1||xy3.y()<1||xy4.y()<1)
        {
            xy1=temp1;
            xy4=temp2;
            state=1;

        }
        else if(widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1)
        {
            xy1=temp1;
            xy4=temp2;
            state=1;

        }
    }
}

Diamond_I::Diamond_I()
{
    xy1=QPoint(8,-4);
    xy2=QPoint(8,-3);
    xy3=QPoint(8,-2);
    xy4=QPoint(8,-1);
    left=xy1.x();
    right=xy4.x();
    bottom=xy4.y();
}

int Diamond_I::getDiamondColor()
{
    return BLUE;
}

void Diamond_I::changeDiamond()
{
    if(state==1)
    {
        QPoint temp1(xy1.x()-1,xy1.y()+3);
        QPoint temp2(xy2.x()+1,xy2.y()+2);
        QPoint temp3(xy3.x()+2,xy3.y()+1);
        if(temp1.x()>=0&&temp3.y()<=14&& widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1&&widgeSize[temp3.x()][temp3.y()]==-1)
        {
            xy1=temp1;
            xy2=temp2;
            xy3=temp3;
            state=2;
        }
        else
            return;
    }
    else if(state==2)
    {
        QPoint temp1(xy1.x()+1,xy1.y()-3);
        QPoint temp2(xy2.x()-1,xy2.y()-2);
        QPoint temp3(xy3.x()-2,xy3.y()-1);
        if(temp1.y()<1||temp2.y()<1&&temp3.y()<1&&xy4.y()<1)
        {
            xy1=temp1;
            xy2=temp2;
            xy3=temp3;
            state=1;
        }
        else if(widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1&&widgeSize[temp3.x()][temp3.y()]==-1)
        {
            xy1=temp1;
            xy2=temp2;
            xy3=temp3;
            state=1;
        }
        else
            return;
    }
}

Diamond_T::Diamond_T()
{
    xy1=QPoint(6,-2);
    xy2=QPoint(7,-2);
    xy3=QPoint(8,-2);
    xy4=QPoint(7,-1);
    left=xy1.x();
    right=xy4.x();
    bottom=xy4.y();
}

int Diamond_T::getDiamondColor()
{
    return VIOLET;
}

void Diamond_T::changeDiamond()
{
    if(state==1)
    {
        QPoint temp1(xy3.x()-1,xy3.y()-1);
        if(xy1.y()<1||xy2.y()<1||xy3.y()<1||xy4.y()<1)
        {
            xy3=temp1;
            state=2;
        }
        else if(widgeSize[temp1.x()][temp1.y()]==-1)
        {
            xy3=temp1;
            state=2;
        }
        else
            return;
    }
    else if(state==2)
    {
        QPoint temp1(xy1.x(),xy1.y()+1);
        QPoint temp2(xy3.x()+1,xy3.y()+2);
          if(temp2.x()<=14&&(xy1.y()<1||xy2.y()<1||xy3.y()<1||xy4.y()<1))
          {
              xy1=temp1;
              xy3=temp2;
              state=3;
          }
          else if(temp2.x()<=14&& widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1)
          {
              xy1=temp1;
              xy3=temp2;
              state=3;
          }
          else
              return;

    }
    else if(state==3)
    {
        QPoint temp1(xy1.x()+1,xy1.y()-2);
        QPoint temp2(xy3.x(),xy3.y()-1);
        if(xy1.y()<1||xy2.y()<1||xy3.y()<1||xy4.y()<1)
        {
            xy1=temp1;
            xy3=temp2;
            state=4;
        }
        else if(widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1)
        {
            xy1=temp1;
            xy3=temp2;
            state=4;
        }
        else
            return;
    }
    else if(state==4)
    {
        QPoint temp1(xy1.x()-1,xy1.y()+1);
         if(xy1.y()<1||xy2.y()<1||xy3.y()<1||xy4.y()<1)
         {
             xy1=temp1;
             state=1;
         }
         else if(widgeSize[temp1.x()][temp1.y()]==-1)
         {
             xy1=temp1;
             state=1;
         }
         else
             return;
    }
}

Diamond_Z::Diamond_Z()
{
    xy1=QPoint(6,-2);
    xy2=QPoint(7,-2);
    xy3=QPoint(7,-1);
    xy4=QPoint(8,-1);
    left=xy1.x();
    right=xy4.x();
    bottom=xy4.y();
}

int Diamond_Z::getDiamondColor()
{
    return GREEN;
}

void Diamond_Z::changeDiamond()
{
    if(state==1)
    {
        QPoint temp1(xy1.x()+2,xy1.y()-1);
        QPoint temp2(xy4.x(),xy4.y()-1);
         if(xy1.y()<1||xy2.y()<1||xy3.y()<1||xy4.y()<1)
         {
             xy1=temp1;
             xy4=temp2;
             state=2;
         }
         else if(widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1)
         {
             xy1=temp1;
             xy4=temp2;
             state=2;
         }
         else
             return;

    }
    else if(state==2)
    {
        QPoint temp1(xy1.x()-2,xy1.y()+1);
        QPoint temp2(xy4.x(),xy4.y()+1);
         if(temp1.x()>=0&&( xy1.y()<1||xy2.y()<1||xy3.y()<1||xy4.y()<1))
         {
             xy1=temp1;
             xy4=temp2;
             state=1;
         }
         else if(temp1.x()>=0&&widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1)
         {
             xy1=temp1;
             xy4=temp2;
             state=1;
         }
         else
             return;
    }
}

Diamond_S::Diamond_S()
{
    xy1=QPoint(7,-2);
    xy2=QPoint(8,-2);
    xy3=QPoint(6,-1);
    xy4=QPoint(7,-1);
    left=xy1.x();
    right=xy4.x();
    bottom=xy4.y();
}

int Diamond_S::getDiamondColor()
{
    return RED;
}

void Diamond_S::changeDiamond()
{

    if(state==1)
    {
        QPoint temp1(xy3.x()+1,xy3.y()-2);
        QPoint temp2(xy4.x()+1,xy4.y());
         if(xy1.y()<1||xy2.y()<1||xy3.y()<1||xy4.y()<1)
         {
             xy3=temp1;
             xy4=temp2;
             state=2;
         }
         else if(widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1)
         {
             xy3=temp1;
             xy4=temp2;
             state=2;
         }
         else
             return;

    }
    else if(state==2)
    {
        QPoint temp1(xy3.x()-1,xy3.y()+2);
        QPoint temp2(xy4.x()-1,xy4.y());
         if(temp1.x()>=0&&( xy1.y()<1||xy2.y()<1||xy3.y()<1||xy4.y()<1))
         {
             xy3=temp1;
             xy4=temp2;
             state=1;
         }
         else if(temp1.x()>=0&&widgeSize[temp1.x()][temp1.y()]==-1&&widgeSize[temp2.x()][temp2.y()]==-1)
         {
             xy3=temp1;
             xy4=temp2;
             state=1;
         }
         else
             return;
    }
}

Diamond_O::Diamond_O()
{
    xy1=QPoint(7,-2);
    xy2=QPoint(8,-2);
    xy3=QPoint(7,-1);
    xy4=QPoint(8,-1);
    left=xy1.x();
    right=xy4.x();
    bottom=xy4.y();
}

int Diamond_O::getDiamondColor()
{
    return YELLOW;
}

void Diamond_O::changeDiamond()
{

}
