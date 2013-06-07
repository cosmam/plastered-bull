#include "pagescriteria.h"

#include "pagescriteria_p.h"
#include "pagescriteriawidget.h"

using namespace Data;

/**
 * @author Cosmam
 * @name PagesCriteria
 * @namespace Data
 * @brief Default constructor
 * @param parent: The parent object
 **/
PagesCriteria::PagesCriteria(QObject *parent) :
    Criteria(*new Data::PagesCriteriaPrivate, parent)
{
    Q_D(Data::PagesCriteria);
    d->setParent(this);
    d->q_ptr = this;
    d->init();
}

/**
 * @author Cosmam
 * @name ~PagesCriteria
 * @namespace Data
 * @brief Destructor
 **/
PagesCriteria::~PagesCriteria()
{
}

/**
 * @author Cosmam
 * @name setPages
 * @namespace Data
 * @brief Sets the page count
 * @param pages: The number of pages
 **/
void PagesCriteria::setPages(int pages)
{
    if( pages >= 0 ) {
        Q_D(Data::PagesCriteria);
        d->m_pages = pages;
    }
}

/**
 * @author Cosmam
 * @name pages
 * @namespace Data
 * @brief Gets the page count
 * @return The page count
 */
int PagesCriteria::pages() const
{
	Q_D(const Data::PagesCriteria);
	return d->m_pages;
}

/**
 * @author Cosmam
 * @name Met
 * @namespace Data
 * @brief Checks if this criteria meets the bar set by the other
 * @param other: The other criteria
 * @return Whether or not this criteria meets that set by the other
 */
bool PagesCriteria::Met(const Criteria * other) const
{
	const PagesCriteria * otherPages = qobject_cast<const PagesCriteria *>(other);
	
    if( !otherPages )
		return false;
		
	Q_D(const Data::PagesCriteria);
		
	return ( d->m_pages >= otherPages->pages() );
}

/**
 * @author Cosmam
 * @name CreateWidget
 * @namespace Data
 * @brief Creates the criteria widget
 * @return The criteria widget
 **/
UI::CriteriaWidgetBase * PagesCriteria::CreateWidget()
{
    Q_D(Data::PagesCriteria);

    d->m_widget = new UI::PagesCriteriaWidget();

    d->m_widget->SetupWidget( this );

    return d->m_widget;
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name PagesCriteriaPrivate
 * @namespace Data
 * @brief Default constructor
 **/
PagesCriteriaPrivate::PagesCriteriaPrivate() :
    CriteriaPrivate(),
    m_pages(0)
{
}

/**
 * @author Cosmam
 * @name ~PagesCriteriaPrivate
 * @namespace Data
 * @brief Destructor
 **/
PagesCriteriaPrivate::~PagesCriteriaPrivate()
{
}

/**
 * @author Cosmam
 * @name init
 * @namespace Data
 * @brief Initializes this widget
 **/
void PagesCriteriaPrivate::init()
{
}

/************* External Functions *************/

/**
 * @author Cosmam
 * @name operator<<
 * @brief QDataStream output operator
 * @param out: The QDataStream output operator
 * @param criteria: The criteria to output
 * @return A reference to the QDataStream operator
 **/
QDataStream & operator<<(QDataStream & out, const PagesCriteria & criteria)
{
    return out;
}

/**
 * @author Cosmam
 * @name operator >>
 * @brief QDataStream input operator
 * @param in: The QDataStream input operator
 * @param criteria: The criteria to input to
 * @return A reference to the QDataStream operator
 **/
QDataStream & operator>>(QDataStream & in, PagesCriteria & criteria)
{
    return in;
}
