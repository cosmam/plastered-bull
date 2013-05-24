#ifndef CRITERIA_H
#define CRITERIA_H

#include <QSharedDataPointer>

namespace Data
{

class Criteria
{
public:
    Criteria();
    Criteria(const Criteria &);
    Criteria &operator=(const Criteria &);
    ~Criteria();
    
private:
    class Impl;
    QSharedDataPointer<Impl> m_Impl;
};

}

QDataStream & operator<<(QDataStream & out, const Data::Criteria & criteria);

QDataStream & operator>>(QDataStream & in, Data::Criteria & criteria);

#endif // CRITERIA_H
