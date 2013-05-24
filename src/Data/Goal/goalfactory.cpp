#include "goalfactory.h"

#include "goaltypes.h"

#include "customgoal.h"
#include "daygoal.h"
#include "monthgoal.h"
#include "weekgoal.h"
#include "yeargoal.h"

using namespace Data;

Data::Goal * GoalFactory::CreateGoal( int type, QObject * parent )
{
	Data::Goal * goal( NULL );
	
    switch( type ) {
	case Data::CUSTOM_GOAL_TYPE:
		goal = new CustomGoal( parent );
		break;
	case Data::DAY_GOAL_TYPE:
		goal = new DayGoal( parent );
		break;
	case Data::MONTH_GOAL_TYPE:
		goal = new MonthGoal( parent );
		break;
	case Data::WEEK_GOAL_TYPE:
		goal = new WeekGoal( parent );
		break;
	case Data::YEAR_GOAL_TYPE:
		goal = new YearGoal( parent );
		break;
	}
	
	return goal;
}
