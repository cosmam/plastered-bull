#ifndef CHALLENGE_P_H
#define CHALLENGE_P_H

#include <QObject>

namespace Data
{

class Challenge;

class ChallengePrivate : public QObject
{
	Q_OBJECT
    Q_DECLARE_PUBLIC(Data::Challenge);
    Q_DISABLE_COPY(ChallengePrivate);

public:
    explicit ChallengePrivate();
    virtual ~ChallengePrivate() {};
	
    virtual void init();

    Challenge * q_ptr;

public Q_SLOTS:

};

}

#endif // CHALLENGE_P_H
