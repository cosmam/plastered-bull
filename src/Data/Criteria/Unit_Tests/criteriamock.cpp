#include "criteriamock.h"

#include "criteriawidgetbase.h"

using namespace Test;

CriteriaMock::CriteriaMock(QObject *parent) :
    Data::Criteria(parent)
{
}

// LCOV_EXCL_START
bool CriteriaMock::Met(const Criteria *other) const
{
    return false;
}

UI::CriteriaWidgetBase * CriteriaMock::CreateWidget()
{
    return NULL;
}
// LCOV_EXCL_END
