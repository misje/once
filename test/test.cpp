#include <QCoreApplication>
#include "once.h"
#include <QTimer>
#include <QDebug>
#include "Sender.h"
#include "Receiver.h"
#include <functional>
#include <QDebug>
#include <unordered_map>
#include <vector>


struct Test
{
	std::function<void(void)> runFunc;
	std::function<bool(void)> checkResult;
	const char *name;
};

static std::unordered_map<std::string, int> callCounts;
static std::vector<Test> tests;

static void staticFunc4Arg(int a, double b, const QString &c)
{
	qDebug() << __func__ << a << b << c; 
	callCounts[__func__]++;
}
static void staticFunc3Arg(double a, int b, QString c)
{
	qDebug() << __func__ << a << b << c;
	callCounts[__func__]++;
}
static void staticFunc1Arg(int a)
{
	qDebug() << __func__ << a;
	callCounts[__func__]++;
}
static void staticFunc0Arg()
{
	qDebug() << __func__;
	callCounts[__func__]++;
}

static void staticFunc4ArgContext(int a, double b, const QString &c)
{
	qDebug() << __func__ << a << b << c; 
	callCounts[__func__]++;
}
static void staticFunc3ArgContext(double a, int b, QString c)
{
	qDebug() << __func__ << a << b << c;
	callCounts[__func__]++;
}
static void staticFunc1ArgContext(int a)
{
	qDebug() << __func__ << a;
	callCounts[__func__]++;
}
static void staticFunc0ArgContext()
{
	qDebug() << __func__;
	callCounts[__func__]++;
}

static void staticFunc4ArgQueued(int a, double b, const QString &c)
{
	qDebug() << __func__ << a << b << c; 
	callCounts[__func__]++;
}
static void staticFunc3ArgQueued(double a, int b, QString c)
{
	qDebug() << __func__ << a << b << c;
	callCounts[__func__]++;
}
static void staticFunc1ArgQueued(int a)
{
	qDebug() << __func__ << a;
	callCounts[__func__]++;
}
static void staticFunc0ArgQueued()
{
	qDebug() << __func__;
	callCounts[__func__]++;
}

static void staticFunc4ArgCount(int a, double b, const QString &c)
{
	qDebug() << __func__ << a << b << c; 
	callCounts[__func__]++;
}
static void staticFunc3ArgCount(double a, int b, QString c)
{
	qDebug() << __func__ << a << b << c;
	callCounts[__func__]++;
}
static void staticFunc1ArgCount(int a)
{
	qDebug() << __func__ << a;
	callCounts[__func__]++;
}
static void staticFunc0ArgCount()
{
	qDebug() << __func__;
	callCounts[__func__]++;
}

static void staticFunc4ArgContextCount(int a, double b, const QString &c)
{
	qDebug() << __func__ << a << b << c; 
	callCounts[__func__]++;
}
static void staticFunc3ArgContextCount(double a, int b, QString c)
{
	qDebug() << __func__ << a << b << c;
	callCounts[__func__]++;
}
static void staticFunc1ArgContextCount(int a)
{
	qDebug() << __func__ << a;
	callCounts[__func__]++;
}
static void staticFunc0ArgContextCount()
{
	qDebug() << __func__;
	callCounts[__func__]++;
}

static void staticFunc4ArgQueuedCount(int a, double b, const QString &c)
{
	qDebug() << __func__ << a << b << c; 
	callCounts[__func__]++;
}
static void staticFunc3ArgQueuedCount(double a, int b, QString c)
{
	qDebug() << __func__ << a << b << c;
	callCounts[__func__]++;
}
static void staticFunc1ArgQueuedCount(int a)
{
	qDebug() << __func__ << a;
	callCounts[__func__]++;
}
static void staticFunc0ArgQueuedCount()
{
	qDebug() << __func__;
	callCounts[__func__]++;
}

static int staticFunc4ArgRet(int a, double b, const QString &c)
{
	qDebug() << __func__ << a << b << c; 
	callCounts[__func__]++;
	return 0;
}
static int staticFunc3ArgRet(double a, int b, QString c)
{
	qDebug() << __func__ << a << b << c;
	callCounts[__func__]++;
	return 0;
}
static int staticFunc1ArgRet(int a)
{
	qDebug() << __func__ << a;
	callCounts[__func__]++;
	return 0;
}
static int staticFunc0ArgRet()
{
	qDebug() << __func__;
	callCounts[__func__]++;
	return 0;
}

