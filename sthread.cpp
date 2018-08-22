#include "sthread.h"


SerialThread::SerialThread(QObject* parent):QThread(parent)
{

}

SerialThread::~SerialThread()
{

}


void SerialThread::run()
{
	CSerialPort serialport;
	string str;
	//emit catchError(QString::fromStdString("���ڴ򿪴���"));
	if (!serialport.InitPort(3))
	{
		emit catchError(QString::fromStdString("���ڴ򿪴���"));
		return;
	}

	
	
	char cRecved = 0x00;

	while (1)
	{
		if (serialport.ReadChar(cRecved) == true)
		{
			if ((cRecved >= 48) && (cRecved <= 57))
				str += cRecved;
			else
				continue;
		}
		else
		{
			continue;
		}
		emit serialContent((const QString)QString::fromStdString(str));
		str.clear();
		//this->ui.pushButton->setText(QApplication::translate("serialClass", &cRecved, Q_NULLPTR));
	}
	
}
