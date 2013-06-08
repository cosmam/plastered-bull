#include "criteriatest.h"

#include "criteriamock.h"
#include "timefunctions.h"

using namespace Test;

CriteriaTest::CriteriaTest(QObject *parent) :
    QObject(parent)
{
}

void CriteriaTest::initTestCase()
{

}

void CriteriaTest::cleanupTestCase()
{

}

void CriteriaTest::init()
{
    m_criteria = new Test::CriteriaMock();
}

void CriteriaTest::cleanup()
{
    delete m_criteria;
}

void CriteriaTest::TestConstruction()
{
    QVERIFY( m_criteria != NULL );
}
