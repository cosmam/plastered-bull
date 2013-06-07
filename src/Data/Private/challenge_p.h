#ifndef CHALLENGE_P_H
#define CHALLENGE_P_H

#include <QObject>
#include <QPointer>

namespace Data {

    class Challenge;
    class Criteria;

    class ChallengePrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(Data::Challenge)
        Q_DISABLE_COPY(ChallengePrivate)

    public:

        /// Default constructor
        explicit ChallengePrivate();

        /// Virtual destructor
        virtual ~ChallengePrivate() {}

        /// Virtual function to initialize this class
        virtual void init();

        QPointer<Data::Criteria> criteria;

        Challenge * q_ptr;

    public Q_SLOTS:

    };

}

#endif // CHALLENGE_P_H
