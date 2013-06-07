#include "pagescriteriatest.h"

#include "testchasis.h"

#include "pagescriteria.h"
#include "wordscriteria.h"

using namespace Test;

PagesCriteriaTest::PagesCriteriaTest(QObject *parent) :
    QObject(parent)
{
}

void PagesCriteriaTest::initTestCase()
{

}

void PagesCriteriaTest::cleanupTestCase()
{
    qDeleteAll( m_criteriaList );
    m_criteriaList.clear();
}

void PagesCriteriaTest::init()
{
    m_criteria = new Data::PagesCriteria();
}

void PagesCriteriaTest::cleanup()
{
    delete m_criteria;
}

void PagesCriteriaTest::PagesTest_data()
{
    QTest::addColumn<int>("pages");

    QTest::newRow("zero") << 0;
    for( int i=0 ; i < 5 ; ++ i ) {
        int value = TestChasis::RandInt(-10000,0);
        QTest::newRow(qPrintable(QString::number(value))) << value;
    }
    for( int i=0 ; i < 10 ; ++ i ) {
        int value = TestChasis::RandInt(0,1000000);
        QTest::newRow(qPrintable(QString::number(value))) << value;
    }
}

void PagesCriteriaTest::PagesTest()
{
    QFETCH(int, pages);
    int beforePages = m_criteria->pages();
    m_criteria->setPages(pages);

    if( pages >= 0 ) {
        QCOMPARE(m_criteria->pages(), pages);
    }
    else {
        QCOMPARE(m_criteria->pages(), beforePages);
    }

}

void PagesCriteriaTest::MetTest_data()
{
    QTest::addColumn<int>("pages");
    QTest::addColumn<int>("pos");
    QTest::addColumn<bool>("met");

    int pages, max;
    max = 15;

    for( int i=0 ; i < max ; ++i ) {
        pages = TestChasis::RandInt(0,10000);

        if( TestChasis::RandInt(1,3) < 2 ) {
            Data::PagesCriteria * criteria = new Data::PagesCriteria();
            criteria->setPages( TestChasis::RandInt(0,1000) );
            m_criteriaList.append(criteria);
            QTest::newRow(qPrintable(QString::number(i))) << pages << i << (pages >= criteria->pages());
        } else {
            Data::WordsCriteria * criteria = new Data::WordsCriteria();
            criteria->setWords( TestChasis::RandInt(0,10000) );
            m_criteriaList.append(criteria);
            QTest::newRow(qPrintable(QString::number(i))) << pages << i << false;
        }
    }

    pages = TestChasis::RandInt(0,10000);
    Data::PagesCriteria * criteria = new Data::PagesCriteria();
    criteria->setPages( pages );
    m_criteriaList.append(criteria);
    QTest::newRow(qPrintable(QString::number(max))) << pages << max << true;
}

void PagesCriteriaTest::MetTest()
{
    QFETCH(int, pages);
    QFETCH(int, pos);
    QFETCH(bool, met);

    if( pos >= m_criteriaList.size() )
        return;

    m_criteria->setPages(pages);
    QCOMPARE(m_criteria->Met( m_criteriaList.at(pos) ), met);
}
