#ifndef GOALTEST_H
#define GOALTEST_H

#include <QObject>
#include <QPointer>
#include <QtTest>

namespace Test {

    class GoalMock;

    class GoalTest : public QObject
    {
            Q_OBJECT

        public:
            explicit GoalTest(QObject *parent = 0);

        signals:

        public slots:

        private:
            QPointer<Test::GoalMock> m_goal;

        private Q_SLOTS:

            void initTestCase();
            void cleanupTestCase();
            void init();
            void cleanup();

            void TestName_data();
            void TestName();
            void TestColor_data();
            void TestColor();
    };

}

#endif // GOALTEST_H
