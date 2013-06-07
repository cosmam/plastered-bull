#include "pagescriteriawidget.h"
#include "pagescriteriawidget_p.h"

#include "pagescriteria.h"
#include "ui_pagescriteriawidget.h"

using namespace UI;

/**
 * @author Cosmam
 * @name PagesCriteriaWidget
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent widget
 **/
PagesCriteriaWidget::PagesCriteriaWidget(QWidget *parent) :
    CriteriaWidgetBase(parent),
    d_ptr( new PagesCriteriaWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);
}

/**
 * @author Cosmam
 * @name ~PagesCriteriaWidget
 * @namespace UI
 * @brief Destructor
 **/
PagesCriteriaWidget::~PagesCriteriaWidget()
{
    delete d_ptr;
}

/**
 * @author Cosmam
 * @name Pages
 * @namespace UI
 * @brief Gets the page count
 * @return The page count
 **/
int PagesCriteriaWidget::Pages() const
{
//	Q_D(const UI::PagesCriteriaWidget);
	return 0;
}

/**
 * @author Cosmam
 * @name SetupWidget
 * @namespace UI
 * @brief Sets up the widget based on the criteria
 * @param inCriteria: The criteria to base the widget one
 **/
void PagesCriteriaWidget::SetupWidget( const Data::Criteria * inCriteria )
{
    const Data::PagesCriteria * criteria = qobject_cast<const Data::PagesCriteria *>( inCriteria );
	
    if( criteria != NULL ) {
        Q_D(UI::PagesCriteriaWidget);
    }
}

/**
 * @author Cosmam
 * @name isValid
 * @namespace UI
 * @brief Determines whether or not the information is valid
 * @return Whether or not the goal information falls into valid ranges
 **/
bool PagesCriteriaWidget::isValid() const
{
//	Q_D(const UI::PagesCriteiaWidget);
	return true;
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name PagesCriteriaPrivate
 * @namespace UI
 * @brief Default constructor
 * @param parent: The PagesCriteria parent
 **/
PagesCriteriaWidgetPrivate::PagesCriteriaWidgetPrivate(PagesCriteriaWidget *parent) :
    QObject(parent),
    ui(new Ui::PagesCriteriaWidget),
    q_ptr(parent)
{
    ui->setupUi(q_ptr);

    QValidator * validator = new QDoubleValidator(0.0,1000000.0,1);

    ui->pages_LineEdit->setValidator(validator);
}

/**
 * @author Cosmam
 * @name ~PagesCriteriaWidgetPrivate
 * @namespace UI
 * @brief Destructor
 **/
PagesCriteriaWidgetPrivate::~PagesCriteriaWidgetPrivate()
{
    delete ui;
}
