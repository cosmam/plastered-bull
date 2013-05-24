#include "timefunctions.h"

#include <QDataStream>

static int yourEnumMetaId = qRegisterMetaType<Time::Month>();

Time::Month Time::ToMonth( int month )
{
	if( month < 1 || month > 12 )
		return Time::INVALID_MONTH;
		
	Time::Month time = static_cast<Time::Month>( month );
	
	return time;
}

int Time::ToInt( Time::Month month )
{
	return static_cast<int>( month );
}

QString Time::ToString( Time::Month month )
{
	QString monthStr;
	
	switch( month )
	{
	case Time::JAN:
		monthStr = "January";
		break;
	case Time::FEB:
		monthStr = "February";
		break;
	case Time::MAR:
		monthStr = "March";
		break;
	case Time::APR:
		monthStr = "April";
		break;
	case Time::MAY:
		monthStr = "May";
		break;
	case Time::JUN:
		monthStr = "June";
		break;
	case Time::JUL:
		monthStr = "July";
		break;
	case Time::AUG:
		monthStr = "August";
		break;
	case Time::SEP:
		monthStr = "September";
		break;
	case Time::OCT:
		monthStr = "October";
		break;
	case Time::NOV:
		monthStr = "November";
		break;
	case Time::DEC:
		monthStr = "December";
		break;
	default:
		break;
	}
	
	return monthStr;
}

QDataStream & operator>>(QDataStream & in, Time::Month & month)
{
    in >> (qint32&)month;
    return in;
}
