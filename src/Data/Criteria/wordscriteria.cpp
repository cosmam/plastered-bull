#include "wordscriteria.h"

#include "wordscriteria_p.h"
#include "wordscriteriawidget.h"

using namespace Data;

/**
 * @author Cosmam
 * @name WordsCriteria
 * @namespace Data
 * @brief Default constructor
 * @param parent: The parent object
 **/
WordsCriteria::WordsCriteria(QObject *parent) :
    Criteria(*new Data::WordsCriteriaPrivate, parent)
{
    Q_D(Data::WordsCriteria);
    d->setParent(this);
    d->q_ptr = this;
    d->init();
}

/**
 * @author Cosmam
 * @name ~WordsCriteria
 * @namespace Data
 * @brief Destructor
 **/
WordsCriteria::~WordsCriteria()
{
}

/**
 * @author Cosmam
 * @name setWords
 * @namespace Data
 * @brief Sets the number of words
 * @param words:  The number of words
 **/
void WordsCriteria::setWords(int words)
{
    if( words >= 0 ) {
        Q_D(Data::WordsCriteria);
        d->m_words = words;
    }
}

/**
 * @author Cosmam
 * @name words
 * @namespace Data
 * @brief Gets the number of words
 * @return The number of words for the goal
 **/
int WordsCriteria::words() const
{
	Q_D(const Data::WordsCriteria);
	return d->m_words;
}

/**
 * @author Cosmam
 * @name Met
 * @namespace Data
 * @brief Checks if this criteria meets the bar set by the other
 * @param other: The other criteria
 * @return Whether or not this criteria meets the other
 **/
bool WordsCriteria::Met(const Criteria * other) const
{
	const WordsCriteria * otherWords = qobject_cast<const WordsCriteria *>(other);

    if( otherWords == NULL )
		return false;
		
	Q_D(const Data::WordsCriteria);

	return ( d->m_words >= otherWords->words() );
}

/**
 * @author Cosmam
 * @name CreateWidget
 * @namespace Data
 * @brief Creates the criteria widget
 * @return The criteria widget
 **/
UI::CriteriaWidgetBase * WordsCriteria::CreateWidget()
{
    Q_D(Data::WordsCriteria);

    d->m_widget = new UI::WordsCriteriaWidget();

    d->m_widget->SetupWidget( this );

    return d->m_widget;
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name WordsCriteriaPrivate
 * @namespace Data
 * @brief Default constructor
 **/
WordsCriteriaPrivate::WordsCriteriaPrivate() :
    CriteriaPrivate(),
    m_words(0)
{
}

/**
 * @author Cosmam
 * @name ~WordsCriteriaPrivate
 * @namespace Data
 * @brief Destructor
 */
WordsCriteriaPrivate::~WordsCriteriaPrivate()
{
}

/**
 * @author Cosmam
 * @name init
 * @namespace Data
 * @brief Initializes this widget
 **/
void WordsCriteriaPrivate::init()
{
}

/************* External Functions *************/

/**
 * @author Cosmam
 * @name operator <<
 * @brief QDataStream output operator
 * @param out: The QDataStream ouput operator
 * @param criteria: The criteria to output
 * @return A reference to the QDataStream object
 **/
QDataStream & operator<<(QDataStream & out, const WordsCriteria & criteria)
{
    return out;
}

/**
 * @author Cosmam
 * @name operator>>
 * @brief QDataStream input operator
 * @param in: The QDataStream input operator
 * @param criteria: The criteria to input to
 * @return A reference to the QDataStream object
 **/
QDataStream & operator>>(QDataStream & in, WordsCriteria & criteria)
{
    return in;
}
