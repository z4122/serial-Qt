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
		emit catchError(QString::fromStdString("���ڴ򿪴���"));
		return;
	}

}

/**
	��λ����Ƭ�����������Ƭ�����ز�����
	@�������:parameter
	@�������:
*/
void SerialThread::getParameter()
{
	uint8_t buffer[10];
	uint16_t temp = 0;
	uint8_t sum = 0;

	buffer[0] = 0x00;
	buffer[1] = 0x00;
	buffer[2] = 0x0A;

	buffer[3] = 0xff;
	buffer[4] = 0xff;
	buffer[5] = 0xff;
	buffer[6] = 0xff;
	buffer[7] = 0xff;
	buffer[8] = 0xff;

	for (int i = 2; i<9; ++i)
		temp += buffer[i];//У���

	buffer[9] = temp;

	if (!serialport->WriteData(buffer, 10))
		emit catchError("����ʧ�ܣ�������");
}


/**
	��λ����Ƭ�����Ͳ���
	@�������:parameter
	@�������:
*/
void SerialThread::sendParameter(float * pData, unsigned int index)
{
	uint8_t buffer[10];
	uint16_t temp = 0;
	uint8_t sum = 0;

	buffer[0] = 0x00;
	buffer[1] = 0x00;
	buffer[2] = index;

	buffer[3] = (int16_t)pData[0] & 0xff;
	buffer[4] = (int16_t)pData[0] >> 8;
	buffer[5] = (int16_t)pData[1] & 0xff;
	buffer[6] = (int16_t)pData[1] >> 8;
	buffer[7] = (int16_t)pData[2] & 0xff;
	buffer[8] = (int16_t)pData[2] >> 8;

	for (int i = 2; i<9; ++i)
		temp += buffer[i];//У���

	buffer[9] = temp;

	if (!serialport->WriteData(buffer, 10))
		emit catchError("����ʧ�ܣ�������");
}

/**
	��λ���õ���Ƭ�����͵��ַ����߳�����ģʽ��
	@�������:parameter
	@�������:
*/
void SerialThread::run()
{

	string str;
	uint8_t temp= 0;
	char cRecved = 0x00;
	int n = 1;
	while (1)
	{
		if (serialport->ReadChar(cRecved) == true)
		{
			if (n > 2&&n < 10) {
				str += cRecved;
				++n;
				continue;
			}
			if (cRecved == 0x00 && n == 1) {
				++n;
				continue;
			}
			if (cRecved == 0x00 && n == 2) {
				++n;
				continue;
			}
			if (n == 10) {
				for (auto val : str)
					temp += val;
				if(temp==cRecved)
					emit serialContent((const QString)QString::fromStdString(str));
				str.clear();
				n = 1;
				continue;
			}			
			n = 1;//��ֹ�������룬������������¼�������������²���ִ�е���һ�С�
		}
		
	}
	
}
