#include "challenge.h"

using namespace Data;

Challenge::Challenge(QObject *parent) :
    QObject(parent)
{
}

void Challenge::setColor( const QColor & color )
{
    m_color = color;
    emit colorChanged( m_color );
}

QColor Challenge::color() const
{
    return m_color;
}

void Challenge::setName( const QString & name )
{
    m_name = name;
    emit nameChanged( m_name );
}

QString Challenge::name() const
{
    return m_name;
}
