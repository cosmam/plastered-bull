#ifndef GOALFACTORY_H
#define GOALFACTORY_H

class QObject;

namespace Data {

    class Goal;

    class GoalFactory
    {
    public:

        /// Static function to create a goal
        static Data::Goal * CreateGoal( int type, QObject * parent = 0 );
    };

}

#endif // GOALFACTORY_H
