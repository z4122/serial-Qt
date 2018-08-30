/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingClass
{
public:
    QWidget *centralwidget;
    QPushButton *readButton;
    QPushButton *setButton;
    QWidget *verticalLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_3;
    QLabel *label_9;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_10;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_9;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_15;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_14;
    QMenuBar *menubar;

    void setupUi(QMainWindow *settingClass)
    {
        if (settingClass->objectName().isEmpty())
            settingClass->setObjectName(QStringLiteral("settingClass"));
        settingClass->resize(343, 260);
        centralwidget = new QWidget(settingClass);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setToolTipDuration(-1);
        centralwidget->setAutoFillBackground(false);
        readButton = new QPushButton(centralwidget);
        readButton->setObjectName(QStringLiteral("readButton"));
        readButton->setGeometry(QRect(110, 190, 75, 23));
        setButton = new QPushButton(centralwidget);
        setButton->setObjectName(QStringLiteral("setButton"));
        setButton->setGeometry(QRect(200, 190, 75, 23));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 20, 231, 161));
        gridLayout = new QGridLayout(verticalLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_4 = new QLineEdit(verticalLayoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 4, 1, 1, 1);

        lineEdit_5 = new QLineEdit(verticalLayoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 4, 2, 1, 1);

        lineEdit_1 = new QLineEdit(verticalLayoutWidget);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));

        gridLayout->addWidget(lineEdit_1, 2, 1, 1, 1);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 3, 1, 1);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 0, 3, 1, 1);

        lineEdit_7 = new QLineEdit(verticalLayoutWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 6, 1, 1, 1);

        lineEdit_13 = new QLineEdit(verticalLayoutWidget);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));

        gridLayout->addWidget(lineEdit_13, 12, 1, 1, 1);

        lineEdit_10 = new QLineEdit(verticalLayoutWidget);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout->addWidget(lineEdit_10, 9, 1, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 2, 2, 1, 1);

        lineEdit_9 = new QLineEdit(verticalLayoutWidget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout->addWidget(lineEdit_9, 6, 3, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFocusPolicy(Qt::NoFocus);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 1, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 12, 0, 1, 1);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 9, 0, 1, 1);

        lineEdit_15 = new QLineEdit(verticalLayoutWidget);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));

        gridLayout->addWidget(lineEdit_15, 12, 3, 1, 1);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 2, 1, 1);

        lineEdit_6 = new QLineEdit(verticalLayoutWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 4, 3, 1, 1);

        lineEdit_12 = new QLineEdit(verticalLayoutWidget);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        gridLayout->addWidget(lineEdit_12, 9, 3, 1, 1);

        lineEdit_8 = new QLineEdit(verticalLayoutWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 6, 2, 1, 1);

        lineEdit_11 = new QLineEdit(verticalLayoutWidget);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        gridLayout->addWidget(lineEdit_11, 9, 2, 1, 1);

        lineEdit_14 = new QLineEdit(verticalLayoutWidget);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));

        gridLayout->addWidget(lineEdit_14, 12, 2, 1, 1);

        settingClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(settingClass);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 343, 23));
        settingClass->setMenuBar(menubar);

        retranslateUi(settingClass);

        QMetaObject::connectSlotsByName(settingClass);
    } // setupUi

    void retranslateUi(QMainWindow *settingClass)
    {
        settingClass->setWindowTitle(QApplication::translate("settingClass", "MainWindow", Q_NULLPTR));
        readButton->setText(QApplication::translate("settingClass", "\350\257\273\345\217\226\345\217\202\346\225\260", Q_NULLPTR));
        setButton->setText(QApplication::translate("settingClass", "\350\256\276\347\275\256\345\217\202\346\225\260", Q_NULLPTR));
        label_9->setText(QApplication::translate("settingClass", "\351\230\210\345\200\274", Q_NULLPTR));
        label->setText(QApplication::translate("settingClass", "\351\200\232\351\201\2231", Q_NULLPTR));
        label_2->setText(QApplication::translate("settingClass", "\351\200\232\351\201\2232", Q_NULLPTR));
        label_3->setText(QApplication::translate("settingClass", "\351\200\232\351\201\2233", Q_NULLPTR));
        label_7->setText(QApplication::translate("settingClass", "\345\217\202\346\225\260a", Q_NULLPTR));
        label_4->setText(QApplication::translate("settingClass", "\351\200\232\351\201\2235", Q_NULLPTR));
        label_5->setText(QApplication::translate("settingClass", "\351\200\232\351\201\2234", Q_NULLPTR));
        label_8->setText(QApplication::translate("settingClass", "\345\217\202\346\225\260b", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class settingClass: public Ui_settingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
