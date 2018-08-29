/********************************************************************************
** Form generated from reading UI file 'serial.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAL_H
#define UI_SERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_serialClass
{
public:
    QWidget *centralWidget;
    QPushButton *openSerialButton;
    QComboBox *serialComboBox;
    QPushButton *startButton;
    QTextEdit *serialText;
    QPushButton *locationButton;
    QPushButton *stopButton;
    QCustomPlot *widget;
    QMenuBar *menuBar;
    QMenu *choosingbar;
    QMenu *settingbar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *serialClass)
    {
        if (serialClass->objectName().isEmpty())
            serialClass->setObjectName(QStringLiteral("serialClass"));
        serialClass->resize(586, 403);
        centralWidget = new QWidget(serialClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openSerialButton = new QPushButton(centralWidget);
        openSerialButton->setObjectName(QStringLiteral("openSerialButton"));
        openSerialButton->setGeometry(QRect(110, 300, 75, 23));
        serialComboBox = new QComboBox(centralWidget);
        serialComboBox->setObjectName(QStringLiteral("serialComboBox"));
        serialComboBox->setGeometry(QRect(10, 300, 69, 22));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(370, 300, 75, 23));
        serialText = new QTextEdit(centralWidget);
        serialText->setObjectName(QStringLiteral("serialText"));
        serialText->setGeometry(QRect(450, 10, 131, 261));
        serialText->setReadOnly(false);
        locationButton = new QPushButton(centralWidget);
        locationButton->setObjectName(QStringLiteral("locationButton"));
        locationButton->setGeometry(QRect(240, 300, 101, 23));
        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(470, 300, 75, 23));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 421, 261));
        serialClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(serialClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 586, 23));
        choosingbar = new QMenu(menuBar);
        choosingbar->setObjectName(QStringLiteral("choosingbar"));
        settingbar = new QMenu(menuBar);
        settingbar->setObjectName(QStringLiteral("settingbar"));
        settingbar->setEnabled(true);
        settingbar->setMouseTracking(true);
        settingbar->setTearOffEnabled(false);
        serialClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(serialClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        serialClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(serialClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        serialClass->setStatusBar(statusBar);

        menuBar->addAction(choosingbar->menuAction());
        menuBar->addAction(settingbar->menuAction());

        retranslateUi(serialClass);

        QMetaObject::connectSlotsByName(serialClass);
    } // setupUi

    void retranslateUi(QMainWindow *serialClass)
    {
        serialClass->setWindowTitle(QApplication::translate("serialClass", "serial", Q_NULLPTR));
        openSerialButton->setText(QApplication::translate("serialClass", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        startButton->setText(QApplication::translate("serialClass", "\345\274\200\345\247\213\350\256\260\345\275\225", Q_NULLPTR));
        locationButton->setText(QApplication::translate("serialClass", "\351\200\211\346\213\251\344\277\235\345\255\230\344\275\215\347\275\256", Q_NULLPTR));
        stopButton->setText(QApplication::translate("serialClass", "\345\201\234\346\255\242\350\256\260\345\275\225", Q_NULLPTR));
        choosingbar->setTitle(QApplication::translate("serialClass", "\351\200\211\346\213\251\344\270\262\345\217\243", Q_NULLPTR));
        settingbar->setTitle(QApplication::translate("serialClass", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class serialClass: public Ui_serialClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_H
