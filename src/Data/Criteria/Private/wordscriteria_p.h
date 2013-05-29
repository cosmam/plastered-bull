#ifndef DAYGOAL_P_H
#define DAYGOAL_P_H

#include "criteria_p.h"
#include "wordscriteria.h"

namespace UI
{
    class WordsCriteriaWidget;
}

namespace Data
{

class WordsCriteria;

class WordsCriteriaPrivate : public CriteriaPrivate
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(Data::WordsCriteria);
    Q_DISABLE_COPY(WordsCriteriaPrivate);

public:
    explicit WordsCriteriaPrivate();
    ~WordsCriteriaPrivate();
    
    void init();

	int m_words;
	
public Q_SLOTS:

};

}

#endif // DAYGOAL_P_H
