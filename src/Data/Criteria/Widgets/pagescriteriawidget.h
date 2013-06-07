#ifndef PAGESCRITERIAWIDGET_H
#define PAGESCRITERIAWIDGET_H

#include "criteriawidgetbase.h"

namespace UI {

    class PagesCriteriaWidgetPrivate;

    class PagesCriteriaWidget : public UI::CriteriaWidgetBase
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::PagesCriteriaWidget)
        Q_DISABLE_COPY(PagesCriteriaWidget)

    public:

        /// Default constuctor
        explicit PagesCriteriaWidget(QWidget * parent = NULL);

        /// Destructor
        ~PagesCriteriaWidget();

        /// Gets the page count
        int Pages() const;

        /// Sets up the widget based on the criteria
        void SetupWidget( const Data::Criteria * inCriteria );

        /// Determines whether or not the information is valid
        bool isValid() const;

    private:

        PagesCriteriaWidgetPrivate * const d_ptr;
    };

}

#endif // PAGESCRITERIAWIDGET_H
