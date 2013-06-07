#ifndef WORDSCRITERIAWIDGET_P_H
#define WORDSCRITERIAWIDGET_P_H

#include <QObject>

class QColorDialog;

namespace Ui {
    class WordsCriteriaWidget;
}

namespace Data {
    class WordsCriteria;
}

namespace UI {

    class WordsCriteriaWidget;

    class WordsCriteriaWidgetPrivate : public QObject
    {
        Q_OBJECT
        Q_DECLARE_PUBLIC(UI::WordsCriteriaWidget)
        Q_DISABLE_COPY(WordsCriteriaWidgetPrivate)

    public:

        /// Default Constructor
        explicit WordsCriteriaWidgetPrivate(WordsCriteriaWidget *parent);

        /// Destructor
        ~WordsCriteriaWidgetPrivate();

        Ui::WordsCriteriaWidget * const ui;
        UI::WordsCriteriaWidget * const q_ptr;

    public Q_SLOTS:

    };

}

#endif // WORDSCRITERIAWIDGET_P_H
