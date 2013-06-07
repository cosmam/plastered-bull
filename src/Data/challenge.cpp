#include "challenge.h"
#include "challenge_p.h"

#include "criteria.h"

using namespace Data;

/**
 * @author Cosmam
 * @name Challenge
 * @namespace Data
 * @brief Default constructor
 * @param parent: The parent object
 **/
Challenge::Challenge(QObject *parent) :
    QObject(parent),
    d_ptr( new ChallengePrivate )
{
}

/**
 * @author Cosmam
 * @name Challenge
 * @namespace Data
 * @brief Overloaded constructor for d-ptr initialization
 * @param d: A reference to the private class
 * @param parent: The parent object
 **/
Challenge::Challenge(ChallengePrivate &d, QObject *parent) :
    QObject(parent),
    d_ptr(&d)
{
}

/**
 * @author Cosmam
 * @name setCriteria
 * @namespace Data
 * @brief Sets the challenge criteria
 * @param criteria: A pointer to the criteria
 **/
void Challenge::setCriteria( Data::Criteria * criteria )
{
    Q_D(Data::Challenge);
    if( d->criteria != criteria ) {
        if( d->criteria != NULL ) {
            delete d->criteria;
        }
        d->criteria = criteria;
        criteriaChanged( criteria );
    }
}

/**
 * @author Cosmam
 * @name criteria
 * @namespace Data
 * @brief Gets the challenge criteria
 * @return A constant pointer to the challenge criteria
 **/
const Data::Criteria * Challenge::criteria() const
{
    Q_D(const Data::Challenge);
    return d->criteria;
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name ChallengePrivate
 * @namespace Data
 * @brief Default constructor
 **/
ChallengePrivate::ChallengePrivate() :
    QObject(),
    q_ptr(NULL)
{
}

/**
 * @author Cosmam
 * @name init
 * @namespace Data
 * @brief Initializes this object
 **/
void ChallengePrivate::init()
{

}
