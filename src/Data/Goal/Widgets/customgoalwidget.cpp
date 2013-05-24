#include "customgoalwidget.h"
#include "customgoalwidget_p.h"

#include "customgoal.h"
#include "ui_customgoalwidget.h"

#include <QColorDialog>

using namespace UI;

CustomGoalWidget::CustomGoalWidget(QWidget *parent) :
    GoalWidgetBase(parent),
    d_ptr( new CustomGoalWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);	
}

CustomGoalWidget::~CustomGoalWidget()
{
    delete d_ptr;
}

void CustomGoalWidget::SetupWidget( const Data::Goal * inGoal )
{
    const Data::CustomGoal * goal = qobject_cast<const Data::CustomGoal *>( inGoal );

    if( goal != NULL ) {
        Q_D(UI::CustomGoalWidget);
        d->SetupWidget( goal );
    }
}

QString CustomGoalWidget::Name() const
{
    Q_D(const UI::CustomGoalWidget);
    return d->Name();
}

QColor CustomGoalWidget::Color() const
{
    Q_D(const UI::CustomGoalWidget);
    return d->color;
}

QDate CustomGoalWidget::StartDate() const
{
    Q_D(const UI::CustomGoalWidget);
    return d->StartDate();
}

int CustomGoalWidget::Duration() const
{
    Q_D(const UI::CustomGoalWidget);
    return d->Duration();
}

/**************** Private Class ***************/

CustomGoalWidgetPrivate::CustomGoalWidgetPrivate(CustomGoalWidget *parent) :
    QObject(parent),
    ui(new Ui::CustomGoalWidget),
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

CustomGoalWidgetPrivate::~CustomGoalWidgetPrivate()
{
    delete ui;
}

void CustomGoalWidgetPrivate::SetupWidget( const Data::CustomGoal * goal )
{
    connect( ui->startDate_DateEdit, SIGNAL(dateChanged(QDate)),
         this, SLOT(OnStartDateChanged(QDate)));

    ui->name_LineEdit->setText( goal->name() );
    OnColorSelected( goal->color() );
    ui->startDate_DateEdit->setDate( goal->startDate() );
    ui->endDate_DateEdit->setDate( goal->end().date() );
}

QString CustomGoalWidgetPrivate::Name() const
{
    return ui->name_LineEdit->text();
}

QDate CustomGoalWidgetPrivate::StartDate() const
{
    return ui->startDate_DateEdit->date();
}

int CustomGoalWidgetPrivate::Duration() const
{
    return ui->startDate_DateEdit->date().daysTo( ui->endDate_DateEdit->date() );
}

void CustomGoalWidgetPrivate::OnColorButtonClicked()
{
    Q_Q(UI::CustomGoalWidget);

    colorDialog = new QColorDialog( color, q );

    connect( colorDialog, SIGNAL(colorSelected(QColor)),
             this, SLOT(OnColorSelected(QColor)));

    colorDialog->show();
}

void CustomGoalWidgetPrivate::OnColorSelected( const QColor & inColor )
{
    color = inColor;
    QString style = "QPushButton { background: " + color.name() + "; }";
    ui->btn_Color->setStyleSheet( style );
}

void CustomGoalWidgetPrivate::OnStartDateChanged( const QDate & date )
{
    ui->endDate_DateEdit->setMinimumDate( date );
}

void CustomGoalWidgetPrivate::OnCancelClicked()
{
    Q_Q(UI::CustomGoalWidget);

    emit q->ChangesCanceled();

    q->close();
}

void CustomGoalWidgetPrivate::OnAcceptClicked()
{
    Q_Q(UI::CustomGoalWidget);

    emit q->ChangesAccepted();

    q->close();
}
