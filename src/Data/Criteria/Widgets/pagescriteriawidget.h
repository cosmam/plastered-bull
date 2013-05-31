#ifndef PAGESCRITERIAWIDGET_H
#define PAGESCRITERIAWIDGET_H

#include "criteriawidgetbase.h"

namespace UI
{

class PagesCriteriaWidgetPrivate;

class PagesCriteriaWidget : public UI::CriteriaWidgetBase
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::PagesCriteriaWidget);
    
public:
    explicit PagesCriteriaWidget(QWidget * parent = NULL);
    ~PagesCriteriaWidget();

    int Pages() const;

    void SetupWidget( const Data::Criteria * inCriteria );

    bool isValid() const;
	
private:

    Q_DISABLE_COPY(PagesCriteriaWidget);
    PagesCriteriaWidgetPrivate * const d_ptr;
};

}

#endif // PAGESCRITERIAWIDGET_H
