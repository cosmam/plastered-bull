#ifndef WEEKGOALTEST_H
#define WEEKGOALTEST_H

#include <QObject>
#include <QPointer>
#include <QtTest>

namespace Data
{
    class WeekGoal;
}

class WeekGoalTest : public QObject
{
        Q_OBJECT

    public:
        explicit WeekGoalTest(QObject *parent = 0);

    signals:
        
    public slots:

    private:
        QPointer<Data::WeekGoal> m_goal;

    private Q_SLOTS:

        void initTestCase();
        void cleanupTestCase();
        void init();
        void cleanup();

        void TestStart_data();
        void TestStart();
};

#endif // WEEKGOALTEST_H