static int staticFunc4ArgContextRet(int a, double b, const QString &c)
{
	qDebug() << __func__ << a << b << c; 
	callCounts[__func__]++;
	return 0;
}
static int staticFunc3ArgContextRet(double a, int b, QString c)
{
	qDebug() << __func__ << a << b << c;
	callCounts[__func__]++;
	return 0;
}
static int staticFunc1ArgContextRet(int a)
{
	qDebug() << __func__ << a;
	callCounts[__func__]++;
	return 0;
}
static int staticFunc0ArgContextRet()
{
	qDebug() << __func__;
	callCounts[__func__]++;
	return 0;
}

static int staticFunc4ArgQueuedRet(int a, double b, const QString &c)
{
	qDebug() << __func__ << a << b << c; 
	callCounts[__func__]++;
	return 0;
}
static int staticFunc3ArgQueuedRet(double a, int b, QString c)
{
	qDebug() << __func__ << a << b << c;
	callCounts[__func__]++;
	return 0;
}
static int staticFunc1ArgQueuedRet(int a)
{
	qDebug() << __func__ << a;
	callCounts[__func__]++;
	return 0;
}
static int staticFunc0ArgQueuedRet()
{
	qDebug() << __func__;
	callCounts[__func__]++;
	return 0;
}

static int staticFunc4ArgCountRet(int a, double b, const QString &c)
{
	qDebug() << __func__ << a << b << c; 
	callCounts[__func__]++;
	return 0;
}
static int staticFunc3ArgCountRet(double a, int b, QString c)
{
	qDebug() << __func__ << a << b << c;
	callCounts[__func__]++;
	return 0;
}
static int staticFunc1ArgCountRet(int a)
{
	qDebug() << __func__ << a;
	callCounts[__func__]++;
	return 0;
}
static int staticFunc0ArgCountRet()
{
	qDebug() << __func__;
	callCounts[__func__]++;
	return 0;
}

static int staticFunc4ArgContextCountRet(int a, double b, const QString &c)
{
	qDebug() << __func__ << a << b << c; 
	callCounts[__func__]++;
	return 0;
}
static int staticFunc3ArgContextCountRet(double a, int b, QString c)
{
	qDebug() << __func__ << a << b << c;
	callCounts[__func__]++;
	return 0;
}
static int staticFunc1ArgContextCountRet(int a)
{
	qDebug() << __func__ << a;
	callCounts[__func__]++;
	return 0;
}
static int staticFunc0ArgContextCountRet()
{
	qDebug() << __func__;
	callCounts[__func__]++;
	return 0;
}

