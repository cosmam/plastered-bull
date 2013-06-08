#ifndef CHALLENGE_H
#define CHALLENGE_H

#include<QObject>
#include<QDateTime>

namespace Data {

    class ChallengePrivate;
    class Criteria;

    class Challenge : public QObject
    {
        Q_OBJECT                            // LCOV_EXCL_LINE
        Q_DECLARE_PRIVATE(Data::Challenge)
        Q_DISABLE_COPY(Challenge)

    public:

        /// Default constructor
        explicit Challenge(QObject * parent = 0);

        /// Virtual destructor
        virtual ~Challenge() {}     // LCOV_EXCL_LINE

        /// Virtual function to get the goal start datetime
        virtual QDateTime start() const = 0;

        /// Virtual function to get the goal end datetime
        virtual QDateTime end() const = 0;

        /// Sets the goal criteria
        void setCriteria( Data::Criteria * criteria );

        /// Gets the goal criteria
        const Data::Criteria * criteria() const;

    public Q_SLOTS:

    Q_SIGNALS:

        /// Signal emitted when the criteria is changed
        void criteriaChanged( Data::Criteria * );

    protected:

        /// Overloaded constructor for d-pointer initialization
        explicit Challenge(ChallengePrivate & d, QObject * parent = 0);
        ChallengePrivate * const d_ptr;
    };

}

#endif // CHALLENGE_H
