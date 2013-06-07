#ifndef MONTHGOALWIDGETTEST_H
#define MONTHGOALWIDGETTEST_H

#include <QObject>
#include <QPointer>
#include <QtTest>

namespace Ui
{
    class MonthGoalWidget;
}

namespace UI
{
    class MonthGoalWidget;
}

namespace Test
{

class MonthGoalWidgetTest : public QObject
{
        Q_OBJECT

    public:
        explicit MonthGoalWidgetTest(QObject *parent = 0);

    signals:
        
    public slots:

    private:
        QPointer<UI::MonthGoalWidget> m_widget;
        Ui::MonthGoalWidget * m_ui;

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
        void MonthTest_data();
        void MonthTest();
        void YearTest_data();
        void YearTest();
};

}

#endif // MONTHGOALWIDGETTEST_H
