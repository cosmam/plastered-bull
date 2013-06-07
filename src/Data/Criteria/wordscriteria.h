#ifndef WORDSCRITERIA_H
#define WORDSCRITERIA_H

#include "criteria.h"

namespace Data {

    class WordsCriteriaPrivate;

    class WordsCriteria : public Criteria
    {
        Q_OBJECT
        Q_DECLARE_PRIVATE(Data::WordsCriteria)
        Q_DISABLE_COPY(WordsCriteria)

    public:

        /// Default constructor
        explicit WordsCriteria(QObject *parent = 0);

        /// Destructor
        ~WordsCriteria();

        /// Sets the number of words
        void setWords(int words);

        /// Gets the number of words
        int words() const;

        /// Checks if this criteria meets the bar set by the other
        bool Met(const Criteria * other) const;

        /// Creates the criteria widget
        UI::CriteriaWidgetBase * CreateWidget();

    public Q_SLOTS:

    Q_SIGNALS:

    };

}

/// QDataStream output operator
QDataStream & operator<<(QDataStream & out, const Data::WordsCriteria & criteria);

/// QDataStream input operator
QDataStream & operator>>(QDataStream & in, Data::WordsCriteria & criteria);

#endif // WORDSCRITERIA_H
