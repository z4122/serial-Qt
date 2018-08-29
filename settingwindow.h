#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_setting.h"


class settingwindow : public QMainWindow
{
	Q_OBJECT

public:
	settingwindow(QWidget *parent = Q_NULLPTR);
	~settingwindow();

private:
	Ui::settingClass* setui;
};

