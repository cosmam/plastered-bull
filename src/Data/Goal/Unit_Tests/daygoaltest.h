#ifndef DAYGOALTEST_H
#define DAYGOALTEST_H

#include <QObject>
#include <QPointer>
#include <QtTest>

namespace Data
{
    class DayGoal;
}

class DayGoalTest : public QObject
{
        Q_OBJECT

    public:
        explicit DayGoalTest(QObject *parent = 0);

    signals:
        
    public slots:

    private:
        QPointer<Data::DayGoal> m_goal;

    private Q_SLOTS:

        void initTestCase();
        void cleanupTestCase();
        void init();
        void cleanup();

        void TestDate_data();
        void TestDate();
};

#endif // DAYGOALTEST_H
