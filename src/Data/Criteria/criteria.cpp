#include "criteria.h"
#include "criteria_p.h"

using namespace Data;

Criteria::Criteria(QObject *parent) :
    QObject(parent),
    d_ptr( new CriteriaPrivate )
{
}

Criteria::Criteria(CriteriaPrivate &d, QObject *parent) :
    QObject(parent),
    d_ptr(&d)
{
}

/**************** Private Class ***************/

CriteriaPrivate::CriteriaPrivate() :
    QObject(),
    q_ptr(NULL)
{
}

void CriteriaPrivate::init()
{

}
