#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>

namespace Data {

    class Goal;

    class DataStore : public QObject
    {
        Q_OBJECT

        public:

            /// Default constructor
            explicit DataStore(QObject *parent = 0);

            /// Destructor
            ~DataStore();

            //// Adds a goal
            void Add( Data::Goal * goal );

            /// Removes a goal
            void Remove( Data::Goal * goal );

            /// Gets a list of all the goals
            const QList<Data::Goal *> GetAll() const;

        Q_SIGNALS:

        public Q_SLOTS:

        private:

            class Impl;
            Impl * m_Impl;

        private Q_SLOTS:

            /// Slot called when a goal is deleted
            void GoalDeleted( QObject * object );
    };

}

#endif // DATASTORE_H
