#include "serial.h"

serial::serial(QWidget *parent)
	: QMainWindow(parent)
{
	QPushButton *tpushButton;

	ui.setupUi(this);
	

	ui.serialComboBox->addItems(QStringList("串口1"));
	ui.serialComboBox->addItems(QStringList("串口2"));


	connect(ui.serialComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(serialBoxChange(int)));

	connect(setwindow.setui.setButton, SIGNAL(clicked()), this,SLOT(setParameter()));
	connect(setwindow.setui.readButton, SIGNAL(clicked()), this,SLOT(readParameter()));
	//ui.settingbar->addAction("设置参数", &setwindow, SLOT(show()));
	connect(ui.settingbar, SIGNAL(aboutToShow()), &setwindow, SLOT(show()));

	Graph_Init(ui.widget);
}



void serial::serialBoxChange(int index)
{
		QMessageBox::warning(this, "Message", ui.serialComboBox->itemText(index), QMessageBox::Ok);

}

void serial::on_openSerialButton_clicked() //打开串口按钮
{
	
	static int flag = 0;
	if (flag == 0)
	{	
		sthread = new SerialThread(NULL);
		connect(sthread, SIGNAL(catchError(const QString&)), this, SLOT(getError(const QString&)));
		connect(sthread, SIGNAL(serialContent(const QString&)), this, SLOT(processText(const QString&)));
		sthread->openPort(3);
		sthread->start();
		
		ui.openSerialButton->setText("关闭串口");		
		flag = 1;
	}
	else
	{
		sthread->serialport->~CSerialPort();

		sthread->requestInterruption();
		sthread->quit();
		sthread->wait();
		

		ui.openSerialButton->setText("打开串口");
		flag = 0;
	}
	
	
}



void serial::processText(const QString& input)
{
	string received = input.toStdString();
	int16_t val_1 = received[3] << 8 || received[4]; 
	int16_t val_2 = received[5] << 8 || received[6];
	int16_t val_3 = received[7] << 8 || received[8];

	switch(received[2])
	{
		case 0x01:
			setwindow.setui.lineEdit_1->setText(QString("%1").arg(val_1 / 1000.0));
			setwindow.setui.lineEdit_2->setText(QString("%1").arg(val_2 / 1000.0));
			setwindow.setui.lineEdit_3->setText(QString("%1").arg(val_3 / 1000.0));
			break;
		case 0x02:
			setwindow.setui.lineEdit_4->setText(QString("%1").arg(val_1 / 1000.0));
			setwindow.setui.lineEdit_5->setText(QString("%1").arg(val_2 / 1000.0));
			setwindow.setui.lineEdit_6->setText(QString("%1").arg(val_3 / 1000.0));
			break;
		case 0x03:
			setwindow.setui.lineEdit_7->setText(QString("%1").arg(val_1 / 1000.0));
			setwindow.setui.lineEdit_8->setText(QString("%1").arg(val_2 / 1000.0));
			setwindow.setui.lineEdit_9->setText(QString("%1").arg(val_3 / 1000.0));
			break;
		case 0x04:
			setwindow.setui.lineEdit_10->setText(QString("%1").arg(val_1 / 1000.0));
			setwindow.setui.lineEdit_11->setText(QString("%1").arg(val_2 / 1000.0));
			setwindow.setui.lineEdit_12->setText(QString("%1").arg(val_3 / 1000.0));
			break;
		case 0x05:
			setwindow.setui.lineEdit_13->setText(QString("%1").arg(val_1 / 1000.0));
			setwindow.setui.lineEdit_14->setText(QString("%1").arg(val_2 / 1000.0));
			setwindow.setui.lineEdit_15->setText(QString("%1").arg(val_3 / 1000.0));
			break;
		default:
			ui.serialText->append(input);
			Graph_Show(ui.widget, received);
			break;		
	}	
}

void serial::getError(const QString & input)//通过这种方法在主界面生成消息提示框
{
	
}

void serial::on_startButton_clicked()
{
	sthread->sendCommand(command::startRecord);

}

void serial::on_stopButton_clicked()
{
	sthread->sendCommand(command::stopRecord);

}

void serial::readParameter()
{
	sthread->sendCommand(command::getParameter);
}

void serial::setParameter()
{
	float parameter[3];

	parameter[0] = QString2Float(setwindow.setui.lineEdit_1->text());
	parameter[1] = QString2Float(setwindow.setui.lineEdit_2->text());
	parameter[2] = QString2Float(setwindow.setui.lineEdit_3->text());
	sthread->sendParameter(parameter, 1);
	
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
	
}

/**
	QString转为float输出，为了方便串口传输，放大了1000倍
	@输入参数:QString input
	@输出参数:float output
*/
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
		QMessageBox::warning(this, "错误", "打开文件失败");
		return;
	}
	else
	{
		QTextStream textStream(&file);
		QString str = ui.serialText->toPlainText();
		textStream << str;
		QMessageBox::warning(this, "提示", "保存文件成功");
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
	//设置画布颜色
	//QLinearGradient plotGradient;
	//lotGradient.setStart(0, 0);
	//plotGradient.setFinalStop(0, 350);
	//plotGradient.setColorAt(0, QColor(80, 80, 80));
	//plotGradient.setColorAt(1, QColor(50, 50, 50));
	//ui.widget->setBackground(plotGradient);

	//设置坐标颜色/坐标名称颜色
	//ui.widget->xAxis->setLabelColor(Qt::white);//文字颜色
	//ui.widget->yAxis->setLabelColor(Qt::white);
	//ui.widget->xAxis->setTickLabelColor(Qt::white);//坐标轴数字颜色
	//ui.widget->yAxis->setTickLabelColor(Qt::white);
	//ui.widget->xAxis->setBasePen(QPen(Qt::white, 1));//坐标轴颜色及宽度
	//ui.widget->yAxis->setBasePen(QPen(Qt::white, 1));
	//ui.widget->xAxis->setTickPen(QPen(Qt::white, 1));//主刻度
	//ui.widget->yAxis->setTickPen(QPen(Qt::white, 1));
	//ui.widget->xAxis->setSubTickPen(QPen(Qt::white, 1));//副刻度
	//ui.widget->yAxis->setSubTickPen(QPen(Qt::white, 1));

	CustomPlot->graph(0)->setData(temp, temp1); //输出各点的图像，x和y都是QVector类
	CustomPlot->replot();//重绘

}


void serial::Graph_Init(QCustomPlot *CustomPlot)
{
	//设置属性可缩放，移动等
	ui.widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
		QCP::iSelectLegend | QCP::iSelectPlottables);
	CustomPlot->addGraph();//添加一条曲线
	CustomPlot->graph(0)->setPen(QPen(Qt::red)); //0是曲线序号，添加的第一条是0，设置曲线颜色
	CustomPlot->xAxis->setLabel("序列");//x轴的文字
	CustomPlot->yAxis->setLabel("压力值");//y轴的文字

	CustomPlot->xAxis->setRange(0, 100);//x轴范围
	CustomPlot->yAxis->setRange(0, 100);//y轴范围
}