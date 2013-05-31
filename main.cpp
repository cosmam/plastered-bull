#include <QApplication>

#include "customgoaltest.h"
#include "daygoaltest.h"
#include "goaltest.h"
#include "monthgoaltest.h"
#include "weekgoaltest.h"
#include "yeargoaltest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    int status=0;
    {
        CustomGoalTest test;
        status |= QTest::qExec(&test);
    }
    {
        DayGoalTest test;
        status |= QTest::qExec(&test);
    }
    {
        GoalTest test;
        status |= QTest::qExec(&test);
    }
    {
        MonthGoalTest test;
        status |= QTest::qExec(&test);
    }
    {
        WeekGoalTest test;
        status |= QTest::qExec(&test);
    }
    {
        YearGoalTest test;
        status |= QTest::qExec(&test);
    }

    return status;
}
