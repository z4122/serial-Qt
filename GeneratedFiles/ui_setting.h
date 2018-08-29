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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingClass
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;

    void setupUi(QMainWindow *settingClass)
    {
        if (settingClass->objectName().isEmpty())
            settingClass->setObjectName(QStringLiteral("settingClass"));
        settingClass->resize(409, 289);
        centralwidget = new QWidget(settingClass);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        settingClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(settingClass);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 409, 23));
        settingClass->setMenuBar(menubar);

        retranslateUi(settingClass);

        QMetaObject::connectSlotsByName(settingClass);
    } // setupUi

    void retranslateUi(QMainWindow *settingClass)
    {
        settingClass->setWindowTitle(QApplication::translate("settingClass", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class settingClass: public Ui_settingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
