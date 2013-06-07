#ifndef WORDSCRITERIGAWIDGET_H
#define WORDSCRITERIGAWIDGET_H

#include "criteriawidgetbase.h"

namespace UI {

    class WordsCriteriaWidgetPrivate;

    class WordsCriteriaWidget : public UI::CriteriaWidgetBase
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(UI::WordsCriteriaWidget)
        Q_DISABLE_COPY(WordsCriteriaWidget)

    public:

        /// Default constructor
        explicit WordsCriteriaWidget(QWidget * parent = NULL);

        /// Destructor
        ~WordsCriteriaWidget();

        /// Gets the number of words
        int Words() const;

        /// Sets up the widget based on the criteria
        void SetupWidget( const Data::Criteria * inCriteria );

        /// Determines whether or not the information is valid
        bool isValid() const;

    private:

        WordsCriteriaWidgetPrivate * const d_ptr;
    };

}

#endif // WORDSCRITERIGAWIDGET_H
