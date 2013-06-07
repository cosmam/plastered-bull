#include "monthgoalwidget.h"
#include "monthgoalwidget_p.h"

#include "monthgoal.h"
#include "ui_monthgoalwidget.h"

#include <QColorDialog>

using namespace UI;

/**
 * @author Cosmam
 * @name MonthGoalWidget
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent widget
 **/
MonthGoalWidget::MonthGoalWidget(QWidget *parent) :
    GoalWidgetBase(parent),
    d_ptr( new MonthGoalWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);
}

/**
 * @author Cosmam
 * @name ~MonthGoalWidget
 * @namespace UI
 * @brief Destructor
 **/
MonthGoalWidget::~MonthGoalWidget()
{
    delete d_ptr;
}

/**
 * @author Cosmam
 * @name SetupWidget
 * @namespace UI
 * @brief Sets up the widget based on the goal data
 * @param inGoal
 **/
void MonthGoalWidget::SetupWidget( const Data::Goal * inGoal )
{
    const Data::MonthGoal * goal = qobject_cast<const Data::MonthGoal *>( inGoal );
	
    if( goal != NULL ) {
        Q_D(UI::MonthGoalWidget);
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
QString MonthGoalWidget::Name() const
{
    Q_D(const UI::MonthGoalWidget);
    return d->Name();
}

/**
 * @author Cosmam
 * @name Color
 * @namespace UI
 * @brief Gets the goal color
 * @return The goal color
 **/
QColor MonthGoalWidget::Color() const
{
    Q_D(const UI::MonthGoalWidget);
    return d->color;
}

/**
 * @author Cosmam
 * @name Month
 * @namespace UI
 * @brief Gets the goal month
 * @return The goal month
 **/
Time::Month MonthGoalWidget::Month() const
{
    Q_D(const UI::MonthGoalWidget);
    return d->Month();
}

/**
 * @author Cosmam
 * @name Year
 * @namespace UI
 * @brief Gets the goal year
 * @return The goal year
 **/
int MonthGoalWidget::Year() const
{
    Q_D(const UI::MonthGoalWidget);
    return d->Year();
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name MonthGoalWidgetPrivate
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent MonthGoalWidget
 **/
MonthGoalWidgetPrivate::MonthGoalWidgetPrivate(MonthGoalWidget *parent) :
    QObject(parent),
    ui(new Ui::MonthGoalWidget),
    q_ptr(parent)
{
    ui->setupUi(q_ptr);

    ui->year_SpinBox->setMinimum(2010);
    ui->year_SpinBox->setMaximum(2100);

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
 * @name ~MonthGoalPrivate
 * @namespace UI
 * @brief Destructor
 **/
MonthGoalWidgetPrivate::~MonthGoalWidgetPrivate()
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
void MonthGoalWidgetPrivate::SetupWidget( const Data::MonthGoal * goal )
{
    ui->name_LineEdit->setText( goal->name() );
    OnColorSelected( goal->color() );
    ui->month_ComboBox->setCurrentIndex( Time::ToInt( goal->month() ) );
    ui->year_SpinBox->setValue( goal->year() );
}

/**
 * @author Cosmam
 * @name Name
 * @namespace UI
 * @brief Gets the goal name
 * @return The goal name
 **/
QString MonthGoalWidgetPrivate::Name() const
{
    return ui->name_LineEdit->text();
}

/**
 * @author Cosmam
 * @name Month
 * @namespace UI
 * @brief Gets the goal month
 * @return The goal month
 **/
Time::Month MonthGoalWidgetPrivate::Month() const
{
    return Time::ToMonth( ui->month_ComboBox->currentIndex() );
}

/**
 * @author Cosmam
 * @name Year
 * @namespace UI
 * @brief Gets the goal year
 * @return The goal year
 **/
int MonthGoalWidgetPrivate::Year() const
{
    return ui->year_SpinBox->value();
}

/**
 * @author Cosmam
 * @name SetToDefaults
 * @namespace UI
 * @brief Sets widget data to defaults
 **/
void MonthGoalWidgetPrivate::SetToDefaults()
{
    ui->name_LineEdit->setText("");
    OnColorSelected(QColor(0,0,0));
    ui->month_ComboBox->setCurrentIndex(0);
    ui->year_SpinBox->setValue(QDate::currentDate().year());
}

/**
 * @author Cosmam
 * @name OnColorButtonClicked
 * @namespace UI
 * @brief Slot called when the color button is clicked
 **/
void MonthGoalWidgetPrivate::OnColorButtonClicked()
{
    Q_Q(UI::MonthGoalWidget);

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
void MonthGoalWidgetPrivate::OnColorSelected( const QColor & inColor )
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
void MonthGoalWidgetPrivate::OnCancelClicked()
{
    Q_Q(UI::MonthGoalWidget);

    emit q->ChangesCanceled();

    q->close();
}

/**
 * @author Cosmam
 * @name OnAcceptClicked
 * @namespace UI
 * @brief Slot called when accept is clicked
 **/
void MonthGoalWidgetPrivate::OnAcceptClicked()
{
    Q_Q(UI::MonthGoalWidget);

    emit q->ChangesAccepted();

    q->close();
}
