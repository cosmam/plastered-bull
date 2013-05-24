#ifndef CHALLENGE_H
#define CHALLENGE_H

#include "commontypes.h"
#include "criteria.h"

#include<QColor>
#include<QDateTime>
#include<QObject>
#include<QString>

namespace Data
{

class Challenge : public QObject
{
	Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged );
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged );
	
public:

    Challenge( QObject * parent = NULL );

    virtual ~Challenge() {};
	
	void setColor( const QColor & color );
	QColor color() const;
	
	void setName( const QString & name );
	QString name() const;
	
    virtual UI::GoalWidgetBase * CreateWidget() const = 0;
	
signals:

	void colorChanged( QColor );
    void nameChanged( QString );
	
protected:

    QString m_name;
    QColor m_color;
    Data::Criteria m_criteria;
    QDateTime m_start;
    QDateTime m_end;
};

}

#endif // CHALLENGE_H
