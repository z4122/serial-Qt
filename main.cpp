#include "serial.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	serial w;
	w.show();
	return a.exec();
}
