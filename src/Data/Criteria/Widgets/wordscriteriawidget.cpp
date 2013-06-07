#include "wordscriteriawidget.h"
#include "wordscriteriawidget_p.h"

#include "wordscriteria.h"
#include "ui_wordscriteriawidget.h"

using namespace UI;

/**
 * @author Cosmam
 * @name WordsCriteriaWidget
 * @namespace UI
 * @brief Default constructor
 * @param parent: The parent widget
 **/
WordsCriteriaWidget::WordsCriteriaWidget(QWidget *parent) :
    CriteriaWidgetBase(parent),
    d_ptr( new WordsCriteriaWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);
}

/**
 * @author Cosmam
 * @name ~WordsCriteriaWidget
 * @namespace UI
 * @brief Destructor
 **/
WordsCriteriaWidget::~WordsCriteriaWidget()
{
    delete d_ptr;
}

/**
 * @author Cosmam
 * @name Words
 * @namespace UI
 * @brief Gets the number of words
 * @return The number of words
 **/
int WordsCriteriaWidget::Words() const
{
//	Q_D(const UI::WordsCriteriaWidget);
	return 0;
}

/**
 * @author Cosmam
 * @name SetupWidget
 * @namespace UI
 * @brief Sets up the widget based on the criteria
 * @param inCriteria: The criteria to populate the widget with
 **/
void WordsCriteriaWidget::SetupWidget( const Data::Criteria * inCriteria )
{
    const Data::WordsCriteria * criteria = qobject_cast<const Data::WordsCriteria *>( inCriteria );
	
    if( criteria != NULL ) {
        Q_D(UI::WordsCriteriaWidget);
    }
}

/**
 * @author Cosmam
 * @name isValid
 * @namespace UI
 * @brief Determines whether or not the information is valid
 * @return Whether or not the widget criteria is within valid ranges
 **/
bool WordsCriteriaWidget::isValid() const
{
//	Q_D(const UI::WordsCriteiaWidget);
	return true;
}

/**************** Private Class ***************/

/**
 * @author Cosmam
 * @name WordsCriteriaWidgetPrivate
 * @namespace UI
 * @brief Default constructor
 * @param parent: The WordsCriteriaWidget parent
 **/
WordsCriteriaWidgetPrivate::WordsCriteriaWidgetPrivate(WordsCriteriaWidget *parent) :
    QObject(parent),
    ui(new Ui::WordsCriteriaWidget),
    q_ptr(parent)
{
    ui->setupUi(q_ptr);

    QValidator * validator = new QIntValidator(0,1000000000);

    ui->words_LineEdit->setValidator(validator);
}

/**
 * @author Cosmam
 * @name ~WordsCriteriaWidgetPrivate
 * @namespace UI
 * @brief Destructor
 **/
WordsCriteriaWidgetPrivate::~WordsCriteriaWidgetPrivate()
{
    delete ui;
}
