#include "weekgoalwidget.h"
#include "weekgoalwidget_p.h"

#include "weekgoal.h"
#include "ui_weekgoalwidget.h"

#include <QColorDialog>

using namespace UI;

/**
 * @author Cosmam
 * @name WeekGoalWidget
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent widget
 **/
WeekGoalWidget::WeekGoalWidget(QWidget *parent) :
    GoalWidgetBase(parent),
    d_ptr( new WeekGoalWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);
}

/**
 * @author Cosmam
 * @name ~WeekGoalWidget
 * @namespace UI
 * @brief Destructor
 **/
WeekGoalWidget::~WeekGoalWidget()
{
    delete d_ptr;
}

/**
 * @author Cosmam
 * @name SetupWidget
 * @namespace UI
 * @brief Sets up this widget based on the goal data
 * @param inGoal: The goal to base the widget data on
 **/
void WeekGoalWidget::SetupWidget( const Data::Goal * inGoal )
{
    const Data::WeekGoal * goal = qobject_cast<const Data::WeekGoal *>( inGoal );

    if( goal != NULL ) {
        Q_D(UI::WeekGoalWidget);
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
QString WeekGoalWidget::Name() const
{
    Q_D(const UI::WeekGoalWidget);
    return d->Name();
}

/**
 * @author Cosmam
 * @name Coloe
 * @namespace UI
 * @brief Gets the goal color
 * @return The goal color
 **/
QColor WeekGoalWidget::Color() const
{
    Q_D(const UI::WeekGoalWidget);
    return d->color;
}

/**
 * @author Cosmam
 * @name StartDate
 * @namespace UI
 * @brief Gets the start date
 * @return The start date
 **/
QDate WeekGoalWidget::StartDate() const
{
    Q_D(const UI::WeekGoalWidget);
    return d->StartDate();
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name CustomGoalWidget
 * @namespace UI
 * @brief WeekGoalWidgetPrivate::WeekGoalWidgetPrivate
 * @param parent
 **/
WeekGoalWidgetPrivate::WeekGoalWidgetPrivate(WeekGoalWidget *parent) :
    QObject(parent),
    ui(new Ui::WeekGoalWidget),
    q_ptr(parent)
{
    ui->setupUi(q_ptr);

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
 * @name ~WeekGoalWidgetPrivate
 * @namespace UI
 * @brief Destructor
 **/
WeekGoalWidgetPrivate::~WeekGoalWidgetPrivate()
{
    delete ui;
}

/**
 * @author Cosmam
 * @name SetupWidget
 * @namespace UI
 * @brief Sets up this widget based on goal data
 * @param goal: The goal data
 **/
void WeekGoalWidgetPrivate::SetupWidget( const Data::WeekGoal * goal )
{
    ui->name_LineEdit->setText( goal->name() );
    OnColorSelected( goal->color() );
    ui->startDate_DateEdit->setDate( goal->startDate() );
}

/**
 * @author Cosmam
 * @name Name
 * @namespace UI
 * @brief Gets the goal name
 * @return The goal name
 **/
QString WeekGoalWidgetPrivate::Name() const
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
QDate WeekGoalWidgetPrivate::StartDate() const
{
    return ui->startDate_DateEdit->date();
}

/**
 * @author Cosmam
 * @name SetToDefaults
 * @namespace UI
 * @brief Sets widget data to defaults
 **/
void WeekGoalWidgetPrivate::SetToDefaults()
{
    ui->name_LineEdit->setText("");
    OnColorSelected(QColor(0,0,0));
    ui->startDate_DateEdit->setDate(QDate::currentDate());
}

/**
 * @author Cosmam
 * @name OnColorButtonClicked
 * @namespace UI
 * @brief Slot called when the color button is clicked
 **/
void WeekGoalWidgetPrivate::OnColorButtonClicked()
{
    Q_Q(UI::WeekGoalWidget);

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
void WeekGoalWidgetPrivate::OnColorSelected( const QColor & inColor )
{
    color = inColor;
    QString style = "QPushButton { background-color: " + color.name() + "; }";
    ui->btn_Color->setStyleSheet( style );
}

/**
 * @author Cosmam
 * @name OnCancelClicked
 * @namespace UI
 * @brief Slot called when cancel is clicked
 **/
void WeekGoalWidgetPrivate::OnCancelClicked()
{
    Q_Q(UI::WeekGoalWidget);

    emit q->ChangesCanceled();

    q->close();
}

/**
 * @author Cosmam
 * @name OnAcceptClicked
 * @namespace UI
 * @brief Slot called when accept is clicked
 **/
void WeekGoalWidgetPrivate::OnAcceptClicked()
{
    Q_Q(UI::WeekGoalWidget);

    emit q->ChangesAccepted();

    q->close();
}
