#include "challenge.h"
#include "challenge_p.h"

using namespace Data;

Challenge::Challenge(QObject *parent) :
    QObject(parent),
    d_ptr( new ChallengePrivate )
{
}

Challenge::Challenge(ChallengePrivate &d, QObject *parent) :
    QObject(parent),
    d_ptr(&d)
{
}

/**************** Private Class ***************/

ChallengePrivate::ChallengePrivate() :
    QObject(),
    q_ptr(NULL)
{
}

void ChallengePrivate::init()
{

}
