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
#include "sthread.h"
#include "qthread.h"
#include "qcustomplot.h"
#include "settingwindow.h"


using namespace std;
class serial : public QMainWindow
{
	Q_OBJECT



public:
	serial(QWidget *parent = Q_NULLPTR);
	void Graph_Show(QCustomPlot *, const string);

	void Graph_Init(QCustomPlot * CustomPlot);


private:
	Ui::serialClass ui;
	settingwindow setwindow;
	SerialThread *sthread;

public slots:
	void on_openSerialButton_clicked();
	void on_startButton_clicked();
	void on_stopButton_clicked();
	void on_locationButton_clicked();
	void serialBoxChange(int);
	
	void processText(const QString&);
	void getError(const QString&);

	void readParameter();
	void setParameter();

	float QString2Float(QString input);


signals:
	void serialStartWork();




};
