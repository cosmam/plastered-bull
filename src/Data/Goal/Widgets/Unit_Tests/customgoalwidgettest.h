#ifndef CUSTOMGOALWIDGETTEST_H
#define CUSTOMGOALWIDGETTEST_H

#include <QObject>
#include <QPointer>
#include <QtTest>

namespace UI
{
    class CustomGoalWidget;
}

class CustomGoalWidgetTest : public QObject
{
        Q_OBJECT

    public:
        explicit CustomGoalWidgetTest(QObject *parent = 0);

    signals:
        
    public slots:

    private:
        QPointer<UI::CustomGoalWidget> m_widget;

    private Q_SLOTS:

        void initTestCase();
        void cleanupTestCase();
        void init();
        void cleanup();
};

#endif // CUSTOMGOALWIDGETTEST_H
