#ifndef CRITERIA_H
#define CRITERIA_H

#include <QObject>

namespace UI {
	class CriteriaWidgetBase;
}

namespace Data {

    class CriteriaPrivate;

    class Criteria : public QObject
    {
        Q_OBJECT                            // LCOV_EXCL_LINE
        Q_DECLARE_PRIVATE(Data::Criteria)
        Q_DISABLE_COPY(Criteria)

    public:

        /// Default constructor
        explicit Criteria(QObject * parent = 0);

        /// Virtual destructor
        virtual ~Criteria() {}      // LCOV_EXCL_LINE

        /// Virtual function to check if this criteria meets the bar set by the other
        virtual bool Met(const Criteria * other) const = 0;

        /// Virtual function to create the criteria widget
        virtual UI::CriteriaWidgetBase * CreateWidget() = 0;

    public Q_SLOTS:

    Q_SIGNALS:

    protected:

        /// Protected constructor for d-pointer inheritence
        explicit Criteria(CriteriaPrivate & d, QObject * parent = 0);

        CriteriaPrivate * const d_ptr;
    };

}

#endif // CRITERIA_H
