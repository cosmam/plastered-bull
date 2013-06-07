#include "criteriamock.h"

#include "criteriawidgetbase.h"

using namespace Test;

CriteriaMock::CriteriaMock(QObject *parent) :
    Data::Criteria(parent)
{
}

bool CriteriaMock::Met(const Criteria *other) const
{
    return false;
}

UI::CriteriaWidgetBase * CriteriaMock::CreateWidget()
{
    return NULL;
}
