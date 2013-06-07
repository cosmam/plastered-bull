#include "daygoalwidget.h"
#include "daygoalwidget_p.h"

#include "daygoal.h"
#include "ui_daygoalwidget.h"

#include <QColorDialog>

using namespace UI;

/**
 * @author Cosmam
 * @name DayGoalWidget
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent widget
 **/
DayGoalWidget::DayGoalWidget(QWidget *parent) :
    GoalWidgetBase(parent),
    d_ptr( new DayGoalWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);
}

/**
 * @author Cosmam
 * @name ~DayGoalWidget
 * @namespace UI
 * @brief Destructor
 **/
DayGoalWidget::~DayGoalWidget()
{
    delete d_ptr;
}

/**
 * @author Cosmam
 * @name SetupWidget
 * @namespace UI
 * @brief Sets this widget up based on the goal data
 * @param inGoal: The goal
 **/
void DayGoalWidget::SetupWidget( const Data::Goal * inGoal )
{
    const Data::DayGoal * goal = qobject_cast<const Data::DayGoal *>( inGoal );
	
    if( goal != NULL ) {
        Q_D(UI::DayGoalWidget);
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
QString DayGoalWidget::Name() const
{
    Q_D(const UI::DayGoalWidget);
    return d->Name();
}

/**
 * @author Cosmam
 * @name Color
 * @namespace UI
 * @brief Gets the goal color
 * @return The goal color
 **/
QColor DayGoalWidget::Color() const
{
    Q_D(const UI::DayGoalWidget);
    return d->color;
}

/**
 * @author Cosmam
 * @name Date
 * @namespace UI
 * @brief Gets the goal date
 * @return The goal date
 **/
QDate DayGoalWidget::Date() const
{
    Q_D(const UI::DayGoalWidget);
    return d->Date();
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name DayGoalWidgetPrivate
 * @namespace UI
 * @brief Default constructor
 * @param parent
 **/
DayGoalWidgetPrivate::DayGoalWidgetPrivate(DayGoalWidget *parent) :
    QObject(parent),
    ui(new Ui::DayGoalWidget),
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
 * @name ~DayGoalWidgetPrivate
 * @namespace UI
 * @brief Destructor
 **/
DayGoalWidgetPrivate::~DayGoalWidgetPrivate()
{
    delete ui;
}

/**
 * @author Cosmam
 * @name SetupWidget
 * @namespace UI
 * @brief Sets up this widget based on the goal data
 * @param goal: The goal data
 **/
void DayGoalWidgetPrivate::SetupWidget( const Data::DayGoal * goal )
{
    ui->name_LineEdit->setText( goal->name() );
    OnColorSelected( goal->color() );
    ui->date_DateEdit->setDate( goal->date() );
}

/**
 * @author Cosmam
 * @name Name
 * @namespace UI
 * @brief Gets the goal name
 * @return The goal name
 **/
QString DayGoalWidgetPrivate::Name() const
{
    return ui->name_LineEdit->text();
}

/**
 * @author Cosmam
 * @name Date
 * @namespace UI
 * @brief Gets the goal date
 * @return The goal date
 **/
QDate DayGoalWidgetPrivate::Date() const
{
    return ui->date_DateEdit->date();
}

/**
 * @author Cosmam
 * @name SetToDefaults
 * @namespace UI
 * @brief Sets the widget data to defaults
 **/
void DayGoalWidgetPrivate::SetToDefaults()
{
    ui->name_LineEdit->setText("");
    OnColorSelected(QColor(0,0,0));
    ui->date_DateEdit->setDate(QDate::currentDate());
}

/**
 * @author Cosmam
 * @name OnColorButtonClicked
 * @namespace UI
 * @brief Slot called when the color button is clicked
 **/
void DayGoalWidgetPrivate::OnColorButtonClicked()
{
    Q_Q(UI::DayGoalWidget);

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
void DayGoalWidgetPrivate::OnColorSelected( const QColor & inColor )
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
void DayGoalWidgetPrivate::OnCancelClicked()
{
    Q_Q(UI::DayGoalWidget);

    emit q->ChangesCanceled();

    q->close();
}

/**
 * @author Cosmam
 * @name OnAcceptClicked
 * @namespace UI
 * @brief Slot called when accept is clicked
 **/
void DayGoalWidgetPrivate::OnAcceptClicked()
{
    Q_Q(UI::DayGoalWidget);

    emit q->ChangesAccepted();

    q->close();
}
