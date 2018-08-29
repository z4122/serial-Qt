#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_setting.h"
//#include "cserialport.h"

class settingwindow : public QMainWindow
{
	Q_OBJECT

public:
	settingwindow(QWidget *parent = Q_NULLPTR);
	~settingwindow();

public:
	Ui::settingClass setui;


};

