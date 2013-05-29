#ifndef WORDSCRITERIAWIDGET_P_H
#define WORDSCRITERIAWIDGET_P_H

#include <QObject>

class QColorDialog;

namespace Ui 
{
	class WordsCriteriaWidget;
}

namespace Data
{
    class WordsCriteria;
}

namespace UI
{

class WordsCriteriaWidget;

class WordsCriteriaWidgetPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(UI::WordsCriteriaWidget);

public:
    explicit WordsCriteriaWidgetPrivate(WordsCriteriaWidget *parent);
    ~WordsCriteriaWidgetPrivate();

    Ui::WordsCriteriaWidget * const ui;
    UI::WordsCriteriaWidget * const q_ptr;

    Q_DISABLE_COPY(WordsCriteriaWidgetPrivate);

public Q_SLOTS:

};

}

#endif // WORDSCRITERIAWIDGET_P_H
