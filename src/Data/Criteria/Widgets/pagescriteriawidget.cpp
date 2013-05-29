#include "pagescriteriawidget.h"
#include "pagescriteriawidget_p.h"

#include "pagescriteria.h"
#include "ui_pagescriteriawidget.h"

using namespace UI;

PagesCriteriaWidget::PagesCriteriaWidget(QWidget *parent) :
    CriteriaWidgetBase(parent),
    d_ptr( new PagesCriteriaWidgetPrivate(this) )
{
    this->setAttribute(Qt::WA_DeleteOnClose);
}

PagesCriteriaWidget::~PagesCriteriaWidget()
{
    delete d_ptr;
}

int PagesCriteriaWidget::Pages() const
{
//	Q_D(const UI::PagesCriteriaWidget);
	return 0;
}

void PagesCriteriaWidget::SetupWidget( const Data::Criteria * inCriteria )
{
    const Data::PagesCriteria * criteria = qobject_cast<const Data::PagesCriteria *>( inCriteria );
	
    if( criteria != NULL ) {
        Q_D(UI::PagesCriteriaWidget);
    }
}

bool PagesCriteriaWidget::isValid() const
{
//	Q_D(const UI::PagesCriteiaWidget);
	return true;
}

/**************** Private Class ***************/

PagesCriteriaWidgetPrivate::PagesCriteriaWidgetPrivate(PagesCriteriaWidget *parent) :
    QObject(parent),
    ui(new Ui::PagesCriteriaWidget),
    q_ptr(parent)
{
    ui->setupUi(q_ptr);

    QValidator * validator = new QDoubleValidator(0.0,1000000.0,1);

    ui->pages_LineEdit->setValidator(validator);
}

PagesCriteriaWidgetPrivate::~PagesCriteriaWidgetPrivate()
{
    delete ui;
}
