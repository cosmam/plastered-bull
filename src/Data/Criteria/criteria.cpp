#include "criteria.h"
#include "criteria_p.h"

using namespace Data;

/**
 * @author Cosmam
 * @name Criteria
 * @namespace Data
 * @brief Criteria::Criteria
 * @param parent
 **/
Criteria::Criteria(QObject *parent) :
    QObject(parent),
    d_ptr( new CriteriaPrivate )
{
}

/**
 * @author Cosmam
 * @name Criteria
 * @namespace Data
 * @brief Overloaded constructor for d-pointer inheritence
 * @param d
 * @param parent
 **/
Criteria::Criteria(CriteriaPrivate &d, QObject *parent) :
    QObject(parent),
    d_ptr(&d)
{
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name CriteriaPrivate
 * @namespace Data
 * @brief Default constructor
 **/
CriteriaPrivate::CriteriaPrivate() :
    QObject(),
    q_ptr(NULL)
{
}

/**
 * @author Cosmam
 * @name init
 * @namespace Data
 * @brief Virtual function to initialize this widget
 **/
void CriteriaPrivate::init()
{

}
