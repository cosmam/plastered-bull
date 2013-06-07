#include "customgoalwidgettest.h"

#include "customgoalwidget.h"
#include "customgoalwidget_p.h"
#include "ui_customgoalwidget.h"

#include <QColorDialog>

namespace {
const QString bgTag = "background-color:";
}

using namespace Test;

CustomGoalWidgetTest::CustomGoalWidgetTest(QObject *parent) :
    QObject(parent)
{
}

QString CustomGoalWidgetTest::GetBackgroundColorName(QWidget * widget) const
{
    QString style = widget->styleSheet();

    int bg = style.indexOf(bgTag);
    int semi = style.indexOf(";",bg);

    return style.mid(bg + bgTag.size(), semi-bg-bgTag.size() ).trimmed();
}

void CustomGoalWidgetTest::initTestCase()
{

}

void CustomGoalWidgetTest::cleanupTestCase()
{

}

void CustomGoalWidgetTest::init()
{
    m_widget = new UI::CustomGoalWidget();
    m_ui = m_widget->d_ptr->ui;
}

void CustomGoalWidgetTest::cleanup()
{
    delete m_widget;
    m_ui = NULL;
}

void CustomGoalWidgetTest::NameTest_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");

    QTestEventList list1, list2, list3, list4;

    list1.addKeyClick('a');
    QTest::newRow("blank") << list1 << "a";

    list2.addKeyClicks("hello world!");
    list2.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("backspace") << list2 << QString("hello world");

    list3.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("blank backspace") << list3 << QString("");

    list4.addKeyClick(Qt::Key_Return);
    QTest::newRow("blank enter") << list4 << QString("");
}

void CustomGoalWidgetTest::NameTest()
{
    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    events.simulate(m_ui->name_LineEdit);
    QCOMPARE(m_widget->Name(), expected);
}

void CustomGoalWidgetTest::ColorTest_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QColor>("color");

    QTestEventList list;

    list.addMouseClick(Qt::LeftButton);
    QTest::newRow("red") << list << QColor("red");
    QTest::newRow("QColor(142,23,45)") << list << QColor(142,23,45);
}

void CustomGoalWidgetTest::ColorTest()
{
    QFETCH(QTestEventList, events);
    QFETCH(QColor, color);

    QColorDialog * dialog;

    events.simulate(m_ui->btn_Color);
    dialog = m_widget->d_ptr->colorDialog;
    QVERIFY(dialog != NULL);

    if( dialog == NULL )
        return;

    QVERIFY(QTest::qWaitForWindowActive(dialog));

    dialog->setCurrentColor(color);
    QTest::keyClick(dialog, Qt::Key_Return);

    // test cancel and button background color

    QCOMPARE(m_widget->Color(), color);
    QCOMPARE(GetBackgroundColorName(m_ui->btn_Color), color.name());

    events.simulate(m_ui->btn_Color);
    dialog = m_widget->d_ptr->colorDialog;
    QVERIFY(dialog != NULL);

    if( dialog == NULL )
        return;

    QVERIFY(QTest::qWaitForWindowActive(dialog));

    dialog->setCurrentColor(QColor(1,1,1));
    QTest::keyClick(dialog, Qt::Key_Escape);

    QCOMPARE(m_widget->Color(), color);
    QCOMPARE(GetBackgroundColorName(m_ui->btn_Color), color.name());
}

void CustomGoalWidgetTest::StartTest_data()
{
    QTest::addColumn<QDate>("date");

    QTest::newRow("down") << QDate::currentDate().addDays(-1);
    QTest::newRow("up") << QDate::currentDate().addDays(1);
    QTest::newRow("set") << QDate(2013,12,31);
}

void CustomGoalWidgetTest::StartTest()
{
    QFETCH(QDate, date);

    m_ui->startDate_DateEdit->setDate(date);
    QCOMPARE(m_widget->StartDate(), date);
}

void CustomGoalWidgetTest::EndTest_data()
{
    QTest::addColumn<QDate>("date");
    QTest::addColumn<int>("duration");

    QTest::newRow("down") << QDate::currentDate().addDays(-1) << 0;
    QTest::newRow("up") << QDate::currentDate().addDays(1) << 1;
    QTest::newRow("set") << QDate::currentDate().addDays(100) << 100;
}

void CustomGoalWidgetTest::EndTest()
{
    QFETCH(QDate, date);
    QFETCH(int, duration);

    m_ui->endDate_DateEdit->setDate(date);
    QCOMPARE(m_widget->Duration(), duration);
}
