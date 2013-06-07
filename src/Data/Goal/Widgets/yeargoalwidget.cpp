#include "yeargoalwidget.h"
#include "yeargoalwidget_p.h"

#include "yeargoal.h"
#include "ui_yeargoalwidget.h"

#include <QColorDialog>

using namespace UI;

/**
 * @author Cosmam
 * @name YearGoalWidget
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent widget
 **/
YearGoalWidget::YearGoalWidget(QWidget *parent) :
    GoalWidgetBase(parent),
    d_ptr( new YearGoalWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);
}

/**
 * @author Cosmam
 * @name ~YearGoalWidget
 * @namespace UI
 * @brief Destructor
 **/
YearGoalWidget::~YearGoalWidget()
{
    delete d_ptr;
}

/**
 * @author Cosmam
 * @name ~WeekGoalWidgetPrivate
 * @namespace UI
 * @brief YearGoalWidget::SetupWidget
 * @param inGoal
 */
void YearGoalWidget::SetupWidget( const Data::Goal * inGoal )
{
    const Data::YearGoal * goal = qobject_cast<const Data::YearGoal *>( inGoal );

    if( goal != NULL ) {
        Q_D(UI::YearGoalWidget);
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
QString YearGoalWidget::Name() const
{
    Q_D(const UI::YearGoalWidget);
    return d->Name();
}

/**
 * @author Cosmam
 * @name Color
 * @namespace UI
 * @brief Gets the goal color
 * @return The goal color
 **/
QColor YearGoalWidget::Color() const
{
    Q_D(const UI::YearGoalWidget);
    return d->color;
}

/**
 * @author Cosmam
 * @name Year
 * @namespace UI
 * @brief Gets the goal year
 * @return The goal year
 **/
int YearGoalWidget::Year() const
{
    Q_D(const UI::YearGoalWidget);
    return d->Year();
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name YearGoalWidgetPrivate
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent YearGoalWidget
 **/
YearGoalWidgetPrivate::YearGoalWidgetPrivate(YearGoalWidget *parent) :
    QObject(parent),
    ui(new Ui::YearGoalWidget),
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
 * @name ~YearGoalWidgetPrivate
 * @namespace UI
 * @brief Destructor
 **/
YearGoalWidgetPrivate::~YearGoalWidgetPrivate()
{
    delete ui;
}

/**
 * @author Cosmam
 * @name ~WeekGoalWidgetPrivate
 * @namespace UI
 * @brief YearGoalWidgetPrivate::SetupWidget
 * @param goal
 **/
void YearGoalWidgetPrivate::SetupWidget( const Data::YearGoal * goal )
{
    ui->name_LineEdit->setText( goal->name() );
    OnColorSelected( goal->color() );
    ui->year_SpinBox->setValue( goal->year() );
}

/**
 * @author Cosmam
 * @name Name
 * @namespace UI
 * @brief Gets the goal name
 * @return The goal name
 **/
QString YearGoalWidgetPrivate::Name() const
{
    return ui->name_LineEdit->text();
}

/**
 * @author Cosmam
 * @name Year
 * @namespace UI
 * @brief Gets the goal year
 * @return The goal year
 **/
int YearGoalWidgetPrivate::Year() const
{
    return ui->year_SpinBox->value();
}

/**
 * @author Cosmam
 * @name SetToDefaults
 * @namespace UI
 * @brief Sets widget data to defaults
 **/
void YearGoalWidgetPrivate::SetToDefaults()
{
    ui->name_LineEdit->setText("");
    OnColorSelected(QColor(0,0,0));
    ui->year_SpinBox->setValue(QDate::currentDate().year());
}

/**
 * @author Cosmam
 * @name OnColorButtonClicked
 * @namespace UI
 * @brief Slot called when the color button is clicked
 **/
void YearGoalWidgetPrivate::OnColorButtonClicked()
{
    Q_Q(UI::YearGoalWidget);

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
void YearGoalWidgetPrivate::OnColorSelected( const QColor & inColor )
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
void YearGoalWidgetPrivate::OnCancelClicked()
{
    Q_Q(UI::YearGoalWidget);

    emit q->ChangesCanceled();

    q->close();
}

/**
 * @author Cosmam
 * @name OnAcceptClicked
 * @namespace UI
 * @brief Slot called when accept is clicked
 **/
void YearGoalWidgetPrivate::OnAcceptClicked()
{
    Q_Q(UI::YearGoalWidget);

    emit q->ChangesAccepted();

    q->close();
}
