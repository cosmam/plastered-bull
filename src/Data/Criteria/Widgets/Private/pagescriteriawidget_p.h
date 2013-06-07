#ifndef PAGESCRITERIAWIDGET_P_H
#define PAGESCRITERIAWIDGET_P_H

#include <QObject>

class QColorDialog;

namespace Ui {
    class PagesCriteriaWidget;
}

namespace Data {
    class PagesCriteria;
}

namespace UI {

    class PagesCriteriaWidget;

    class PagesCriteriaWidgetPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::PagesCriteriaWidget)
        Q_DISABLE_COPY(PagesCriteriaWidgetPrivate)

    public:

        /// Default constructor
        explicit PagesCriteriaWidgetPrivate(PagesCriteriaWidget *parent);

        /// Destructor
        ~PagesCriteriaWidgetPrivate();

        Ui::PagesCriteriaWidget * const ui;
        UI::PagesCriteriaWidget * const q_ptr;

    public Q_SLOTS:

    };

}

#endif // PAGESCRITERIAWIDGET_P_H
