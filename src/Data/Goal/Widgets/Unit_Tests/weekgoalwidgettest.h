#ifndef WEEKGOALWIDGETTEST_H
#define WEEKGOALWIDGETTEST_H

#include <QObject>
#include <QPointer>
#include <QtTest>

namespace Ui
{
    class WeekGoalWidget;
}

namespace UI
{
    class WeekGoalWidget;
}

namespace Test
{

class WeekGoalWidgetTest : public QObject
{
        Q_OBJECT

    public:
        explicit WeekGoalWidgetTest(QObject *parent = 0);

    signals:
        
    public slots:

    private:
        QPointer<UI::WeekGoalWidget> m_widget;
        Ui::WeekGoalWidget * m_ui;

        QString GetBackgroundColorName(QWidget * widget) const;

    private Q_SLOTS:

        void initTestCase();
        void cleanupTestCase();
        void init();
        void cleanup();

        void NameTest_data();
        void NameTest();
        void ColorTest_data();
        void ColorTest();
        void StartTest_data();
        void StartTest();
};

}

#endif // WEEKGOALWIDGETTEST_H
