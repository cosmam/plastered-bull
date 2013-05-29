#ifndef WORDSCRITERIA_H
#define WORDSCRITERIA_H

#include "criteria.h"

namespace Data
{

class WordsCriteriaPrivate;

class WordsCriteria : public Criteria
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Data::WordsCriteria);
    Q_DISABLE_COPY(WordsCriteria);

public:
    explicit WordsCriteria(QObject *parent = 0);
    ~WordsCriteria();
	    
	void setWords(int words);
	int words() const;
		
	bool Met(const Criteria * other) const;
	
	UI::CriteriaWidgetBase * CreateWidget();
	
public Q_SLOTS:
    
Q_SIGNALS:

};

}

QDataStream & operator<<(QDataStream & out, const Data::WordsCriteria & goal);

QDataStream & operator>>(QDataStream & in, Data::WordsCriteria & goal);

#endif // WORDSCRITERIA_H
