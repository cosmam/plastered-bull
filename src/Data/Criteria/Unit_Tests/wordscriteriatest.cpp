#include "wordscriteriatest.h"

#include "testchasis.h"

#include "pagescriteria.h"
#include "wordscriteria.h"

using namespace Test;

WordsCriteriaTest::WordsCriteriaTest(QObject *parent) :
    QObject(parent)
{
}

void WordsCriteriaTest::initTestCase()
{

}

void WordsCriteriaTest::cleanupTestCase()
{
    qDeleteAll( m_criteriaList );
    m_criteriaList.clear();
}

void WordsCriteriaTest::init()
{
    m_criteria = new Data::WordsCriteria();
}

void WordsCriteriaTest::cleanup()
{
    delete m_criteria;
}

void WordsCriteriaTest::WordsTest_data()
{
    QTest::addColumn<int>("words");

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

void WordsCriteriaTest::WordsTest()
{
    QFETCH(int, words);
    int beforeWords = m_criteria->words();
    m_criteria->setWords(words);

    if( words >= 0 ) {
        QCOMPARE(m_criteria->words(), words);
    }
    else {
        QCOMPARE(m_criteria->words(), beforeWords);
    }

}

void WordsCriteriaTest::MetTest_data()
{
    QTest::addColumn<int>("words");
    QTest::addColumn<int>("pos");
    QTest::addColumn<bool>("met");

    int words, max;
    max = 15;

    for( int i=0 ; i < max ; ++i ) {
        words = TestChasis::RandInt(0,10000);

        if( TestChasis::RandInt(1,3) < 2 ) {
            Data::PagesCriteria * criteria = new Data::PagesCriteria();
            criteria->setPages( TestChasis::RandInt(0,1000) );
            m_criteriaList.append(criteria);
            QTest::newRow(qPrintable(QString::number(i))) << words << i << false;
        } else {
            Data::WordsCriteria * criteria = new Data::WordsCriteria();
            criteria->setWords( TestChasis::RandInt(0,10000) );
            m_criteriaList.append(criteria);
            QTest::newRow(qPrintable(QString::number(i))) << words << i << (words >= criteria->words());
        }
    }

    words = TestChasis::RandInt(0,10000);
    Data::WordsCriteria * criteria = new Data::WordsCriteria();
    criteria->setWords( words );
    m_criteriaList.append(criteria);
    QTest::newRow(qPrintable(QString::number(max))) << words << max << true;
}

void WordsCriteriaTest::MetTest()
{
    QFETCH(int, words);
    QFETCH(int, pos);
    QFETCH(bool, met);

    if( pos >= m_criteriaList.size() )
        return;

    m_criteria->setWords(words);
    QCOMPARE(m_criteria->Met( m_criteriaList.at(pos) ), met);
}
