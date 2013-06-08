#ifndef CRITERIAWIDGETBASE_H
#define CRITERIAWIDGETBASE_H

#include <QWidget>

namespace Data {
	class Criteria;
}

namespace UI {

    class CriteriaWidgetBase : public QWidget
    {
        Q_OBJECT

    public:

        /// Default constructor
        explicit CriteriaWidgetBase(QWidget *parent = 0);

        /// Virtual destructor
        virtual ~CriteriaWidgetBase() {}        // LCOV_EXCL_LINE

        /// Virtual function to setup this widget
        virtual void SetupWidget( const Data::Criteria * inCriteria ) = 0;

    public Q_SLOTS:

        /// Virtual slot to determine if information is valid
        virtual bool isValid() const = 0;

    Q_SIGNALS:

    };

}

Q_DECLARE_METATYPE(UI::CriteriaWidgetBase *)

#endif // CRITERIAWIDGETBASE_H
