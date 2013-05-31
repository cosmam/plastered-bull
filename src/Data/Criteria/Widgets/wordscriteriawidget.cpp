#include "wordscriteriawidget.h"
#include "wordscriteriawidget_p.h"

#include "wordscriteria.h"
#include "ui_wordscriteriawidget.h"

using namespace UI;

WordsCriteriaWidget::WordsCriteriaWidget(QWidget *parent) :
    CriteriaWidgetBase(parent),
    d_ptr( new WordsCriteriaWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);
}

WordsCriteriaWidget::~WordsCriteriaWidget()
{
    delete d_ptr;
}

int WordsCriteriaWidget::Words() const
{
//	Q_D(const UI::WordsCriteriaWidget);
	return 0;
}

void WordsCriteriaWidget::SetupWidget( const Data::Criteria * inCriteria )
{
    const Data::WordsCriteria * criteria = qobject_cast<const Data::WordsCriteria *>( inCriteria );
	
    if( criteria != NULL ) {
        Q_D(UI::WordsCriteriaWidget);
    }
}

bool WordsCriteriaWidget::isValid() const
{
//	Q_D(const UI::WordsCriteiaWidget);
	return true;
}

/**************** Private Class ***************/

WordsCriteriaWidgetPrivate::WordsCriteriaWidgetPrivate(WordsCriteriaWidget *parent) :
    QObject(parent),
    ui(new Ui::WordsCriteriaWidget),
    q_ptr(parent)
{
    ui->setupUi(q_ptr);

    QValidator * validator = new QIntValidator(0,1000000000);

    ui->words_LineEdit->setValidator(validator);
}

WordsCriteriaWidgetPrivate::~WordsCriteriaWidgetPrivate()
{
    delete ui;
}
