#include "serial.h"

serial::serial(QWidget *parent)
	: QMainWindow(parent)
{
	QPushButton *tpushButton;

	ui.setupUi(this);
	tpushButton = new QPushButton(ui.centralWidget);
		
	tpushButton->setGeometry(QRect(30, 80, 85, 33));
	tpushButton->setObjectName(QStringLiteral("test"));
	tpushButton->setText(QApplication::translate("serialClass", "test", Q_NULLPTR));

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

		ui.openSerialButton->setText("打开串口");
		flag = 0;
	}
	
	
}



void serial::textShow(const QString& input)
{
	ui.serialText->append(input);
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
