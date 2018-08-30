#include "settingwindow.h"



settingwindow::settingwindow(QWidget* parent)
	:QMainWindow(parent)
{
	setui.setupUi(this);
	setLineEditOrder();

}


settingwindow::~settingwindow()
{
}

void settingwindow::setLineEditOrder()
{
	setTabOrder(setui.lineEdit_1, setui.lineEdit_2);
	setTabOrder(setui.lineEdit_2, setui.lineEdit_3);
	setTabOrder(setui.lineEdit_3, setui.lineEdit_4);
	setTabOrder(setui.lineEdit_4, setui.lineEdit_5);
	setTabOrder(setui.lineEdit_5, setui.lineEdit_6);
	setTabOrder(setui.lineEdit_6, setui.lineEdit_7);
	setTabOrder(setui.lineEdit_7, setui.lineEdit_8);
	setTabOrder(setui.lineEdit_8, setui.lineEdit_9);
	setTabOrder(setui.lineEdit_9, setui.lineEdit_10);
	setTabOrder(setui.lineEdit_10, setui.lineEdit_11);
	setTabOrder(setui.lineEdit_11, setui.lineEdit_12);
	setTabOrder(setui.lineEdit_12, setui.lineEdit_13);
	setTabOrder(setui.lineEdit_13, setui.lineEdit_14);
	setTabOrder(setui.lineEdit_14, setui.lineEdit_15);
}
