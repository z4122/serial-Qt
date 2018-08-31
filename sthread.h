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


/**
	ËÄ¸öÃüÁî£º
	setParameter,getParameter,startRecord,stopRecord.
*/
enum command {
	setParameter = 0x01,
	getParameter = 0x02,
	startRecord = 0x03,
	stopRecord = 0x04
};

class SerialThread : public QThread
{
	Q_OBJECT

public:
	SerialThread(QObject *parent = 0);
	~SerialThread();
	CSerialPort *serialport;
	void openPort(UINT);
	void getParameter();
	void sendParameter(float* pData, unsigned int index);
	void sendCommand(command);

protected:
	void run();

signals:
	void catchError(const QString&);
	void serialContent(const QString&);


	

};
