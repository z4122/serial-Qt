#include "serial.h"

serial::serial(QWidget *parent)
	: QMainWindow(parent)
{
	QPushButton *tpushButton;

	ui.setupUi(this);
	

	ui.serialComboBox->addItems(QStringList("����1"));
	ui.serialComboBox->addItems(QStringList("����2"));

	
	connect(ui.serialComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(serialBoxChange(int)));

	connect(setwindow.setui.setButton, SIGNAL(clicked()), this,SLOT(setParameter()));
	connect(setwindow.setui.readButton, SIGNAL(clicked()), this,SLOT(readParameter()));
	//ui.settingbar->addAction("���ò���", &setwindow, SLOT(show()));
	connect(ui.settingbar, SIGNAL(aboutToShow()), &setwindow, SLOT(show()));
}



void serial::serialBoxChange(int index)
{
		QMessageBox::warning(this, "Message", ui.serialComboBox->itemText(index), QMessageBox::Ok);

}

void serial::on_openSerialButton_clicked() //�򿪴��ڰ�ť
{
	
	static int flag = 0;
	if (flag == 0)
	{	
		sthread = new SerialThread(NULL);
		sthread->openPort(3);
		sthread->serialport->~CSerialPort();

		delete sthread;
		sthread = NULL;
		ui.openSerialButton->setText("�رմ���");		
		flag = 1;
	}
	else
	{
		sthread->requestInterruption();
		sthread->quit();
		sthread->wait();

		ui.openSerialButton->setText("�򿪴���");
		flag = 0;
	}
	
	
}

void serial::on_startButton_clicked()
{
	sthread = new SerialThread(NULL);
	connect(sthread, SIGNAL(catchError(const QString&)), this, SLOT(getError(const QString&)));
	connect(sthread, SIGNAL(serialContent(const QString&)), this, SLOT(textShow(const QString&)));
	sthread->openPort(3);
	

	sthread->start();
}
void serial::on_stopButton_clicked()
{
	sthread->requestInterruption();
	sthread->quit();
	sthread->wait();
	sthread->serialport->~CSerialPort();
}

void serial::textShow(const QString& input)
{
	ui.serialText->append(input);
	Graph_Show(ui.widget,input.toStdString());
}

void serial::getError(const QString & input)//ͨ�����ַ�����������������Ϣ��ʾ��
{
	
}

void serial::readParameter()
{

}

void serial::setParameter()
{
	float parameter[3];

	parameter[0] = QString2Float(setwindow.setui.lineEdit_1->text());
	parameter[1] = QString2Float(setwindow.setui.lineEdit_2->text());
	parameter[2] = QString2Float(setwindow.setui.lineEdit_3->text());
	sthread->sendParameter(parameter, 1);
	
	/*
	parameter[0] = QString2Float(setwindow.setui.lineEdit_4->text());
	parameter[1] = QString2Float(setwindow.setui.lineEdit_5->text());
	parameter[2] = QString2Float(setwindow.setui.lineEdit_6->text());
	sthread->sendParameter(parameter, 2);

	parameter[0] = QString2Float(setwindow.setui.lineEdit_7->text());
	parameter[1] = QString2Float(setwindow.setui.lineEdit_8->text());
	parameter[2] = QString2Float(setwindow.setui.lineEdit_9->text());
	sthread->sendParameter(parameter, 3);

	parameter[0] = QString2Float(setwindow.setui.lineEdit_10->text());
	parameter[1] = QString2Float(setwindow.setui.lineEdit_11->text());
	parameter[2] = QString2Float(setwindow.setui.lineEdit_12->text());
	sthread->sendParameter(parameter, 4);

	parameter[0] = QString2Float(setwindow.setui.lineEdit_13->text());
	parameter[1] = QString2Float(setwindow.setui.lineEdit_14->text());
	parameter[2] = QString2Float(setwindow.setui.lineEdit_15->text());
	sthread->sendParameter(parameter, 5);
	*/
}

float serial::QString2Float(QString input)
{
	return stof(input.toStdString())*1000;
}


void serial::on_locationButton_clicked()
{
	QFileDialog fileDialog;

	QString fileName = fileDialog.getSaveFileName(this, "Open File", "D://serialtest", "Text File(*.txt)");

	if (fileName == "")
		return;

	QFile file(fileName);

	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QMessageBox::warning(this, "����", "���ļ�ʧ��");
		return;
	}
	else
	{
		QTextStream textStream(&file);
		QString str = ui.serialText->toPlainText();
		textStream << str;
		QMessageBox::warning(this, "��ʾ", "�����ļ��ɹ�");
		file.close();
	}


}


void serial::Graph_Show(QCustomPlot *CustomPlot,const string data )
{
	static QVector<double> temp(100);
	static QVector<double> temp1(100);

	for (int i = 0; i<100; i++)
	{
		temp[i] = i;
	}
	for (int i = 0; i<100-data.size(); i++)
	{
		temp1[i] = temp1[i+data.size()];
	}
	for (int i = 100-data.size()+1; i < 100; i++)
	{
		temp1[i] = (data[i - (100 - data.size())]-'0')*10;
	}
	//���û�����ɫ
	QLinearGradient plotGradient;
	//lotGradient.setStart(0, 0);
	//plotGradient.setFinalStop(0, 350);
	//plotGradient.setColorAt(0, QColor(80, 80, 80));
	//plotGradient.setColorAt(1, QColor(50, 50, 50));
	//ui.widget->setBackground(plotGradient);

	//����������ɫ/����������ɫ
	//ui.widget->xAxis->setLabelColor(Qt::white);//������ɫ
	//ui.widget->yAxis->setLabelColor(Qt::white);
	//ui.widget->xAxis->setTickLabelColor(Qt::white);//������������ɫ
	//ui.widget->yAxis->setTickLabelColor(Qt::white);
	//ui.widget->xAxis->setBasePen(QPen(Qt::white, 1));//��������ɫ�����
	//ui.widget->yAxis->setBasePen(QPen(Qt::white, 1));
	//ui.widget->xAxis->setTickPen(QPen(Qt::white, 1));//���̶�
	//ui.widget->yAxis->setTickPen(QPen(Qt::white, 1));
	//ui.widget->xAxis->setSubTickPen(QPen(Qt::white, 1));//���̶�
	//ui.widget->yAxis->setSubTickPen(QPen(Qt::white, 1));


	//�������Կ����ţ��ƶ���
	ui.widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
		QCP::iSelectLegend | QCP::iSelectPlottables);
	CustomPlot->addGraph();//���һ������
	CustomPlot->graph(0)->setPen(QPen(Qt::red)); //0��������ţ���ӵĵ�һ����0������������ɫ
	CustomPlot->graph(0)->setData(temp, temp1); //��������ͼ��x��y����QVector��

	CustomPlot->xAxis->setLabel("����");//x�������
	CustomPlot->yAxis->setLabel("ѹ��ֵ");//y�������

	CustomPlot->xAxis->setRange(0, 100);//x�᷶Χ
	CustomPlot->yAxis->setRange(0, 100);//y�᷶Χ
	CustomPlot->replot();//�ػ�

}