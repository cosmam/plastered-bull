#include "yeargoalwidget.h"
#include "yeargoalwidget_p.h"

#include "yeargoal.h"
#include "ui_yeargoalwidget.h"

#include <QColorDialog>

using namespace UI;

YearGoalWidget::YearGoalWidget(QWidget *parent) :
    GoalWidgetBase(parent),
    d_ptr( new YearGoalWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);
}

YearGoalWidget::~YearGoalWidget()
{
    delete d_ptr;
}

void YearGoalWidget::SetupWidget( const Data::Goal * inGoal )
{
    const Data::YearGoal * goal = qobject_cast<const Data::YearGoal *>( inGoal );

    if( goal != NULL ) {
        Q_D(UI::YearGoalWidget);
        d->SetupWidget( goal );
    }
}

QString YearGoalWidget::Name() const
{
    Q_D(const UI::YearGoalWidget);
    return d->Name();
}

QColor YearGoalWidget::Color() const
{
    Q_D(const UI::YearGoalWidget);
    return d->color;
}

int YearGoalWidget::Year() const
{
    Q_D(const UI::YearGoalWidget);
    return d->Year();
}

/**************** Private Class ***************/

YearGoalWidgetPrivate::YearGoalWidgetPrivate(YearGoalWidget *parent) :
    QObject(parent),
    ui(new Ui::YearGoalWidget),
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

YearGoalWidgetPrivate::~YearGoalWidgetPrivate()
{
    delete ui;
}

void YearGoalWidgetPrivate::SetupWidget( const Data::YearGoal * goal )
{
    ui->name_LineEdit->setText( goal->name() );
    OnColorSelected( goal->color() );
    ui->year_SpinBox->setValue( goal->year() );
}

QString YearGoalWidgetPrivate::Name() const
{
    return ui->name_LineEdit->text();
}

int YearGoalWidgetPrivate::Year() const
{
    return ui->year_SpinBox->value();
}

void YearGoalWidgetPrivate::OnColorButtonClicked()
{
    Q_Q(UI::YearGoalWidget);

    colorDialog = new QColorDialog( color, q );

    connect( colorDialog, SIGNAL(colorSelected(QColor)),
             this, SLOT(OnColorSelected(QColor)));

    colorDialog->show();
}

void YearGoalWidgetPrivate::OnColorSelected( const QColor & inColor )
{
    color = inColor;
    QString style = "QPushButton { background: " + color.name() + "; }";
    ui->btn_Color->setStyleSheet( style );
}

void YearGoalWidgetPrivate::OnCancelClicked()
{
    Q_Q(UI::YearGoalWidget);

    emit q->ChangesCanceled();

    q->close();
}

void YearGoalWidgetPrivate::OnAcceptClicked()
{
    Q_Q(UI::YearGoalWidget);

    emit q->ChangesAccepted();

    q->close();
}
