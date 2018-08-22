#include "sthread.h"


SerialThread::SerialThread(QObject* parent):QThread(parent)
{

}

SerialThread::~SerialThread()
{

}

void SerialThread::openPort(UINT portNum)
{
	serialport = new CSerialPort();
	if (!serialport->InitPort(3))
	{
		emit catchError(QString::fromStdString("´®¿Ú´ò¿ª´íÎó"));
		return;
	}

}


void SerialThread::run()
{

	string str;
	
	
	
	
	char cRecved = 0x00;
	int n = 10;
	while (!QThread::currentThread()->isInterruptionRequested())
	{
			while (n--)
			{
				if (serialport->ReadChar(cRecved) == true)
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
			}
			emit serialContent((const QString)QString::fromStdString(str));
			str.clear();
			n = 10;

		
		//this->ui.pushButton->setText(QApplication::translate("serialClass", &cRecved, Q_NULLPTR));
	}
	
}
