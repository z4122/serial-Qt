#include "sthread.h"


SerialThread::SerialThread(QObject *parent) :QObject(parent)
{

}

SerialThread::~SerialThread()
{

}


void SerialThread::readContent()
{
	CSerialPort serialport;
	string str;

	if (!serialport.InitPort(3))
	{
		emit catchError(QString::fromStdString("´®¿Ú´ò¿ª´íÎó"));
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
		emit serialContent(QString::fromStdString(str));
		//this->ui.pushButton->setText(QApplication::translate("serialClass", &cRecved, Q_NULLPTR));
	}
}
