#include "weekgoalwidget.h"
#include "weekgoalwidget_p.h"

#include "weekgoal.h"
#include "ui_weekgoalwidget.h"

#include <QColorDialog>

using namespace UI;

WeekGoalWidget::WeekGoalWidget(QWidget *parent) :
    GoalWidgetBase(parent),
    d_ptr( new WeekGoalWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);
}

WeekGoalWidget::~WeekGoalWidget()
{
    delete d_ptr;
}

void WeekGoalWidget::SetupWidget( const Data::Goal * inGoal )
{
    const Data::WeekGoal * goal = qobject_cast<const Data::WeekGoal *>( inGoal );

    if( goal != NULL ) {
        Q_D(UI::WeekGoalWidget);
        d->SetupWidget( goal );
    }
}

QString WeekGoalWidget::Name() const
{
    Q_D(const UI::WeekGoalWidget);
    return d->Name();
}

QColor WeekGoalWidget::Color() const
{
    Q_D(const UI::WeekGoalWidget);
    return d->color;
}

QDate WeekGoalWidget::StartDate() const
{
    Q_D(const UI::WeekGoalWidget);
    return d->StartDate();
}

/**************** Private Class ***************/

WeekGoalWidgetPrivate::WeekGoalWidgetPrivate(WeekGoalWidget *parent) :
    QObject(parent),
    ui(new Ui::WeekGoalWidget),
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

WeekGoalWidgetPrivate::~WeekGoalWidgetPrivate()
{
    delete ui;
}

void WeekGoalWidgetPrivate::SetupWidget( const Data::WeekGoal * goal )
{
    ui->name_LineEdit->setText( goal->name() );
    OnColorSelected( goal->color() );
    ui->startDate_DateEdit->setDate( goal->startDate() );
}

QString WeekGoalWidgetPrivate::Name() const
{
    return ui->name_LineEdit->text();
}

QDate WeekGoalWidgetPrivate::StartDate() const
{
    return ui->startDate_DateEdit->date();
}

void WeekGoalWidgetPrivate::OnColorButtonClicked()
{
    Q_Q(UI::WeekGoalWidget);

    colorDialog = new QColorDialog( color, q );

    connect( colorDialog, SIGNAL(colorSelected(QColor)),
             this, SLOT(OnColorSelected(QColor)));

    colorDialog->show();
}

void WeekGoalWidgetPrivate::OnColorSelected( const QColor & inColor )
{
    color = inColor;
    QString style = "QPushButton { background: " + color.name() + "; }";
    ui->btn_Color->setStyleSheet( style );
}

void WeekGoalWidgetPrivate::OnCancelClicked()
{
    Q_Q(UI::WeekGoalWidget);

    emit q->ChangesCanceled();

    q->close();
}

void WeekGoalWidgetPrivate::OnAcceptClicked()
{
    Q_Q(UI::WeekGoalWidget);

    emit q->ChangesAccepted();

    q->close();
}
