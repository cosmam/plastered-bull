#ifndef PAGESCRITERIATEST_H
#define PAGESCRITERIATEST_H

#include <QList>
#include <QObject>
#include <QPointer>
#include <QtTest>

namespace Data {
    class Criteria;
    class PagesCriteria;
}

namespace Test {

    class PagesCriteriaTest : public QObject
    {
            Q_OBJECT

        public:
            explicit PagesCriteriaTest(QObject *parent = 0);

        signals:

        public slots:

        private:
            QPointer<Data::PagesCriteria> m_criteria;
            QList<Data::Criteria *> m_criteriaList;

        private Q_SLOTS:

            void initTestCase();
            void cleanupTestCase();
            void init();
            void cleanup();

            void PagesTest_data();
            void PagesTest();
            void MetTest_data();
            void MetTest();
    };

}

#endif // PAGESCRITERIATEST_H
