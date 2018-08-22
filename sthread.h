#pragma once
#pragma execution_character_set("utf-8")

#include <QObject>
#include "qobject.h"
#include "cserialport.h"
#include "qmessagebox.h"
#include "qstring.h"
#include "qsignaltransition.h"
#include "string"
#include "qthread.h"
#include "qtimer.h"

using namespace std;
class SerialThread : public QThread
{
	Q_OBJECT

public:
	SerialThread(QObject *parent = 0);
	~SerialThread();
	CSerialPort *serialport;
	void openPort(UINT);

protected:
	void run();

signals:
	void catchError(const QString&);
	void serialContent(const QString&);


	

};
