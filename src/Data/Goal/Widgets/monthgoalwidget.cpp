#include "monthgoalwidget.h"
#include "monthgoalwidget_p.h"

#include "monthgoal.h"
#include "ui_monthgoalwidget.h"

#include <QColorDialog>

using namespace UI;

MonthGoalWidget::MonthGoalWidget(QWidget *parent) :
    GoalWidgetBase(parent),
    d_ptr( new MonthGoalWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);
}

MonthGoalWidget::~MonthGoalWidget()
{
    delete d_ptr;
}

void MonthGoalWidget::SetupWidget( const Data::Goal * inGoal )
{
    const Data::MonthGoal * goal = qobject_cast<const Data::MonthGoal *>( inGoal );
	
    if( goal != NULL ) {
        Q_D(UI::MonthGoalWidget);
        d->SetupWidget( goal );
    }
}

QString MonthGoalWidget::Name() const
{
    Q_D(const UI::MonthGoalWidget);
    return d->Name();
}

QColor MonthGoalWidget::Color() const
{
    Q_D(const UI::MonthGoalWidget);
    return d->color;
}

Time::Month MonthGoalWidget::Month() const
{
    Q_D(const UI::MonthGoalWidget);
    return d->Month();
}

int MonthGoalWidget::Year() const
{
    Q_D(const UI::MonthGoalWidget);
    return d->Year();
}

/**************** Private Class ***************/

MonthGoalWidgetPrivate::MonthGoalWidgetPrivate(MonthGoalWidget *parent) :
    QObject(parent),
    ui(new Ui::MonthGoalWidget),
    q_ptr(parent)
{
    ui->setupUi(q_ptr);

    connect( ui->btn_Cancel, SIGNAL(clicked()),
             this, SLOT(OnCancelClicked()) );
    connect( ui->btn_Accept, SIGNAL(clicked()),
             this, SLOT(OnAcceptClicked()) );
    connect( ui->btn_Color, SIGNAL(clicked()),
             this, SLOT(OnColorButtonClicked()) );
}

MonthGoalWidgetPrivate::~MonthGoalWidgetPrivate()
{
    delete ui;
}

void MonthGoalWidgetPrivate::SetupWidget( const Data::MonthGoal * goal )
{
    ui->name_LineEdit->setText( goal->name() );
    OnColorSelected( goal->color() );
    ui->month_ComboBox->setCurrentIndex( Time::ToInt( goal->month() ) );
    ui->year_SpinBox->setValue( goal->year() );
}

QString MonthGoalWidgetPrivate::Name() const
{
    return ui->name_LineEdit->text();
}

Time::Month MonthGoalWidgetPrivate::Month() const
{
    return Time::ToMonth( ui->month_ComboBox->currentIndex() );
}

int MonthGoalWidgetPrivate::Year() const
{
    return ui->year_SpinBox->value();
}

void MonthGoalWidgetPrivate::OnColorButtonClicked()
{
    Q_Q(UI::MonthGoalWidget);

    colorDialog = new QColorDialog( color, q );

    connect( colorDialog, SIGNAL(colorSelected(QColor)),
             this, SLOT(OnColorSelected(QColor)));

    colorDialog->show();
}

void MonthGoalWidgetPrivate::OnColorSelected( const QColor & inColor )
{
    color = inColor;
    QString style = "QPushButton { background: " + color.name() + "; }";
    ui->btn_Color->setStyleSheet( style );
}

void MonthGoalWidgetPrivate::OnCancelClicked()
{
    Q_Q(UI::MonthGoalWidget);

    emit q->ChangesCanceled();

    q->close();
}

void MonthGoalWidgetPrivate::OnAcceptClicked()
{
    Q_Q(UI::MonthGoalWidget);

    emit q->ChangesAccepted();

    q->close();
}
