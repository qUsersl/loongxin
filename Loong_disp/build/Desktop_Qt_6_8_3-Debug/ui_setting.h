/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setting
{
public:
    QPushButton *backButton;
    QLabel *label_time;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_tempMax;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_tempMin;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_humiMax;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_humiMin;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_lightMax;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_lightMin;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_smogMax;

    void setupUi(QWidget *setting)
    {
        if (setting->objectName().isEmpty())
            setting->setObjectName("setting");
        setting->resize(925, 627);
        backButton = new QPushButton(setting);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(70, 60, 61, 71));
        backButton->setMinimumSize(QSize(0, 70));
        backButton->setStyleSheet(QString::fromUtf8("border-image: url(:/back.png);"));
        label_time = new QLabel(setting);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(150, 40, 231, 31));
        layoutWidget = new QWidget(setting);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(196, 141, 471, 321));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);

        horizontalLayout_10->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_10);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        doubleSpinBox_tempMax = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_tempMax->setObjectName("doubleSpinBox_tempMax");
        doubleSpinBox_tempMax->setMinimumSize(QSize(90, 0));
        doubleSpinBox_tempMax->setValue(50.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox_tempMax);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        doubleSpinBox_tempMin = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_tempMin->setObjectName("doubleSpinBox_tempMin");
        doubleSpinBox_tempMin->setMinimumSize(QSize(90, 0));
        doubleSpinBox_tempMin->setValue(10.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_tempMin);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_8->addLayout(verticalLayout);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        doubleSpinBox_humiMax = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_humiMax->setObjectName("doubleSpinBox_humiMax");
        doubleSpinBox_humiMax->setMinimumSize(QSize(90, 0));
        doubleSpinBox_humiMax->setValue(80.000000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_humiMax);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        doubleSpinBox_humiMin = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_humiMin->setObjectName("doubleSpinBox_humiMin");
        doubleSpinBox_humiMin->setMinimumSize(QSize(90, 0));
        doubleSpinBox_humiMin->setValue(10.000000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_humiMin);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_8->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        doubleSpinBox_lightMax = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_lightMax->setObjectName("doubleSpinBox_lightMax");
        doubleSpinBox_lightMax->setMinimumSize(QSize(90, 0));
        doubleSpinBox_lightMax->setMaximum(1000.000000000000000);
        doubleSpinBox_lightMax->setValue(1000.000000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox_lightMax);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_6->addWidget(label_7);

        doubleSpinBox_lightMin = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_lightMin->setObjectName("doubleSpinBox_lightMin");
        doubleSpinBox_lightMin->setMinimumSize(QSize(90, 0));
        doubleSpinBox_lightMin->setMaximum(1000.000000000000000);
        doubleSpinBox_lightMin->setValue(10.000000000000000);

        horizontalLayout_6->addWidget(doubleSpinBox_lightMin);


        verticalLayout_3->addLayout(horizontalLayout_6);


        horizontalLayout_9->addLayout(verticalLayout_3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        horizontalLayout_7->addWidget(label_8);

        doubleSpinBox_smogMax = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_smogMax->setObjectName("doubleSpinBox_smogMax");
        doubleSpinBox_smogMax->setMinimumSize(QSize(90, 0));
        doubleSpinBox_smogMax->setMaximum(1000.000000000000000);
        doubleSpinBox_smogMax->setValue(800.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_smogMax);


        horizontalLayout_9->addLayout(horizontalLayout_7);


        verticalLayout_4->addLayout(horizontalLayout_9);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(setting);

        QMetaObject::connectSlotsByName(setting);
    } // setupUi

    void retranslateUi(QWidget *setting)
    {
        setting->setWindowTitle(QCoreApplication::translate("setting", "\350\256\276\347\275\256", nullptr));
        backButton->setText(QString());
        label_time->setText(QString());
        label->setText(QCoreApplication::translate("setting", "\346\212\245\350\255\246\345\200\274\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("setting", "\346\270\251\345\272\246\344\270\212\351\231\220\345\200\274", nullptr));
        label_3->setText(QCoreApplication::translate("setting", "\346\270\251\345\272\246\344\270\213\351\231\220\345\200\274", nullptr));
        label_4->setText(QCoreApplication::translate("setting", "\346\271\277\345\272\246\344\270\212\351\231\220\345\200\274", nullptr));
        label_5->setText(QCoreApplication::translate("setting", "\346\271\277\345\272\246\344\270\213\351\231\220\345\200\274", nullptr));
        label_6->setText(QCoreApplication::translate("setting", "\345\205\211\347\205\247\344\270\212\351\231\220\345\200\274", nullptr));
        label_7->setText(QCoreApplication::translate("setting", "\345\205\211\347\205\247\344\270\213\351\231\220\345\200\274", nullptr));
        label_8->setText(QCoreApplication::translate("setting", "\347\203\237\351\233\276\346\212\245\350\255\246\345\200\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setting: public Ui_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
