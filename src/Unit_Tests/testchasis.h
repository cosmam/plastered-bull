#ifndef TESTCHASIS_H
#define TESTCHASIS_H

#include <QObject>

#include <QDate>
#include <QStringList>

namespace Test
{

class TestChasis : public QObject
{
        Q_OBJECT
    public:
        explicit TestChasis(QObject *parent = 0);
        ~TestChasis();

        void CreateObjects();

        int RunTests();

        static int RandInt(int lower=0, int upper=1000000);
        static QString RandString();
        static QDate RandDate(QDate start = QDate(2000,1,1), QDate end = QDate(2100,12,31));
        static QColor RandColor();

    signals:
        
    public slots:

    private:

        void RegisterTest(QObject * object);

        static void InitRand();

        QList<QObject *> m_objects;

        QStringList m_errors;

        static uint m_randInit;

        int m_status;

};

}

#endif // TESTCHASIS_H
