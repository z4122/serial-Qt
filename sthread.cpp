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
	//emit catchError(QString::fromStdString("串口打开错误"));
	if (!serialport.InitPort(3))
	{
		emit catchError(QString::fromStdString("串口打开错误"));
		return;
	}

	
	
	char cRecved = 0x00;
	int n = 10;
	while (1)
	{
		while (n--)
			if (serialport.ReadChar(cRecved) == true)
			{
				if ((cRecved >= 48) && (cRecved <= 57))
					str += cRecved;
			}
		n = 10;
		emit serialContent((const QString)QString::fromStdString(str));
		str.clear();
		sleep(1);
		//this->ui.pushButton->setText(QApplication::translate("serialClass", &cRecved, Q_NULLPTR));
	}
	
}
