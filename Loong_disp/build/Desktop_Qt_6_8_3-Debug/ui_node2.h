/********************************************************************************
** Form generated from reading UI file 'node2.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODE2_H
#define UI_NODE2_H

#include <QtCharts/QChartView>
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

class Ui_node2
{
public:
    QGridLayout *gridLayout;
    QPushButton *back_2Button;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_time;
    QPushButton *pushButton_data;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *temperature2Button;
    QSpacerItem *horizontalSpacer;
    QPushButton *humi_2Button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *light_2Button;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *smog_2Button;
    QChartView *graphicsView;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEdit_log;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextEdit *textEdit_temp;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QTextEdit *textEdit_humi;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QTextEdit *textEdit_light;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QTextEdit *textEdit_smog;

    void setupUi(QWidget *node2)
    {
        if (node2->objectName().isEmpty())
            node2->setObjectName("node2");
        node2->resize(1197, 698);
        node2->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 245, 244);"));
        gridLayout = new QGridLayout(node2);
        gridLayout->setObjectName("gridLayout");
        back_2Button = new QPushButton(node2);
        back_2Button->setObjectName("back_2Button");
        back_2Button->setMinimumSize(QSize(70, 70));
        back_2Button->setStyleSheet(QString::fromUtf8("border-image: url(:/back.png);"));

        gridLayout->addWidget(back_2Button, 0, 0, 2, 1);

        horizontalSpacer_4 = new QSpacerItem(364, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_time = new QLabel(node2);
        label_time->setObjectName("label_time");
        label_time->setMinimumSize(QSize(250, 0));
        QFont font;
        font.setPointSize(15);
        label_time->setFont(font);
        label_time->setStyleSheet(QString::fromUtf8("color: rgb(28, 113, 216);"));
        label_time->setTextFormat(Qt::AutoText);
        label_time->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_time);

        pushButton_data = new QPushButton(node2);
        pushButton_data->setObjectName("pushButton_data");

        verticalLayout_7->addWidget(pushButton_data);


        gridLayout->addLayout(verticalLayout_7, 0, 3, 2, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        temperature2Button = new QPushButton(node2);
        temperature2Button->setObjectName("temperature2Button");
        temperature2Button->setMinimumSize(QSize(85, 62));
        temperature2Button->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 97, 81);"));

        horizontalLayout_3->addWidget(temperature2Button);

        horizontalSpacer = new QSpacerItem(18, 18, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        humi_2Button = new QPushButton(node2);
        humi_2Button->setObjectName("humi_2Button");
        humi_2Button->setMinimumSize(QSize(85, 62));
        humi_2Button->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));

        horizontalLayout_3->addWidget(humi_2Button);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        light_2Button = new QPushButton(node2);
        light_2Button->setObjectName("light_2Button");
        light_2Button->setMinimumSize(QSize(85, 62));
        light_2Button->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 240, 107);"));

        horizontalLayout_3->addWidget(light_2Button);

        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        smog_2Button = new QPushButton(node2);
        smog_2Button->setObjectName("smog_2Button");
        smog_2Button->setMinimumSize(QSize(85, 62));
        smog_2Button->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));

        horizontalLayout_3->addWidget(smog_2Button);


        verticalLayout_6->addLayout(horizontalLayout_3);

        graphicsView = new QChartView(node2);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setMinimumSize(QSize(450, 450));

        verticalLayout_6->addWidget(graphicsView);


        gridLayout->addLayout(verticalLayout_6, 1, 4, 3, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(node2);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        textEdit_log = new QTextEdit(node2);
        textEdit_log->setObjectName("textEdit_log");
        textEdit_log->setReadOnly(true);

        verticalLayout->addWidget(textEdit_log);


        gridLayout->addLayout(verticalLayout, 2, 0, 2, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(node2);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 41));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/temp1_img.png);"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        textEdit_temp = new QTextEdit(node2);
        textEdit_temp->setObjectName("textEdit_temp");
        textEdit_temp->setReadOnly(true);

        verticalLayout_2->addWidget(textEdit_temp);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(node2);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 41));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/humi1_image.png);"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        textEdit_humi = new QTextEdit(node2);
        textEdit_humi->setObjectName("textEdit_humi");
        textEdit_humi->setReadOnly(true);

        verticalLayout_3->addWidget(textEdit_humi);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 2, 2, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(node2);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(0, 41));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/light1_img.png);"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        textEdit_light = new QTextEdit(node2);
        textEdit_light->setObjectName("textEdit_light");
        textEdit_light->setReadOnly(true);

        verticalLayout_4->addWidget(textEdit_light);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_5 = new QLabel(node2);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(0, 41));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/smog1_img.png);"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_5);

        textEdit_smog = new QTextEdit(node2);
        textEdit_smog->setObjectName("textEdit_smog");
        textEdit_smog->setReadOnly(true);

        verticalLayout_5->addWidget(textEdit_smog);


        horizontalLayout_2->addLayout(verticalLayout_5);


        gridLayout->addLayout(horizontalLayout_2, 3, 2, 1, 2);


        retranslateUi(node2);

        QMetaObject::connectSlotsByName(node2);
    } // setupUi

    void retranslateUi(QWidget *node2)
    {
        node2->setWindowTitle(QCoreApplication::translate("node2", "\350\212\202\347\202\271\344\272\214", nullptr));
        back_2Button->setText(QString());
        label_time->setText(QString());
        pushButton_data->setText(QCoreApplication::translate("node2", "\346\225\260\346\215\256\345\257\274\345\207\272", nullptr));
        temperature2Button->setText(QCoreApplication::translate("node2", "\346\270\251\345\272\246\346\233\262\347\272\277", nullptr));
        humi_2Button->setText(QCoreApplication::translate("node2", "\346\271\277\345\272\246\346\233\262\347\272\277", nullptr));
        light_2Button->setText(QCoreApplication::translate("node2", "\345\205\211\347\205\247\346\233\262\347\272\277", nullptr));
        smog_2Button->setText(QCoreApplication::translate("node2", "\347\203\237\351\233\276\346\233\262\347\272\277", nullptr));
        label->setText(QCoreApplication::translate("node2", "\350\212\202\347\202\271\346\227\245\345\277\227", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class node2: public Ui_node2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODE2_H
