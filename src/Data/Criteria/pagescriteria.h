#ifndef PAGESCRITERIA_H
#define PAGESCRITERIA_H

#include "criteria.h"

namespace Data {

    class PagesCriteriaPrivate;

    class PagesCriteria : public Criteria
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(Data::PagesCriteria)
        Q_DISABLE_COPY(PagesCriteria)

    public:

        /// Default constructor
        explicit PagesCriteria(QObject *parent = 0);

        /// Destructor
        ~PagesCriteria();

        /// Sets the page count
        void setPages(int pages);

        /// Gets the page count
        int pages() const;

        /// Checks if this criteria meets the bar set by the other
        bool Met(const Criteria * other) const;

        /// Creates the criteria widget
        UI::CriteriaWidgetBase * CreateWidget();

    public Q_SLOTS:

    Q_SIGNALS:

    };

}

/// QDataStream output operator
QDataStream & operator<<(QDataStream & out, const Data::PagesCriteria & criteria);

/// QDataStream input operator
QDataStream & operator>>(QDataStream & in, Data::PagesCriteria & criteria);

#endif // PAGESCRITERIA_H
