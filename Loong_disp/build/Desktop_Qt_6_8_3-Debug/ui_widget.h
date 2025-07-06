/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_5;
    QLabel *label_time;
    QTextEdit *outPutEdit;
    QTextEdit *inputEdit;
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *node1Bt;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *node2Bt;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *node3Bt;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *setBt;
    QLabel *label_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1147, 679);
        label_5 = new QLabel(Widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(410, 0, 57, 28));
        QFont font;
        font.setPointSize(14);
        label_5->setFont(font);
        label_time = new QLabel(Widget);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(476, 9, 201, 24));
        QFont font1;
        font1.setPointSize(15);
        label_time->setFont(font1);
        label_time->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        outPutEdit = new QTextEdit(Widget);
        outPutEdit->setObjectName("outPutEdit");
        outPutEdit->setGeometry(QRect(740, 200, 331, 221));
        inputEdit = new QTextEdit(Widget);
        inputEdit->setObjectName("inputEdit");
        inputEdit->setGeometry(QRect(740, 440, 331, 101));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(970, 560, 88, 26));
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 310, 621, 141));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        node1Bt = new QPushButton(widget);
        node1Bt->setObjectName("node1Bt");
        node1Bt->setMinimumSize(QSize(100, 100));
        node1Bt->setStyleSheet(QString::fromUtf8("border-image: url(:/node_pic.png);"));

        verticalLayout->addWidget(node1Bt);

        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(13);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        node2Bt = new QPushButton(widget);
        node2Bt->setObjectName("node2Bt");
        node2Bt->setMinimumSize(QSize(100, 100));
        node2Bt->setStyleSheet(QString::fromUtf8("border-image: url(:/node_pic.png);"));

        verticalLayout_2->addWidget(node2Bt);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        node3Bt = new QPushButton(widget);
        node3Bt->setObjectName("node3Bt");
        node3Bt->setMinimumSize(QSize(100, 100));
        node3Bt->setStyleSheet(QString::fromUtf8("border-image: url(:/node_pic.png);"));

        verticalLayout_3->addWidget(node3Bt);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        setBt = new QPushButton(widget);
        setBt->setObjectName("setBt");
        setBt->setMinimumSize(QSize(100, 100));
        setBt->setStyleSheet(QString::fromUtf8("border-image: url(:/set.png);"));

        verticalLayout_4->addWidget(setBt);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_4);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\344\270\273\347\225\214\351\235\242", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\346\227\266\351\227\264\357\274\232", nullptr));
        label_time->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        node1Bt->setText(QString());
        label->setText(QCoreApplication::translate("Widget", "Node1", nullptr));
        node2Bt->setText(QString());
        label_2->setText(QCoreApplication::translate("Widget", "Node2", nullptr));
        node3Bt->setText(QString());
        label_3->setText(QCoreApplication::translate("Widget", "Node3", nullptr));
        setBt->setText(QString());
        label_4->setText(QCoreApplication::translate("Widget", "Set", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
