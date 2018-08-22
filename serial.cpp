#include "serial.h"

serial::serial(QWidget *parent)
	: QMainWindow(parent)
{
	QPushButton *tpushButton;

	ui.setupUi(this);


	ui.serialComboBox->addItems(QStringList("串口1"));
	ui.serialComboBox->addItems(QStringList("串口2"));

	sthread = new SerialThread();

	connect(ui.serialComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(serialBoxChange(int)));

	connect(sthread, SIGNAL(catchError(const QString&)), this, SLOT(getError(const QString&)));

	connect(sthread, SIGNAL(serialContent(const QString&)), this, SLOT(textShow(const QString&)));

	
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
		sthread->start();
		ui.openSerialButton->setText("关闭串口");		
		flag = 1;
	}
	else
	{
		sthread->quit();
		sthread->wait();
		ui.openSerialButton->setText("打开串口");
		flag = 0;
	}
	
	
}



void serial::textShow(const QString& input)
{
	ui.serialText->append(input);
	Graph_Show(ui.widget,input[0]);
}

void serial::getError(const QString & input)//通过这种方法在主界面生成消息提示框
{
	QMessageBox::warning(this, "错误",input);
}

void serial::on_startButton_clicked()
{

}
void serial::on_stopButton_clicked()
{

}

void serial::on_locationButton_clicked()
{
	QFileDialog fileDialog;

	QString fileName = fileDialog.getSaveFileName(this, "Open File", "/home", "Text File(*.txt)");

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


void serial::Graph_Show(QCustomPlot *CustomPlot,const QChar data )
{
	QVector<double> temp(100);
	QVector<double> temp1(100);

	srand((unsigned)time(NULL));//设置一个随机函数
	for (int i = 0; i<100; i++)
	{
		temp[i] = i;
	}
	for (int i = 0; i<99; i++)
	{
		temp1[i] = temp[i+1];
	}
	temp1[99] = data.unicode()-'0';
	//设置画布颜色
	QLinearGradient plotGradient;
	//lotGradient.setStart(0, 0);
	//plotGradient.setFinalStop(0, 350);
	//plotGradient.setColorAt(0, QColor(80, 80, 80));
	plotGradient.setColorAt(1, QColor(50, 50, 50));
	ui.widget->setBackground(plotGradient);

	//设置坐标颜色/坐标名称颜色
	ui.widget->xAxis->setLabelColor(Qt::white);//文字颜色
	ui.widget->yAxis->setLabelColor(Qt::white);
	ui.widget->xAxis->setTickLabelColor(Qt::white);//坐标轴数字颜色
	ui.widget->yAxis->setTickLabelColor(Qt::white);
	ui.widget->xAxis->setBasePen(QPen(Qt::white, 1));//坐标轴颜色及宽度
	ui.widget->yAxis->setBasePen(QPen(Qt::white, 1));
	ui.widget->xAxis->setTickPen(QPen(Qt::white, 1));//主刻度
	ui.widget->yAxis->setTickPen(QPen(Qt::white, 1));
	ui.widget->xAxis->setSubTickPen(QPen(Qt::white, 1));//副刻度
	ui.widget->yAxis->setSubTickPen(QPen(Qt::white, 1));


	//设置属性可缩放，移动等
	ui.widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
		QCP::iSelectLegend | QCP::iSelectPlottables);
	CustomPlot->addGraph();//添加一条曲线
	CustomPlot->graph(0)->setPen(QPen(Qt::green)); //0是曲线序号，添加的第一条是0，设置曲线颜色
	CustomPlot->graph(0)->setData(temp, temp1); //输出各点的图像，x和y都是QVector类

	CustomPlot->xAxis->setLabel("x");//x轴的文字
	CustomPlot->yAxis->setLabel("y");//y轴的文字

	CustomPlot->xAxis->setRange(0, 100);//x轴范围
	CustomPlot->yAxis->setRange(-100, 200);//y轴范围
	CustomPlot->replot();//重绘

}