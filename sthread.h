#pragma once

#include <QObject>
#include "qobject.h"
#include "cserialport.h"
#include "qmessagebox.h"
#include "qstring.h"
#include "qsignaltransition.h"
#include "string"

using namespace std;
class SerialThread : public QObject
{
	Q_OBJECT

public:
	SerialThread(QObject* parent = NULL);
	~SerialThread();
	

public slots:
	void readContent();

signals:

	void catchError(QString&);
	void serialContent(QString&);
};
