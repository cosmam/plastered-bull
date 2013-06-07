#ifndef WORDSCRITERIATEST_H
#define WORDSCRITERIATEST_H

#include <QList>
#include <QObject>
#include <QPointer>
#include <QtTest>

namespace Data {
    class Criteria;
    class WordsCriteria;
}

namespace Test {

    class WordsCriteriaTest : public QObject
    {
            Q_OBJECT

        public:
            explicit WordsCriteriaTest(QObject *parent = 0);

        signals:

        public slots:

        private:
            QPointer<Data::WordsCriteria> m_criteria;
            QList<Data::Criteria *> m_criteriaList;

        private Q_SLOTS:

            void initTestCase();
            void cleanupTestCase();
            void init();
            void cleanup();

            void WordsTest_data();
            void WordsTest();
            void MetTest_data();
            void MetTest();
    };

}

#endif // WORDSCRITERIATEST_H
