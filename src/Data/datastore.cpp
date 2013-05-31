#include "datastore.h"

#include "goal.h"

#include <QList>
#include <QPointer>

using namespace Data;

class DataStore::Impl
{
public:
    QList< QPointer<Goal> > data;
};

DataStore::DataStore(QObject *parent) :
    QObject(parent),
    m_Impl( new DataStore::Impl )
{
}

DataStore::~DataStore()
{
    delete m_Impl;
}

void DataStore::Add( Data::Goal * goal )
{
    m_Impl->data.append( goal );
    connect( goal, SIGNAL( destroyed(QObject*) ),
             this, SLOT( GoalDeleted(QObject*) ) );
}

void DataStore::Remove( Data::Goal * goal )
{
    m_Impl->data.removeAll(goal);
}

const QList<Data::Goal *> DataStore::GetAll() const
{
    QList<Data::Goal *> list;
    foreach( QPointer<Data::Goal> goal, m_Impl->data )
    {
        list.append( goal );
    }

    return list;
}

void DataStore::GoalDeleted( QObject * object )
{
    Data::Goal * goal = qobject_cast<Data::Goal *>(object);

    Remove(goal);
}
