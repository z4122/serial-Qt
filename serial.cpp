#include "serial.h"

serial::serial(QWidget *parent)
	: QMainWindow(parent)
{
	QPushButton *tpushButton;

	ui.setupUi(this);


	ui.serialComboBox->addItems(QStringList("����1"));
	ui.serialComboBox->addItems(QStringList("����2"));

	sthread = new SerialThread();

	connect(ui.serialComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(serialBoxChange(int)));

	connect(sthread, SIGNAL(catchError(const QString&)), this, SLOT(getError(const QString&)));

	connect(sthread, SIGNAL(serialContent(const QString&)), this, SLOT(textShow(const QString&)));

	
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
		sthread->start();
		ui.openSerialButton->setText("�رմ���");		
		flag = 1;
	}
	else
	{
		sthread->quit();
		sthread->wait();
		ui.openSerialButton->setText("�򿪴���");
		flag = 0;
	}
	
	
}



void serial::textShow(const QString& input)
{
	ui.serialText->append(input);
	Graph_Show(ui.widget,input[0]);
}

void serial::getError(const QString & input)//ͨ�����ַ�����������������Ϣ��ʾ��
{
	QMessageBox::warning(this, "����",input);
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


void serial::Graph_Show(QCustomPlot *CustomPlot,const QChar data )
{
	QVector<double> temp(100);
	QVector<double> temp1(100);

	srand((unsigned)time(NULL));//����һ���������
	for (int i = 0; i<100; i++)
	{
		temp[i] = i;
	}
	for (int i = 0; i<99; i++)
	{
		temp1[i] = temp[i+1];
	}
	temp1[99] = data.unicode()-'0';
	//���û�����ɫ
	QLinearGradient plotGradient;
	//lotGradient.setStart(0, 0);
	//plotGradient.setFinalStop(0, 350);
	//plotGradient.setColorAt(0, QColor(80, 80, 80));
	plotGradient.setColorAt(1, QColor(50, 50, 50));
	ui.widget->setBackground(plotGradient);

	//����������ɫ/����������ɫ
	ui.widget->xAxis->setLabelColor(Qt::white);//������ɫ
	ui.widget->yAxis->setLabelColor(Qt::white);
	ui.widget->xAxis->setTickLabelColor(Qt::white);//������������ɫ
	ui.widget->yAxis->setTickLabelColor(Qt::white);
	ui.widget->xAxis->setBasePen(QPen(Qt::white, 1));//��������ɫ�����
	ui.widget->yAxis->setBasePen(QPen(Qt::white, 1));
	ui.widget->xAxis->setTickPen(QPen(Qt::white, 1));//���̶�
	ui.widget->yAxis->setTickPen(QPen(Qt::white, 1));
	ui.widget->xAxis->setSubTickPen(QPen(Qt::white, 1));//���̶�
	ui.widget->yAxis->setSubTickPen(QPen(Qt::white, 1));


	//�������Կ����ţ��ƶ���
	ui.widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
		QCP::iSelectLegend | QCP::iSelectPlottables);
	CustomPlot->addGraph();//���һ������
	CustomPlot->graph(0)->setPen(QPen(Qt::green)); //0��������ţ���ӵĵ�һ����0������������ɫ
	CustomPlot->graph(0)->setData(temp, temp1); //��������ͼ��x��y����QVector��

	CustomPlot->xAxis->setLabel("x");//x�������
	CustomPlot->yAxis->setLabel("y");//y�������

	CustomPlot->xAxis->setRange(0, 100);//x�᷶Χ
	CustomPlot->yAxis->setRange(-100, 200);//y�᷶Χ
	CustomPlot->replot();//�ػ�

}