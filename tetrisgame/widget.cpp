#include "widget.h"
#include "ui_widget.h"
#include <QAction>
#include <QMenu>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    level(1000),
   // game(new GameWidge),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->move(600,200);
    //添加等级选项
    QAction *ac1=new QAction("等级一",this);
    QAction *ac2=new QAction("等级二",this);
    QAction *ac3=new QAction("等级三",this);
    QMenu *men=new QMenu(this);
    men->addAction(ac1);
    men->addAction(ac2);
    men->addAction(ac3);
    ui->levelbtn->setMenu(men);
    //连接等级选项
    connect(ac1,&QAction::triggered,this,[=](){level=300;this->on_startbtn_clicked();});
    connect(ac2,&QAction::triggered,this,[=](){level=200;this->on_startbtn_clicked();});
    connect(ac3,&QAction::triggered,this,[=](){level=100;this->on_startbtn_clicked();});

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startbtn_clicked()
{
    game=new GameWidge;
    connect(this,&Widget::startgame,game,&GameWidge::startgame);
    connect(game,&GameWidge::gameOver,this,[=](){this->show();delete game;});
    this->hide();
    emit startgame(level,this->geometry().topLeft());
    this->close();
}

void Widget::on_levelbtn_clicked()
{
    ui->levelbtn->showMenu();
    emit startgame(level,this->geometry().topLeft());
    this->hide();
}

void Widget::on_exitbtn_clicked()
{
    this->close();
}