static int staticFunc4ArgQueuedCountRet(int a, double b, const QString &c)
{
	qDebug() << __func__ << a << b << c; 
	callCounts[__func__]++;
	return 0;
}
static int staticFunc3ArgQueuedCountRet(double a, int b, QString c)
{
	qDebug() << __func__ << a << b << c;
	callCounts[__func__]++;
	return 0;
}
static int staticFunc1ArgQueuedCountRet(int a)
{
	qDebug() << __func__ << a;
	callCounts[__func__]++;
	return 0;
}
static int staticFunc0ArgQueuedCountRet()
{
	qDebug() << __func__;
	callCounts[__func__]++;
	return 0;
}

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	Sender sender, resender;

	for (const auto &test : (Test[]){
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, staticFunc4Arg); },
			[]{ return callCounts.at("staticFunc4Arg") == 1; },
			"static function with mathing arg. list"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, staticFunc3Arg); },
			[]{ return callCounts.at("staticFunc3Arg") == 1; },
			"static function with 3 (implicit convertible) args."
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, staticFunc1Arg); },
			[]{ return callCounts.at("staticFunc1Arg") == 1; },
			"static function with 1 (implicit convertible) arg."
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, staticFunc0Arg); },
			[]{ return callCounts.at("staticFunc0Arg") == 1; },
			"static function with no args."
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc4ArgContext); },
			[]{ return callCounts.at("staticFunc4ArgContext") == 1; },
			"static function with mathing arg. list, using context"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc3ArgContext); },
			[]{ return callCounts.at("staticFunc3ArgContext") == 1; },
			"static function with 3 (implicit convertible) args., using context"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc1ArgContext); },
			[]{ return callCounts.at("staticFunc1ArgContext") == 1; },
			"static function with 1 (implicit convertible) arg., using context"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc0ArgContext); },
			[]{ return callCounts.at("staticFunc0ArgContext") == 1; },
			"static function with no args., using context"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc4ArgQueued, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc4ArgQueued") == 1; },
			"static function with mathing arg. list, using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc3ArgQueued, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc3ArgQueued") == 1; },
			"static function with 3 (implicit convertible) args., using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc1ArgQueued, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc1ArgQueued") == 1; },
			"static function with 1 (implicit convertible) arg., using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc0ArgQueued, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc0ArgQueued") == 1; },
			"static function with no args., using explicit (queued) connection type"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, staticFunc4ArgCount); },
			[]{ return callCounts.at("staticFunc4ArgCount") == 2; },
			"static function with mathing arg. list, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, staticFunc3ArgCount); },
			[]{ return callCounts.at("staticFunc3ArgCount") == 2; },
			"static function with 3 (implicit convertible) args., called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, staticFunc1ArgCount); },
			[]{ return callCounts.at("staticFunc1ArgCount") == 2; },
			"static function with 1 (implicit convertible) arg., called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, staticFunc0ArgCount); },
			[]{ return callCounts.at("staticFunc0ArgCount") == 2; },
			"static function with no args., called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc4ArgContextCount); },
			[]{ return callCounts.at("staticFunc4ArgContextCount") == 2; },
			"static function with mathing arg. list, using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc3ArgContextCount); },
			[]{ return callCounts.at("staticFunc3ArgContextCount") == 2; },
			"static function with 3 (implicit convertible) args., using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc1ArgContextCount); },
			[]{ return callCounts.at("staticFunc1ArgContextCount") == 2; },
			"static function with 1 (implicit convertible) arg., using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc0ArgContextCount); },
			[]{ return callCounts.at("staticFunc0ArgContextCount") == 2; },
			"static function with no args., using context, called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc4ArgQueuedCount, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc4ArgQueuedCount") == 2; },
			"static function with mathing arg. list, using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc3ArgQueuedCount, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc3ArgQueuedCount") == 2; },
			"static function with 3 (implicit convertible) args., using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc1ArgQueuedCount, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc1ArgQueuedCount") == 2; },
			"static function with 1 (implicit convertible) arg., using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc0ArgQueuedCount, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc0ArgQueuedCount") == 2; },
			"static function with no args., using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, staticFunc4ArgRet); },
			[]{ return callCounts.at("staticFunc4ArgRet") == 1; },
			"static function (with return signature) with mathing arg. list"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, staticFunc3ArgRet); },
			[]{ return callCounts.at("staticFunc3ArgRet") == 1; },
			"static function (with return signature) with 3 (implicit convertible) args."
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, staticFunc1ArgRet); },
			[]{ return callCounts.at("staticFunc1ArgRet") == 1; },
			"static function (with return signature) with 1 (implicit convertible) arg."
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, staticFunc0ArgRet); },
			[]{ return callCounts.at("staticFunc0ArgRet") == 1; },
			"static function (with return signature) with no args."
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc4ArgContextRet); },
			[]{ return callCounts.at("staticFunc4ArgContextRet") == 1; },
			"static function (with return signature) with mathing arg. list, using context"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc3ArgContextRet); },
			[]{ return callCounts.at("staticFunc3ArgContextRet") == 1; },
			"static function (with return signature) with 3 (implicit convertible) args., using context"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc1ArgContextRet); },
			[]{ return callCounts.at("staticFunc1ArgContextRet") == 1; },
			"static function (with return signature) with 1 (implicit convertible) arg., using context"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc0ArgContextRet); },
			[]{ return callCounts.at("staticFunc0ArgContextRet") == 1; },
			"static function (with return signature) with no args., using context"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc4ArgQueuedRet, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc4ArgQueuedRet") == 1; },
			"static function (with return signature) with mathing arg. list, using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc3ArgQueuedRet, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc3ArgQueuedRet") == 1; },
			"static function (with return signature) with 3 (implicit convertible) args., using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc1ArgQueuedRet, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc1ArgQueuedRet") == 1; },
			"static function (with return signature) with 1 (implicit convertible) arg., using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, staticFunc0ArgQueuedRet, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc0ArgQueuedRet") == 1; },
			"static function (with return signature) with no args., using explicit (queued) connection type"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, staticFunc4ArgCountRet); },
			[]{ return callCounts.at("staticFunc4ArgCountRet") == 2; },
			"static function (with return signature) with mathing arg. list, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, staticFunc3ArgCountRet); },
			[]{ return callCounts.at("staticFunc3ArgCountRet") == 2; },
			"static function (with return signature) with 3 (implicit convertible) args., called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, staticFunc1ArgCountRet); },
			[]{ return callCounts.at("staticFunc1ArgCountRet") == 2; },
			"static function (with return signature) with 1 (implicit convertible) arg., called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, staticFunc0ArgCountRet); },
			[]{ return callCounts.at("staticFunc0ArgCountRet") == 2; },
			"static function (with return signature) with no args., called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc4ArgContextCountRet); },
			[]{ return callCounts.at("staticFunc4ArgContextCountRet") == 2; },
			"static function (with return signature) with mathing arg. list, using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc3ArgContextCountRet); },
			[]{ return callCounts.at("staticFunc3ArgContextCountRet") == 2; },
			"static function (with return signature) with 3 (implicit convertible) args., using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc1ArgContextCountRet); },
			[]{ return callCounts.at("staticFunc1ArgContextCountRet") == 2; },
			"static function (with return signature) with 1 (implicit convertible) arg., using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc0ArgContextCountRet); },
			[]{ return callCounts.at("staticFunc0ArgContextCountRet") == 2; },
			"static function (with return signature) with no args., using context, called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc4ArgQueuedCountRet, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc4ArgQueuedCountRet") == 2; },
			"static function (with return signature) with mathing arg. list, using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc3ArgQueuedCountRet, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc3ArgQueuedCountRet") == 2; },
			"static function (with return signature) with 3 (implicit convertible) args., using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc1ArgQueuedCountRet, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc1ArgQueuedCountRet") == 2; },
			"static function (with return signature) with 1 (implicit convertible) arg., using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, staticFunc0ArgQueuedCountRet, Qt::QueuedConnection); },
			[]{ return callCounts.at("staticFunc0ArgQueuedCountRet") == 2; },
			"static function (with return signature) with no args., using explicit (queued) connection type, called twice"
		},
	})
	{
		tests.push_back(test);
		test.runFunc();
	}

	{
		Test test{
			[&sender] {
				auto context = new QObject;
				QObject::connect(context, &QObject::destroyed, [&sender] {
					qDebug() << "Context destroyed";
					QTimer::singleShot(0, &sender, &Sender::delayedSignal);
					QTimer::singleShot(0, &sender, &Sender::delayedSignal);
					QTimer::singleShot(0, &sender, &Sender::delayedSignal);
				});
				QObject::connect(&sender, &Sender::delayedSignal, [] { qDebug() << "Delayed signal"; });
				Once::connect(&sender, &Sender::delayedSignal, 4, context, [context] {
					auto count = context->property("callCount").toInt();
					context->setProperty("callCount", ++count);
					callCounts["contextTest"]++;
					qDebug() << "Called" << count << "out of 4, but expecting only one call "
						"to to context destruction";
					context->deleteLater();
				});
				QTimer::singleShot(0, &sender, &Sender::delayedSignal);
			},
			[]{ return callCounts.at("contextTest") == 1; },
			"lambda set to fire four times, but expected only to run once after context object is destroyed",
		};
		tests.push_back(test);
		test.runFunc();
	}

	Receiver receiver;
	auto verifyTotalCallCount = [&receiver] { return receiver.totalCallCount() == 48; };
	for (const auto &test : (Test[]){
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot1); },
			verifyTotalCallCount,
			"slot with mathing arg. list"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot2); },
			verifyTotalCallCount,
			"slot with 3 (implicit convertible) args."
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot3); },
			verifyTotalCallCount,
			"slot with 1 (implicit convertible) arg."
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot4); },
			verifyTotalCallCount,
			"slot with no args."
		},

		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot1, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot with mathing arg. list, using explicit (queued) connection type"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot2, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot with 3 (implicit convertible) args., using explicit (queued) connection type"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot3, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot with 1 (implicit convertible) arg., using explicit (queued) connection type"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot4, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot with no args., using explicit (queued) connection type"
		},

		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot1); },
			verifyTotalCallCount,
			"slot with mathing arg. list, called twice"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot2); },
			verifyTotalCallCount,
			"slot with 3 (implicit convertible) args., called twice"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot3); },
			verifyTotalCallCount,
			"slot with 1 (implicit convertible) arg., called twice"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot4); },
			verifyTotalCallCount,
			"slot with no args., called twice"
		},

		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot1, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot with mathing arg. list, using explicit (queued) connection type, called twice"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot2, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot with 3 (implicit convertible) args., using explicit (queued) connection type, called twice"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot3, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot with 1 (implicit convertible) arg., using explicit (queued) connection type, called twice"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot4, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot with no args., using explicit (queued) connection type, called twice"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot1); },
			verifyTotalCallCount,
			"slot (with return signature) with mathing arg. list"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot2); },
			verifyTotalCallCount,
			"slot (with return signature) with 3 (implicit convertible) args."
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot3); },
			verifyTotalCallCount,
			"slot (with return signature) with 1 (implicit convertible) arg."
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot4); },
			verifyTotalCallCount,
			"slot (with return signature) with no args."
		},

		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot1, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot (with return signature) with mathing arg. list, using explicit (queued) connection type"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot2, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot (with return signature) with 3 (implicit convertible) args., using explicit (queued) connection type"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot3, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot (with return signature) with 1 (implicit convertible) arg., using explicit (queued) connection type"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, &receiver, &Receiver::slot4, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot (with return signature) with no args., using explicit (queued) connection type"
		},

		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot1); },
			verifyTotalCallCount,
			"slot (with return signature) with mathing arg. list, called twice"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot2); },
			verifyTotalCallCount,
			"slot (with return signature) with 3 (implicit convertible) args., called twice"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot3); },
			verifyTotalCallCount,
			"slot (with return signature) with 1 (implicit convertible) arg., called twice"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot4); },
			verifyTotalCallCount,
			"slot (with return signature) with no args., called twice"
		},

		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot1, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot (with return signature) with mathing arg. list, using explicit (queued) connection type, called twice"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot2, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot (with return signature) with 3 (implicit convertible) args., using explicit (queued) connection type, called twice"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot3, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot (with return signature) with 1 (implicit convertible) arg., using explicit (queued) connection type, called twice"
		},
		{
			[&sender, &receiver]{ Once::connect(&sender, &Sender::signal, 2, &receiver, &Receiver::slot4, Qt::QueuedConnection); },
			verifyTotalCallCount,
			"slot (with return signature) with no args., using explicit (queued) connection type, called twice"
		},
	})
	{
		tests.push_back(test);
		test.runFunc();
	}

	for (const auto &test : (Test[]){
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4Arg"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc4Arg") == 1; },
			"lambda with mathing arg. list",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3Arg"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc3Arg") == 1; },
			"lambda with 3 (implicit convertible) args.",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1Arg"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc1Arg") == 1; },
			"lambda with 1 (implicit convertible) arg.",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, []() {
				qDebug() << __func__;
				callCounts["lambdaFunc0Arg"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc0Arg") == 1; },
			"lambda with no args.",
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgContext"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgContext") == 1; },
			"labmda with mathing arg. list, using context",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgContext"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgContext") == 1; },
			"lambda with 3 (implicit convertible) args., using context",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgContext"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgContext") == 1; },
			"lambda with 1 (implicit convertible) arg., using context",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, []{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgContext"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgContext") == 1; },
			"lambda with no args., using context"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgQueued"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc4ArgQueued") == 1; },
			"lambda with mathing arg. list, using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgQueued"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc3ArgQueued") == 1; },
			"lambda with 3 (implicit convertible) args., using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgQueued"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc1ArgQueued") == 1; },
			"lambda with 1 (implicit convertible) arg., using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, []{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgQueued"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgQueued") == 1; },
			"lambda with no args., using explicit (queued) connection type"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgCount"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgCount") == 2; },
			"lambda with mathing arg. list, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgCount"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgCount") == 2; },
			"lambda with 3 (implicit convertible) args., called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgCount"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgCount") == 2; },
			"lambda with 1 (implicit convertible) arg., called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, []{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgCount"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgCount") == 2; },
			"lambda with no args., called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgContextCount"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgContextCount") == 2; },
			"lambda with mathing arg. list, using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgContextCount"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgContextCount") == 2; },
			"lambda with 3 (implicit convertible) args., using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgContextCount"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgContextCount") == 2; },
			"lambda with 1 (implicit convertible) arg., using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, []{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgContextCount"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgContextCount") == 2; },
			"lambda with no args., using context, called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgQueuedCount"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc4ArgQueuedCount") == 2; },
			"lambda with mathing arg. list, using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgQueuedCount"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc3ArgQueuedCount") == 2; },
			"lambda with 3 (implicit convertible) args., using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgQueuedCount"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc1ArgQueuedCount") == 2; },
			"lambda with 1 (implicit convertible) arg., using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, []{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgQueuedCount"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc0ArgQueuedCount") == 2; },
			"lambda with no args., using explicit (queued) connection type, called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgRet") == 1; },
			"lambda (with return signature) with mathing arg. list",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgRet") == 1; },
			"lambda (with return signature) with 3 (implicit convertible) args.",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgRet") == 1; },
			"lambda (with return signature) with 1 (implicit convertible) arg.",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, []() {
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgRet") == 1; },
			"lambda (with return signature) with no args.",
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgContextRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgContextRet") == 1; },
			"labmda (with return signature) with mathing arg. list, using context",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgContextRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgContextRet") == 1; },
			"lambda (with return signature) with 3 (implicit convertible) args., using context",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgContextRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgContextRet") == 1; },
			"lambda (with return signature) with 1 (implicit convertible) arg., using context",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, []{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgContextRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgContextRet") == 1; },
			"lambda (with return signature) with no args., using context"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgQueuedRet"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc4ArgQueuedRet") == 1; },
			"lambda (with return signature) with mathing arg. list, using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgQueuedRet"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc3ArgQueuedRet") == 1; },
			"lambda (with return signature) with 3 (implicit convertible) args., using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgQueuedRet"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc1ArgQueuedRet") == 1; },
			"lambda (with return signature) with 1 (implicit convertible) arg., using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, []{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgQueuedRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgQueuedRet") == 1; },
			"lambda (with return signature) with no args., using explicit (queued) connection type"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgCountRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgCountRet") == 2; },
			"lambda (with return signature) with mathing arg. list, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgCountRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgCountRet") == 2; },
			"lambda (with return signature) with 3 (implicit convertible) args., called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgCountRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgCountRet") == 2; },
			"lambda (with return signature) with 1 (implicit convertible) arg., called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, []{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgCountRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgCountRet") == 2; },
			"lambda (with return signature) with no args., called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgContextCountRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgContextCountRet") == 2; },
			"lambda (with return signature) with mathing arg. list, using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgContextCountRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgContextCountRet") == 2; },
			"lambda (with return signature) with 3 (implicit convertible) args., using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgContextCountRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgContextCountRet") == 2; },
			"lambda (with return signature) with 1 (implicit convertible) arg., using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, []{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgContextCountRet"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgContextCountRet") == 2; },
			"lambda (with return signature) with no args., using context, called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgQueuedCountRet"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc4ArgQueuedCountRet") == 2; },
			"lambda (with return signature) with mathing arg. list, using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgQueuedCountRet"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc3ArgQueuedCountRet") == 2; },
			"lambda (with return signature) with 3 (implicit convertible) args., using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgQueuedCountRet"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc1ArgQueuedCountRet") == 2; },
			"lambda (with return signature) with 1 (implicit convertible) arg., using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, []{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgQueuedCountRet"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc0ArgQueuedCountRet") == 2; },
			"lambda (with return signature) with no args., using explicit (queued) connection type, called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [&](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgCap") == 1; },
			"lambda (capturing) with mathing arg. list",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [&](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgCap") == 1; },
			"lambda (capturing) with 3 (implicit convertible) args.",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [&](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgCap") == 1; },
			"lambda (capturing) with 1 (implicit convertible) arg.",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [&]() {
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgCap") == 1; },
			"lambda (capturing) with no args.",
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgContextCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgContextCap") == 1; },
			"labmda (capturing) with mathing arg. list, using context",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgContextCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgContextCap") == 1; },
			"lambda (capturing) with 3 (implicit convertible) args., using context",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgContextCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgContextCap") == 1; },
			"lambda (capturing) with 1 (implicit convertible) arg., using context",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&]{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgContextCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgContextCap") == 1; },
			"lambda (capturing) with no args., using context"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgQueuedCap"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc4ArgQueuedCap") == 1; },
			"lambda (capturing) with mathing arg. list, using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgQueuedCap"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc3ArgQueuedCap") == 1; },
			"lambda (capturing) with 3 (implicit convertible) args., using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgQueuedCap"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc1ArgQueuedCap") == 1; },
			"lambda (capturing) with 1 (implicit convertible) arg., using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&]{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgQueuedCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgQueuedCap") == 1; },
			"lambda (capturing) with no args., using explicit (queued) connection type"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [&](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgCountCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgCountCap") == 2; },
			"lambda (capturing) with mathing arg. list, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [&](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgCountCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgCountCap") == 2; },
			"lambda (capturing) with 3 (implicit convertible) args., called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [&](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgCountCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgCountCap") == 2; },
			"lambda (capturing) with 1 (implicit convertible) arg., called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [&]{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgCountCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgCountCap") == 2; },
			"lambda (capturing) with no args., called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgContextCountCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgContextCountCap") == 2; },
			"lambda (capturing) with mathing arg. list, using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgContextCountCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgContextCountCap") == 2; },
			"lambda (capturing) with 3 (implicit convertible) args., using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgContextCountCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgContextCountCap") == 2; },
			"lambda (capturing) with 1 (implicit convertible) arg., using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&]{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgContextCountCap"]++;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgContextCountCap") == 2; },
			"lambda (capturing) with no args., using context, called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgQueuedCountCap"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc4ArgQueuedCountCap") == 2; },
			"lambda (capturing) with mathing arg. list, using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgQueuedCountCap"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc3ArgQueuedCountCap") == 2; },
			"lambda (capturing) with 3 (implicit convertible) args., using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgQueuedCountCap"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc1ArgQueuedCountCap") == 2; },
			"lambda (capturing) with 1 (implicit convertible) arg., using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&]{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgQueuedCountCap"]++;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc0ArgQueuedCountCap") == 2; },
			"lambda (capturing) with no args., using explicit (queued) connection type, called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [&](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgRetCap") == 1; },
			"lambda (capturing) (with return signature) with mathing arg. list",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [&](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgRetCap") == 1; },
			"lambda (capturing) (with return signature) with 3 (implicit convertible) args.",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [&](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgRetCap") == 1; },
			"lambda (capturing) (with return signature) with 1 (implicit convertible) arg.",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, [&]() {
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgRetCap") == 1; },
			"lambda (capturing) (with return signature) with no args.",
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgContextRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgContextRetCap") == 1; },
			"labmda (capturing) (with return signature) with mathing arg. list, using context",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgContextRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgContextRetCap") == 1; },
			"lambda (capturing) (with return signature) with 3 (implicit convertible) args., using context",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgContextRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgContextRetCap") == 1; },
			"lambda (capturing) (with return signature) with 1 (implicit convertible) arg., using context",
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&]{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgContextRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgContextRetCap") == 1; },
			"lambda (capturing) (with return signature) with no args., using context"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgQueuedRetCap"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc4ArgQueuedRetCap") == 1; },
			"lambda (capturing) (with return signature) with mathing arg. list, using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgQueuedRetCap"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc3ArgQueuedRetCap") == 1; },
			"lambda (capturing) (with return signature) with 3 (implicit convertible) args., using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgQueuedRetCap"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc1ArgQueuedRetCap") == 1; },
			"lambda (capturing) (with return signature) with 1 (implicit convertible) arg., using explicit (queued) connection type"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, &sender, [&]{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgQueuedRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgQueuedRetCap") == 1; },
			"lambda (capturing) (with return signature) with no args., using explicit (queued) connection type"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [&](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgCountRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgCountRetCap") == 2; },
			"lambda (capturing) (with return signature) with mathing arg. list, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [&](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgCountRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgCountRetCap") == 2; },
			"lambda (capturing) (with return signature) with 3 (implicit convertible) args., called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [&](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgCountRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgCountRetCap") == 2; },
			"lambda (capturing) (with return signature) with 1 (implicit convertible) arg., called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, [&]{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgCountRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgCountRetCap") == 2; },
			"lambda (capturing) (with return signature) with no args., called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgContextCountRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc4ArgContextCountRetCap") == 2; },
			"lambda (capturing) (with return signature) with mathing arg. list, using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgContextCountRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc3ArgContextCountRetCap") == 2; },
			"lambda (capturing) (with return signature) with 3 (implicit convertible) args., using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgContextCountRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc1ArgContextCountRetCap") == 2; },
			"lambda (capturing) (with return signature) with 1 (implicit convertible) arg., using context, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&]{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgContextCountRetCap"]++;
				return 0;
			}); },
			[]{ return callCounts.at("lambdaFunc0ArgContextCountRetCap") == 2; },
			"lambda (capturing) (with return signature) with no args., using context, called twice"
		},

		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&](int a, double b, const QString &c) {
				qDebug() << __func__ << a << b << c; 
				callCounts["lambdaFunc4ArgQueuedCountRetCap"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc4ArgQueuedCountRetCap") == 2; },
			"lambda (capturing) (with return signature) with mathing arg. list, using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&](double a, int b, QString c) {
				qDebug() << __func__ << a << b << c;
				callCounts["lambdaFunc3ArgQueuedCountRetCap"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc3ArgQueuedCountRetCap") == 2; },
			"lambda (capturing) (with return signature) with 3 (implicit convertible) args., using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&](int a) {
				qDebug() << __func__ << a;
				callCounts["lambdaFunc1ArgQueuedCountRetCap"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc1ArgQueuedCountRetCap") == 2; },
			"lambda (capturing) (with return signature) with 1 (implicit convertible) arg., using explicit (queued) connection type, called twice"
		},
		{
			[&sender]{ Once::connect(&sender, &Sender::signal, 2, &sender, [&]{
				qDebug() << __func__;
				callCounts["lambdaFunc0ArgQueuedCountRetCap"]++;
				return 0;
			}, Qt::QueuedConnection); },
			[]{ return callCounts.at("lambdaFunc0ArgQueuedCountRetCap") == 2; },
			"lambda (capturing) (with return signature) with no args., using explicit (queued) connection type, called twice"
		},
	})
	{
		tests.push_back(test);
		test.runFunc();
	}

	/* Compile-time checks only: */
	{
		/* Test functor as a lambda variable (different signature): */
		auto lambda = [&](int a, double b, const QString &c) { qDebug() << __func__ << a << b << c; return 0; };
		Once::connect(&sender, &Sender::signal, lambda);
		Once::connect(&sender, &Sender::signal, 1, lambda);
		Once::connect(&sender, &Sender::signal, &sender, lambda);
		Once::connect(&sender, &Sender::signal, 1, &sender, lambda);
	}
	{
		/* Test functor as a std::function: */
		std::function<void(int)> lambda = [&](int a) { qDebug() << __func__ << a; };
		Once::connect(&sender, &Sender::signal, lambda);
		Once::connect(&sender, &Sender::signal, 1, lambda);
		Once::connect(&sender, &Sender::signal, &sender, lambda);
		Once::connect(&sender, &Sender::signal, 1, &sender, lambda);
	}

	Once::connect(&sender, &Sender::signal, &resender, &Sender::signal1);
	Once::connect(&sender, &Sender::signal, &resender, &Sender::signal2);
	Once::connect(&sender, &Sender::signal, &resender, &Sender::signal3);
	Once::connect(&sender, &Sender::signal, &resender, &Sender::signal4);

	sender.emitSignal();
	sender.emitSignal();
	sender.emitSignal();
	sender.emitSignal();
	sender.emitSignal();
	sender.emitSignal();
	sender.emitSignal();

	/* Test perfect forwarding (ensure a non-copyable object like QObject can
	 * be sent as an argument (in a direct connection): */
	Once::connect(&sender, &Sender::nonCopySignal, [](const QObject &o) { qDebug() << &o; });
	sender.emitNonCopySignal();

	QTimer::singleShot(10, []{
		bool allSucceeded = true;
		for (auto &test : tests)
		{
			try {
				if (!test.checkResult())
				{
					qCritical() << "FAILED:" << test.name << "(incorrect result)";
					allSucceeded = false;
				}
				else
					qInfo() << "SUCCEEDED:" << test.name;
			} catch (const std::out_of_range &) {
				qCritical() << "FAILED:" << test.name << "(functor/slot never called)";
				allSucceeded = false;
			}
		}

		if (!allSucceeded)
			qFatal("One or more tests failed");
	});
	QTimer::singleShot(20, []{ QCoreApplication::exit(); });
	return app.exec();
}
