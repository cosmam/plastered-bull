#ifndef CUSTOMGOALWIDGETTEST_H
#define CUSTOMGOALWIDGETTEST_H

#include <QObject>
#include <QPointer>
#include <QtTest>

namespace Ui
{
    class CustomGoalWidget;
}

namespace UI
{
    class CustomGoalWidget;
}

namespace Test
{

class CustomGoalWidgetTest : public QObject
{
        Q_OBJECT

    public:
        explicit CustomGoalWidgetTest(QObject *parent = 0);

    signals:
        
    public slots:

    private:
        QPointer<UI::CustomGoalWidget> m_widget;
        Ui::CustomGoalWidget * m_ui;

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
        void EndTest_data();
        void EndTest();
};

}

#endif // CUSTOMGOALWIDGETTEST_H
