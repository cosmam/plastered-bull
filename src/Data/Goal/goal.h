#ifndef GOAL_H
#define GOAL_H

#include "challenge.h"
#include "commontypes.h"

#include<QColor>
#include<QString>

namespace UI {
    class GoalWidgetBase;
}

namespace Data {

    class GoalPrivate;

    class Goal : public Challenge
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(Data::Goal)
        Q_DISABLE_COPY(Goal)

    public:

        /// Default constructor
        Goal( QObject * parent = 0 );

        /// Virtual destructor
        virtual ~Goal() {}

        /// Sets the goal color
        void setColor( const QColor & color );

        /// Gets the goal color
        QColor color() const;

        /// Sets the goal name
        void setName( const QString & name );

        /// Gets the goal name
        QString name() const;

        /// Virtual function that creates a goal widget from this goal
        virtual UI::GoalWidgetBase * CreateWidget() = 0;

        /// Gets the goal ID
        ID_t id() const;

    public Q_SLOTS:

    Q_SIGNALS:

        /// Signal emitted on color changed
        void colorChanged( QColor );

        /// Signal emitted on name changed
        void nameChanged( QString );

        /// Signal emitted on goal changed
        void goalChanged( Data::Goal * );

    protected:

        /// Overloaded constructor for d-pointer inheritence
        explicit Goal(GoalPrivate & d, QObject * parent = 0);
    };

}

#endif // GOAL_H
