#ifndef PAGESCRITERIA_P_H
#define PAGESCRITERIA_P_H

#include "criteria_p.h"
#include "pagescriteria.h"

namespace UI {
    class PagesCriteriaWidget;
}

namespace Data {

    class PagesCriteriaPrivate : public CriteriaPrivate
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(Data::PagesCriteria)
        Q_DISABLE_COPY(PagesCriteriaPrivate)

    public:

        /// Default constructor
        explicit PagesCriteriaPrivate();

        /// Destructor
        ~PagesCriteriaPrivate();

        /// Function to initialize this class
        void init();

        int m_pages;

    public Q_SLOTS:

    };

}

#endif // PAGESCRITERIA_P_H
