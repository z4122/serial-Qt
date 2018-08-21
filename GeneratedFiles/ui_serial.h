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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serialClass
{
public:
    QWidget *centralWidget;
    QPushButton *openSerialButton;
    QToolButton *toolButton;
    QRadioButton *radioButton;
    QComboBox *serialComboBox;
    QPushButton *startButton;
    QTextEdit *serialText;
    QPushButton *locationButton;
    QPushButton *stopButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *serialClass)
    {
        if (serialClass->objectName().isEmpty())
            serialClass->setObjectName(QStringLiteral("serialClass"));
        serialClass->resize(600, 400);
        centralWidget = new QWidget(serialClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openSerialButton = new QPushButton(centralWidget);
        openSerialButton->setObjectName(QStringLiteral("openSerialButton"));
        openSerialButton->setGeometry(QRect(110, 280, 75, 23));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(110, 110, 37, 17));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(50, 190, 89, 15));
        serialComboBox = new QComboBox(centralWidget);
        serialComboBox->setObjectName(QStringLiteral("serialComboBox"));
        serialComboBox->setGeometry(QRect(20, 280, 69, 22));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(350, 300, 75, 23));
        serialText = new QTextEdit(centralWidget);
        serialText->setObjectName(QStringLiteral("serialText"));
        serialText->setGeometry(QRect(220, 0, 371, 281));
        serialText->setReadOnly(false);
        locationButton = new QPushButton(centralWidget);
        locationButton->setObjectName(QStringLiteral("locationButton"));
        locationButton->setGeometry(QRect(240, 300, 75, 23));
        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(460, 300, 75, 23));
        serialClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(serialClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        serialClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(serialClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        serialClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(serialClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        serialClass->setStatusBar(statusBar);

        retranslateUi(serialClass);

        QMetaObject::connectSlotsByName(serialClass);
    } // setupUi

    void retranslateUi(QMainWindow *serialClass)
    {
        serialClass->setWindowTitle(QApplication::translate("serialClass", "serial", Q_NULLPTR));
        openSerialButton->setText(QApplication::translate("serialClass", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        toolButton->setText(QApplication::translate("serialClass", "...", Q_NULLPTR));
        radioButton->setText(QApplication::translate("serialClass", "RadioButton", Q_NULLPTR));
        startButton->setText(QApplication::translate("serialClass", "\345\274\200\345\247\213\350\256\260\345\275\225", Q_NULLPTR));
        locationButton->setText(QApplication::translate("serialClass", "\351\200\211\346\213\251\344\277\235\345\255\230\344\275\215\347\275\256", Q_NULLPTR));
        stopButton->setText(QApplication::translate("serialClass", "\345\201\234\346\255\242\350\256\260\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class serialClass: public Ui_serialClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_H
