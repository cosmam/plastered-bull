#ifndef CUSTOMGOALTEST_H
#define CUSTOMGOALTEST_H

#include <QObject>
#include <QPointer>
#include <QtTest>

namespace Data {
    class CustomGoal;
}

namespace Test {

    class CustomGoalTest : public QObject
    {
            Q_OBJECT

        public:
            explicit CustomGoalTest(QObject *parent = 0);

        signals:

        public slots:

        private:
            QPointer<Data::CustomGoal> m_goal;

        private Q_SLOTS:

            void initTestCase();
            void cleanupTestCase();
            void init();
            void cleanup();

            void TestStart_data();
            void TestStart();
            void TestDuration_data();
            void TestDuration();
            void WidgetTest_data();
            void WidgetTest();
    };

}

#endif // CUSTOMGOALTEST_H
