#ifndef MONTHGOALTEST_H
#define MONTHGOALTEST_H

#include <QObject>
#include <QPointer>
#include <QtTest>

#include "timefunctions.h"

namespace Data {
    class MonthGoal;
}

namespace Test {

    class MonthGoalTest : public QObject
    {
            Q_OBJECT

        public:
            explicit MonthGoalTest(QObject *parent = 0);

        signals:

        public slots:

        private:
            QPointer<Data::MonthGoal> m_goal;

        private Q_SLOTS:

            void initTestCase();
            void cleanupTestCase();
            void init();
            void cleanup();

            void TestMonth_data();
            void TestMonth();
            void TestYear_data();
            void TestYear();
            void WidgetTest_data();
            void WidgetTest();
    };

}

#endif // MONTHGOALTEST_H
