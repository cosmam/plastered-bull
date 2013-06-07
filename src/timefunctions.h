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

    /// Convers an int to a month
	Time::Month ToMonth( int month );

    /// Converts a month to an int
	int ToInt( Time::Month month );

    /// Converts a month to a QString
	QString ToString( Time::Month month );
	
}

/// QDataStream input operator
QDataStream & operator>>(QDataStream & in, Time::Month & month);

Q_DECLARE_METATYPE( Time::Month )

#endif // TIMEFUNCTIONS_H
