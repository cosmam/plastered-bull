#ifndef WORDSCRITERIGAWIDGET_H
#define WORDSCRITERIGAWIDGET_H

#include "criteriawidgetbase.h"

namespace UI
{

class WordsCriteriaWidgetPrivate;

class WordsCriteriaWidget : public UI::CriteriaWidgetBase
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UI::WordsCriteriaWidget);
    
public:
    explicit WordsCriteriaWidget(QWidget * parent = NULL);
    ~WordsCriteriaWidget();

    int Words() const;

    void SetupWidget( const Data::Criteria * inCriteria );

    bool isValid() const;
	
private:

    Q_DISABLE_COPY(WordsCriteriaWidget);
    WordsCriteriaWidgetPrivate * const d_ptr;
};

}

#endif // WORDSCRITERIGAWIDGET_H
