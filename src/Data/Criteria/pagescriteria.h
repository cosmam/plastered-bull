#ifndef PAGESCRITERIA_H
#define PAGESCRITERIA_H

#include "criteria.h"

namespace Data
{

class PagesCriteriaPrivate;

class PagesCriteria : public Criteria
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Data::PagesCriteria);
    Q_DISABLE_COPY(PagesCriteria);

public:
    explicit PagesCriteria(QObject *parent = 0);
    ~PagesCriteria();
	    
	void setPages(int pages);
	int pages() const;
		
	bool Met(const Criteria * other) const;
	
	UI::CriteriaWidgetBase * CreateWidget();
	
public Q_SLOTS:
    
Q_SIGNALS:

};

}

QDataStream & operator<<(QDataStream & out, const Data::PagesCriteria & goal);

QDataStream & operator>>(QDataStream & in, Data::PagesCriteria & goal);

#endif // PAGESCRITERIA_H
