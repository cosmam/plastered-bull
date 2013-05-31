#ifndef YEARGOALTEST_H
#define YEARGOALTEST_H

#include <QObject>
#include <QPointer>
#include <QtTest>

namespace Data
{
    class YearGoal;
}

class YearGoalTest : public QObject
{
        Q_OBJECT

    public:
        explicit YearGoalTest(QObject *parent = 0);

    signals:
        
    public slots:

    private:
        QPointer<Data::YearGoal> m_goal;

    private Q_SLOTS:

        void initTestCase();
        void cleanupTestCase();
        void init();
        void cleanup();

        void TestYear_data();
        void TestYear();
};

#endif // YEARGOALTEST_H
