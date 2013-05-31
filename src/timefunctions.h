#ifndef TIMEFUNCTIONS_H
#define TIMEFUNCTIONS_H

#include <QMetaType>
#include <QString>
#include <QTime>

namespace Time
{
	const QTime startTime(0,0,0,0);
	const QTime endTime(23,59,59,999);
	
	enum Month
	{
		INVALID_MONTH = 0,
		JAN,
		FEB,
		MAR,
		APR,
		MAY,
		JUN,
		JUL,
		AUG,
		SEP,
		OCT,
		NOV,
		DEC
	};
	
	Time::Month ToMonth( int month );
	int ToInt( Time::Month month );
	QString ToString( Time::Month month );
	
}

QDataStream & operator>>(QDataStream & in, Time::Month & month);

Q_DECLARE_METATYPE( Time::Month );

#endif // TIMEFUNCTIONS_H
