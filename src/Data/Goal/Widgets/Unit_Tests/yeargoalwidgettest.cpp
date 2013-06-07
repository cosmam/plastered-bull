#include "yeargoalwidgettest.h"

#include "yeargoalwidget.h"
#include "yeargoalwidget_p.h"
#include "ui_yeargoalwidget.h"

#include "testchasis.h"

#include <QColorDialog>

namespace {
const QString bgTag = "background-color:";
}

using namespace Test;

YearGoalWidgetTest::YearGoalWidgetTest(QObject *parent) :
    QObject(parent)
{
}

QString YearGoalWidgetTest::GetBackgroundColorName(QWidget * widget) const
{
    QString style = widget->styleSheet();

    int bg = style.indexOf(bgTag);
    int semi = style.indexOf(";",bg);

    return style.mid(bg + bgTag.size(), semi-bg-bgTag.size() ).trimmed();
}

void YearGoalWidgetTest::initTestCase()
{

}

void YearGoalWidgetTest::cleanupTestCase()
{

}

void YearGoalWidgetTest::init()
{
    m_widget = new UI::YearGoalWidget();
    m_ui = m_widget->d_ptr->ui;
}

void YearGoalWidgetTest::cleanup()
{
    delete m_widget;
    m_ui = NULL;
}

void YearGoalWidgetTest::NameTest_data()
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

void YearGoalWidgetTest::NameTest()
{
    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    events.simulate(m_ui->name_LineEdit);
    QCOMPARE(m_widget->Name(), expected);
}

void YearGoalWidgetTest::ColorTest_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QColor>("color");

    QTestEventList list;

    list.addMouseClick(Qt::LeftButton);
    QTest::newRow("red") << list << QColor("red");
    QTest::newRow("QColor(142,23,45)") << list << QColor(142,23,45);
}

void YearGoalWidgetTest::ColorTest()
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

void YearGoalWidgetTest::YearTest_data()
{
    QTest::addColumn<int>("year");

    for( int i=0; i < 20 ; ++i ) {
        int rand = TestChasis::RandInt(1950, 2150);
        QTest::newRow(qPrintable( QString::number(rand) )) << rand;
    }
}

void YearGoalWidgetTest::YearTest()
{
    QFETCH(int, year);

    m_ui->year_SpinBox->setValue(year);

    if( ( year >= m_ui->year_SpinBox->minimum() ) && ( year <= m_ui->year_SpinBox->maximum() ) ) {
        QCOMPARE(m_widget->Year(), year);
    } else if( year > m_ui->year_SpinBox->maximum() ) {
        QCOMPARE(m_widget->Year(), m_ui->year_SpinBox->maximum());
    } else {
        QCOMPARE(m_widget->Year(), m_ui->year_SpinBox->minimum());
    }
}
