#ifndef CRITERIAMOCK_H
#define CRITERIAMOCK_H

#include "criteria.h"

namespace UI {
    class CriteriaWidgetBase;
}

namespace Test {

    class CriteriaMock : public Data::Criteria
    {
            Q_OBJECT
        public:
            explicit CriteriaMock(QObject *parent = 0);

            bool Met(const Criteria * other) const;

            UI::CriteriaWidgetBase * CreateWidget();

        signals:

        public slots:

    };

}

#endif // CRITERIAMOCK_H
