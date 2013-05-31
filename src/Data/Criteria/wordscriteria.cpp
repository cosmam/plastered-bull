#include "wordscriteria.h"

#include "wordscriteria_p.h"
#include "wordscriteriawidget.h"

using namespace Data;

WordsCriteria::WordsCriteria(QObject *parent) :
    Criteria(*new Data::WordsCriteriaPrivate, parent)
{
    Q_D(Data::WordsCriteria);
    d->setParent(this);
    d->q_ptr = this;
    d->init();
}

WordsCriteria::~WordsCriteria()
{
}
	    
void WordsCriteria::setWords(int words)
{
	Q_D(Data::WordsCriteria);
	d->m_words = words;
}

int WordsCriteria::words() const
{
	Q_D(const Data::WordsCriteria);
	return d->m_words;
}

bool WordsCriteria::Met(const Criteria * other) const
{
	const WordsCriteria * otherWords = qobject_cast<const WordsCriteria *>(other);
	
	if( !other )
		return false;
		
	Q_D(const Data::WordsCriteria);
		
	return ( d->m_words >= otherWords->words() );
}

UI::CriteriaWidgetBase * WordsCriteria::CreateWidget()
{
    Q_D(Data::WordsCriteria);

    d->m_widget = new UI::WordsCriteriaWidget();

    d->m_widget->SetupWidget( this );

    return d->m_widget;
}

/**************** Private Class ***************/

WordsCriteriaPrivate::WordsCriteriaPrivate() :
    CriteriaPrivate(),
    m_words(0)
{
}

WordsCriteriaPrivate::~WordsCriteriaPrivate()
{
}

void WordsCriteriaPrivate::init()
{
}

/************* External Functions *************/

QDataStream & operator<<(QDataStream & out, const WordsCriteria & goal)
{
    return out;
}

QDataStream & operator>>(QDataStream & in, WordsCriteria & goal)
{
    return in;
}
