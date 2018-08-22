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

		ui.openSerialButton->setText("�򿪴���");
		flag = 0;
	}
	
	
}



void serial::textShow(const QString& input)
{
	ui.serialText->append(input);
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
