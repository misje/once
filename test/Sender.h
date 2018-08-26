#pragma once
#include <QObject>

class Sender : public QObject
{
	Q_OBJECT

signals:
	void signal(int a, double b, const QString &c);
	void signal1(int a, double b, const QString &c);
	void signal2(double a, int b, QString c);
	void signal3(int a);
	void signal4();
	void nonCopySignal(const QObject &o);
	void delayedSignal();

public:
	void emitSignal(int a = 1, double b = 2.3, const QString &c = "c")
	{
		emit signal(a, b, c);
	}

	void emitNonCopySignal()
	{
		QObject o;
		o.setObjectName("Non-copyable object");
		emit nonCopySignal(o);
	}
};
