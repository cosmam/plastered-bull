#ifndef TESTCHASIS_H
#define TESTCHASIS_H

#include <QObject>

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

        static int RandInt(int lower, int upper);

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
