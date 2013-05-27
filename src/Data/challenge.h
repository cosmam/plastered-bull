#ifndef CHALLENGE_H
#define CHALLENGE_H

#include<QObject>
#include<QDateTime>

namespace Data
{

class ChallengePrivate;

class Challenge : public QObject
{
	Q_OBJECT
    Q_DECLARE_PRIVATE(Data::Challenge);
    Q_DISABLE_COPY(Challenge);
	
public:
    explicit Challenge(QObject * parent = 0);
    virtual ~Challenge() {};

    virtual QDateTime start() const = 0;
    virtual QDateTime end() const = 0;

public Q_SLOTS:

Q_SIGNALS:
	
protected:
    explicit Challenge(ChallengePrivate & d, QObject * parent = 0);
    ChallengePrivate * const d_ptr;
};

}

#endif // CHALLENGE_H
