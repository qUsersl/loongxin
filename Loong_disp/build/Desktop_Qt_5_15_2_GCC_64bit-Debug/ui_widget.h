/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *outPutEdit;
    QSpacerItem *verticalSpacer;
    QTextEdit *inputEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;
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
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_time;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1137, 735);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(14);
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 0, 1, 1, 1);

        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 0, 7, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 233, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 4, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        outPutEdit = new QTextEdit(Widget);
        outPutEdit->setObjectName(QString::fromUtf8("outPutEdit"));
        outPutEdit->setMinimumSize(QSize(330, 400));

        verticalLayout_5->addWidget(outPutEdit);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        inputEdit = new QTextEdit(Widget);
        inputEdit->setObjectName(QString::fromUtf8("inputEdit"));
        inputEdit->setMinimumSize(QSize(0, 100));
        inputEdit->setMaximumSize(QSize(16777215, 150));

        verticalLayout_5->addWidget(inputEdit);


        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_6->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_6, 1, 7, 3, 2);

        horizontalSpacer_4 = new QSpacerItem(62, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        node1Bt = new QPushButton(Widget);
        node1Bt->setObjectName(QString::fromUtf8("node1Bt"));
        node1Bt->setMinimumSize(QSize(100, 100));
        node1Bt->setStyleSheet(QString::fromUtf8("border-image: url(:/node_pic.png);"));

        verticalLayout->addWidget(node1Bt);

        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(13);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        node2Bt = new QPushButton(Widget);
        node2Bt->setObjectName(QString::fromUtf8("node2Bt"));
        node2Bt->setMinimumSize(QSize(100, 100));
        node2Bt->setStyleSheet(QString::fromUtf8("border-image: url(:/node_pic.png);"));

        verticalLayout_2->addWidget(node2Bt);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        node3Bt = new QPushButton(Widget);
        node3Bt->setObjectName(QString::fromUtf8("node3Bt"));
        node3Bt->setMinimumSize(QSize(100, 100));
        node3Bt->setStyleSheet(QString::fromUtf8("border-image: url(:/node_pic.png);"));

        verticalLayout_3->addWidget(node3Bt);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        setBt = new QPushButton(Widget);
        setBt->setObjectName(QString::fromUtf8("setBt"));
        setBt->setMinimumSize(QSize(100, 100));
        setBt->setStyleSheet(QString::fromUtf8("border-image: url(:/set.png);"));

        verticalLayout_4->addWidget(setBt);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_4);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 5);

        horizontalSpacer_5 = new QSpacerItem(62, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 6, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 232, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 3, 5, 2, 1);

        verticalSpacer_4 = new QSpacerItem(20, 52, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 4, 8, 1, 1);

        verticalSpacer_5 = new QSpacerItem(106, 236, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 3, 2, 1, 1);

        label_time = new QLabel(Widget);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        QFont font2;
        font2.setPointSize(15);
        label_time->setFont(font2);
        label_time->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));

        gridLayout->addWidget(label_time, 0, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\344\270\273\347\225\214\351\235\242", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\346\227\266\351\227\264\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "AI\345\257\271\350\257\235\346\241\206", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        node1Bt->setText(QString());
        label->setText(QCoreApplication::translate("Widget", "Node1", nullptr));
        node2Bt->setText(QString());
        label_2->setText(QCoreApplication::translate("Widget", "Node2", nullptr));
        node3Bt->setText(QString());
        label_3->setText(QCoreApplication::translate("Widget", "Node3", nullptr));
        setBt->setText(QString());
        label_4->setText(QCoreApplication::translate("Widget", "Set", nullptr));
        label_time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
