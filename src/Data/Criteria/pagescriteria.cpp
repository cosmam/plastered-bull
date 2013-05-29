#include "pagescriteria.h"

#include "pagescriteria_p.h"
#include "pagescriteriawidget.h"

using namespace Data;

PagesCriteria::PagesCriteria(QObject *parent) :
    Criteria(*new Data::PagesCriteriaPrivate, parent)
{
    Q_D(Data::PagesCriteria);
    d->setParent(this);
    d->q_ptr = this;
    d->init();
}

PagesCriteria::~PagesCriteria()
{
}
	    
void PagesCriteria::setPages(int pages)
{
	Q_D(Data::PagesCriteria);
	d->m_pages = pages;
}

int PagesCriteria::pages() const
{
	Q_D(const Data::PagesCriteria);
	return d->m_pages;
}

bool PagesCriteria::Met(const Criteria * other) const
{
	const PagesCriteria * otherPages = qobject_cast<const PagesCriteria *>(other);
	
	if( !other )
		return false;
		
	Q_D(const Data::PagesCriteria);
		
	return ( d->m_pages >= otherPages->pages() );
}

UI::CriteriaWidgetBase * PagesCriteria::CreateWidget()
{
    Q_D(Data::PagesCriteria);

    d->m_widget = new UI::PagesCriteriaWidget();

    d->m_widget->SetupWidget( this );

    return d->m_widget;
}

/**************** Private Class ***************/

PagesCriteriaPrivate::PagesCriteriaPrivate() :
    CriteriaPrivate(),
    m_pages(0)
{
}

PagesCriteriaPrivate::~PagesCriteriaPrivate()
{
}

void PagesCriteriaPrivate::init()
{
}

/************* External Functions *************/

QDataStream & operator<<(QDataStream & out, const PagesCriteria & goal)
{
    return out;
}

QDataStream & operator>>(QDataStream & in, PagesCriteria & goal)
{
    return in;
}
