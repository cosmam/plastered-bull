#ifndef DAYGOALWIDGETTEST_H
#define DAYGOALWIDGETTEST_H

#include <QObject>
#include <QPointer>
#include <QtTest>

namespace Ui
{
    class DayGoalWidget;
}

namespace UI
{
    class DayGoalWidget;
}

namespace Test
{

class DayGoalWidgetTest : public QObject
{
        Q_OBJECT

    public:
        explicit DayGoalWidgetTest(QObject *parent = 0);

    signals:
        
    public slots:

    private:
        QPointer<UI::DayGoalWidget> m_widget;
        Ui::DayGoalWidget * m_ui;

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
        void DateTest_data();
        void DateTest();
};

}

#endif // DAYGOALWIDGETTEST_H
