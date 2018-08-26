#pragma once
#include <QObject>
#include <QDebug>

class Receiver : public QObject
{
	Q_OBJECT

public:
	int totalCallCount() const { return m_totalCallCount; }

	void slot1(int a, double b, const QString &c) {
		qDebug() << __func__ << a << b << c;
		++m_totalCallCount;
	}
	void slot2(double a, int b, QString c) {
		qDebug() << __func__ << a << b << c;
		++m_totalCallCount;
	}
	void slot3(int a) {
		qDebug() << __func__ << a;
		++m_totalCallCount;
	}
	void slot4() {
		qDebug() << __func__;
		++m_totalCallCount;
	}

	int rslot1(int a, double b, const QString &c) {
		qDebug() << __func__ << a << b << c;
		++m_totalCallCount;
		return 0;
	}
	int rslot2(double a, int b, QString c) {
		qDebug() << __func__ << a << b << c;
		++m_totalCallCount;
		return 0;
	}
	int rslot3(int a) {
		qDebug() << __func__ << a;
		++m_totalCallCount;
		return 0;
	}
	int rslot4() {
		qDebug() << __func__;
		++m_totalCallCount;
		return 0;
	}

private:
	int m_totalCallCount = 0;
};
