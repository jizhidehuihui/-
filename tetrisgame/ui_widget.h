/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *startbtn;
    QPushButton *levelbtn;
    QPushButton *exitbtn;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        Widget->setStyleSheet(QStringLiteral("background-color: rgb(115, 210, 22);"));
        startbtn = new QPushButton(Widget);
        startbtn->setObjectName(QStringLiteral("startbtn"));
        startbtn->setGeometry(QRect(360, 210, 89, 25));
        startbtn->setStyleSheet(QLatin1String("background-color: rgb(204, 0, 0);\n"
"background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));\n"
"QPushButton press:\n"
"{\n"
"background-color: rgb(119, 32, 32);\n"
"}\n"
""));
        levelbtn = new QPushButton(Widget);
        levelbtn->setObjectName(QStringLiteral("levelbtn"));
        levelbtn->setGeometry(QRect(360, 270, 89, 25));
        levelbtn->setContextMenuPolicy(Qt::ActionsContextMenu);
        levelbtn->setStyleSheet(QLatin1String("background-color: rgb(204, 0, 0);\n"
"background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));\n"
"QPushButton press:\n"
"{\n"
"background-color: rgb(119, 32, 32);\n"
"}\n"
""));
        exitbtn = new QPushButton(Widget);
        exitbtn->setObjectName(QStringLiteral("exitbtn"));
        exitbtn->setGeometry(QRect(360, 330, 89, 25));
        exitbtn->setStyleSheet(QLatin1String("background-color: rgb(204, 0, 0);\n"
"background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));\n"
"QPushButton press:\n"
"{\n"
"background-color: rgb(119, 32, 32);\n"
"}\n"
""));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(690, 570, 101, 17));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        startbtn->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\346\270\270\346\210\217", Q_NULLPTR));
        levelbtn->setText(QApplication::translate("Widget", "\351\200\211\346\213\251\347\255\211\347\272\247", Q_NULLPTR));
        exitbtn->setText(QApplication::translate("Widget", "\351\200\200\345\207\272\346\270\270\346\210\217", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "by:\346\234\272\345\210\266\347\232\204\351\230\277\350\276\211", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
