#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>

namespace Data
{

class Goal;

class DataStore : public QObject
{
    Q_OBJECT
public:
    explicit DataStore(QObject *parent = 0);
    ~DataStore();

    void Add( Data::Goal * goal );

    void Remove( Data::Goal * goal );

    const QList<Data::Goal *> GetAll() const;

Q_SIGNALS:
    
public Q_SLOTS:

private:

    class Impl;
    Impl * m_Impl;
    
private Q_SLOTS:

    void GoalDeleted( QObject * object );
};

}

#endif // DATASTORE_H
