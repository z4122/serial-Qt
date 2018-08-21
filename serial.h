#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include "ui_serial.h"
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qwidget.h>
#include <QtWidgets\qmessagebox.h>
#include "cserialport.h"
#include <qfiledialog.h>
#include <qtextstream.h>
#include "string"


using namespace std;
class serial : public QMainWindow
{
	Q_OBJECT

public:
	serial(QWidget *parent = Q_NULLPTR);

private:
	Ui::serialClass ui;


private slots:
	void on_openSerialButton_clicked();
	void on_startButton_clicked();
	void on_stopButton_clicked();
	void on_locationButton_clicked();
	void serialBoxChange(int);
	
	void textShow(QString&);


signals:
	void serialStartWork();
	void serialStopWork();
	

};
