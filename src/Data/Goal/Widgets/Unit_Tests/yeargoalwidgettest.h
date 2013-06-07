#ifndef YEARGOALWIDGETTEST_H
#define YEARGOALWIDGETTEST_H

#include <QObject>
#include <QPointer>
#include <QtTest>

namespace Ui
{
    class YearGoalWidget;
}

namespace UI
{
    class YearGoalWidget;
}

namespace Test
{

class YearGoalWidgetTest : public QObject
{
        Q_OBJECT

    public:
        explicit YearGoalWidgetTest(QObject *parent = 0);

    signals:
        
    public slots:

    private:
        QPointer<UI::YearGoalWidget> m_widget;
        Ui::YearGoalWidget * m_ui;

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
        void YearTest_data();
        void YearTest();
};

}

#endif // YEARGOALWIDGETTEST_H
