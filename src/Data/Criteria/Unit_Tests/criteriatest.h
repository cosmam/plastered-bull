#ifndef CRITERIATEST_H
#define CRITERIATEST_H

#include <QObject>
#include <QPointer>
#include <QtTest>

namespace Test {

    class CriteriaMock;

    class CriteriaTest : public QObject
    {
            Q_OBJECT

        public:
            explicit CriteriaTest(QObject *parent = 0);

        signals:

        public slots:

        private:
            QPointer<Test::CriteriaMock> m_criteria;

        private Q_SLOTS:

            void initTestCase();
            void cleanupTestCase();
            void init();
            void cleanup();
    };

}

#endif // CRITERIATEST_H
