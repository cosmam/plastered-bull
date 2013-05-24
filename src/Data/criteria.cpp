#include "criteria.h"
#include <QSharedData>

using namespace Data;

class Data::Criteria::Impl : public QSharedData {
public:
};

Criteria::Criteria() :
    m_Impl(new Data::Criteria::Impl)
{
}

Criteria::Criteria(const Criteria &rhs) :
    m_Impl(rhs.m_Impl)
{
}

Criteria & Criteria::operator=(const Criteria &rhs)
{
    if (this != &rhs)
    {
        m_Impl.operator=(rhs.m_Impl);
    }

    return *this;
}

Criteria::~Criteria()
{
}

QDataStream & operator<<(QDataStream & out, const Criteria & criteria)
{
    Q_UNUSED(criteria);

    return out;
}

QDataStream & operator>>(QDataStream & in, Criteria & criteria)
{
    Q_UNUSED(criteria);

    return in;
}
