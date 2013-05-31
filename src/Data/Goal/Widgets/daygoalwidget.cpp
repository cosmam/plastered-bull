#include "daygoalwidget.h"
#include "daygoalwidget_p.h"

#include "daygoal.h"
#include "ui_daygoalwidget.h"

#include <QColorDialog>

using namespace UI;

DayGoalWidget::DayGoalWidget(QWidget *parent) :
    GoalWidgetBase(parent),
    d_ptr( new DayGoalWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);
}

DayGoalWidget::~DayGoalWidget()
{
    delete d_ptr;
}

void DayGoalWidget::SetupWidget( const Data::Goal * inGoal )
{
    const Data::DayGoal * goal = qobject_cast<const Data::DayGoal *>( inGoal );
	
    if( goal != NULL ) {
        Q_D(UI::DayGoalWidget);
        d->SetupWidget( goal );
    }
}

QString DayGoalWidget::Name() const
{
    Q_D(const UI::DayGoalWidget);
    return d->Name();
}

QColor DayGoalWidget::Color() const
{
    Q_D(const UI::DayGoalWidget);
    return d->color;
}

QDate DayGoalWidget::Date() const
{
    Q_D(const UI::DayGoalWidget);
    return d->Date();
}

/**************** Private Class ***************/

DayGoalWidgetPrivate::DayGoalWidgetPrivate(DayGoalWidget *parent) :
    QObject(parent),
    ui(new Ui::DayGoalWidget),
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

DayGoalWidgetPrivate::~DayGoalWidgetPrivate()
{
    delete ui;
}

void DayGoalWidgetPrivate::SetupWidget( const Data::DayGoal * goal )
{
    ui->name_LineEdit->setText( goal->name() );
    OnColorSelected( goal->color() );
    ui->date_DateEdit->setDate( goal->date() );
}

QString DayGoalWidgetPrivate::Name() const
{
    return ui->name_LineEdit->text();
}

QDate DayGoalWidgetPrivate::Date() const
{
    return ui->date_DateEdit->date();
}

void DayGoalWidgetPrivate::OnColorButtonClicked()
{
    Q_Q(UI::DayGoalWidget);

    colorDialog = new QColorDialog( color, q );

    connect( colorDialog, SIGNAL(colorSelected(QColor)),
             this, SLOT(OnColorSelected(QColor)));

    colorDialog->show();
}

void DayGoalWidgetPrivate::OnColorSelected( const QColor & inColor )
{
    color = inColor;
    QString style = "QPushButton { background: " + color.name() + "; }";
    ui->btn_Color->setStyleSheet( style );
}

void DayGoalWidgetPrivate::OnCancelClicked()
{
    Q_Q(UI::DayGoalWidget);

    emit q->ChangesCanceled();

    q->close();
}

void DayGoalWidgetPrivate::OnAcceptClicked()
{
    Q_Q(UI::DayGoalWidget);

    emit q->ChangesAccepted();

    q->close();
}
