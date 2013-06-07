#include "customgoalwidget.h"
#include "customgoalwidget_p.h"

#include "customgoal.h"
#include "ui_customgoalwidget.h"

#include <QColorDialog>

using namespace UI;

/**
 * @author Cosmam
 * @name CustomGoalWidget
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent widget
 **/
CustomGoalWidget::CustomGoalWidget(QWidget *parent) :
    GoalWidgetBase(parent),
    d_ptr( new CustomGoalWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);	
}

/**
 * @author Cosmam
 * @name ~CustomGoalWidget
 * @namespace UI
 * @brief Destructor
 **/
CustomGoalWidget::~CustomGoalWidget()
{
    delete d_ptr;
}

/**
 * @author Cosmam
 * @name SetupWidget
 * @namespace UI
 * @brief Sets this widget up based on the goal data
 * @param inGoal
 **/
void CustomGoalWidget::SetupWidget( const Data::Goal * inGoal )
{
    const Data::CustomGoal * goal = qobject_cast<const Data::CustomGoal *>( inGoal );

    if( goal != NULL ) {
        Q_D(UI::CustomGoalWidget);
        d->SetupWidget( goal );
    }
}

/**
 * @author Cosmam
 * @name Name
 * @namespace UI
 * @brief Gets the goal name
 * @return The goal name
 **/
QString CustomGoalWidget::Name() const
{
    Q_D(const UI::CustomGoalWidget);
    return d->Name();
}

/**
 * @author Cosmam
 * @name Color
 * @namespace UI
 * @brief Gets the goal color
 * @return The goal color
 **/
QColor CustomGoalWidget::Color() const
{
    Q_D(const UI::CustomGoalWidget);
    return d->color;
}

/**
 * @author Cosmam
 * @name StartDate
 * @namespace UI
 * @brief Gets the goal start date
 * @return The goal start date
 **/
QDate CustomGoalWidget::StartDate() const
{
    Q_D(const UI::CustomGoalWidget);
    return d->StartDate();
}

/**
 * @author Cosmam
 * @name Duration
 * @namespace UI
 * @brief Gets the goal duration
 * @return The goal duration
 **/
int CustomGoalWidget::Duration() const
{
    Q_D(const UI::CustomGoalWidget);
    return d->Duration();
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name CustomGoalWidgetPrivate
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent CustomGoalWidget
 **/
CustomGoalWidgetPrivate::CustomGoalWidgetPrivate(CustomGoalWidget *parent) :
    QObject(parent),
    ui(new Ui::CustomGoalWidget),
    q_ptr(parent)
{
    ui->setupUi(q_ptr);

    connect( ui->startDate_DateEdit, SIGNAL(dateChanged(QDate)),
         this, SLOT(OnStartDateChanged(QDate)));

    SetToDefaults();

    connect( ui->btn_Cancel, SIGNAL(clicked()),
             this, SLOT(OnCancelClicked()) );
    connect( ui->btn_Accept, SIGNAL(clicked()),
             this, SLOT(OnAcceptClicked()) );
    connect( ui->btn_Color, SIGNAL(clicked()),
             this, SLOT(OnColorButtonClicked()) );
}

/**
 * @author Cosmam
 * @name ~CustomGoalWidgetPrivate
 * @namespace UI
 * @brief Destructor
 **/
CustomGoalWidgetPrivate::~CustomGoalWidgetPrivate()
{
    delete ui;
}

/**
 * @author Cosmam
 * @name SetupWidget
 * @namespace UI
 * @brief Sets up the custom goal widget
 * @param goal: The goal information to set up the widget with
 **/
void CustomGoalWidgetPrivate::SetupWidget( const Data::CustomGoal * goal )
{
    ui->name_LineEdit->setText( goal->name() );
    OnColorSelected( goal->color() );
    ui->startDate_DateEdit->setDate( goal->startDate() );
    ui->endDate_DateEdit->setDate( goal->end().date() );
}

/**
 * @author Cosmam
 * @name Name
 * @namespace UI
 * @brief Gets the goal name
 * @return The goal name
 **/
QString CustomGoalWidgetPrivate::Name() const
{
    return ui->name_LineEdit->text();
}

/**
 * @author Cosmam
 * @name StartDate
 * @namespace UI
 * @brief Gets the goal start date
 * @return The goal start date
 **/
QDate CustomGoalWidgetPrivate::StartDate() const
{
    return ui->startDate_DateEdit->date();
}

/**
 * @author Cosmam
 * @name Duration
 * @namespace UI
 * @brief Gets the goal duration
 * @return The goal duration
 **/
int CustomGoalWidgetPrivate::Duration() const
{
    return ui->startDate_DateEdit->date().daysTo( ui->endDate_DateEdit->date() );
}

/**
 * @author Cosmam
 * @name SetToDefaults
 * @namespace UI
 * @brief Sets widget data to defaults
 **/
void CustomGoalWidgetPrivate::SetToDefaults()
{
    ui->name_LineEdit->setText("");
    OnColorSelected(QColor(0,0,0));
    ui->startDate_DateEdit->setDate(QDate::currentDate());
    ui->endDate_DateEdit->setDate(QDate::currentDate());
}

/**
 * @author Cosmam
 * @name OnColorButtonClicked
 * @namespace UI
 * @brief Slot called when the color button is clicked
 **/
void CustomGoalWidgetPrivate::OnColorButtonClicked()
{
    Q_Q(UI::CustomGoalWidget);

    colorDialog = new QColorDialog( color, q );

    connect( colorDialog, SIGNAL(colorSelected(QColor)),
             this, SLOT(OnColorSelected(QColor)));

    colorDialog->show();
}

/**
 * @author Cosmam
 * @name OnColorSelected
 * @namespace UI
 * @brief Slot called when a color is slected
 * @param inColor: the selected color
 **/
void CustomGoalWidgetPrivate::OnColorSelected( const QColor & inColor )
{
    color = inColor;
    QString style = "QPushButton { background-color: " + color.name() + "; }";
    ui->btn_Color->setStyleSheet( style );
}

/**
 * @author Cosmam
 * @name OnStartDateChanged
 * @namespace UI
 * @brief Slot called when the start date is changed
 * @param date: The new start date
 **/
void CustomGoalWidgetPrivate::OnStartDateChanged( const QDate & date )
{
    ui->endDate_DateEdit->setMinimumDate( date );
}

/**
 * @author Cosmam
 * @name OnCancelClicked
 * @namespace UI
 * @brief Slot called when cancel is clicked
 **/
void CustomGoalWidgetPrivate::OnCancelClicked()
{
    Q_Q(UI::CustomGoalWidget);

    emit q->ChangesCanceled();

    q->close();
}

/**
 * @author Cosmam
 * @name OnAcceptClicked
 * @namespace UI
 * @brief Slot called when accept is clicked
 **/
void CustomGoalWidgetPrivate::OnAcceptClicked()
{
    Q_Q(UI::CustomGoalWidget);

    emit q->ChangesAccepted();

    q->close();
}
