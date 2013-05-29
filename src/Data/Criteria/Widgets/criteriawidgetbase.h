#ifndef CRITERIAWIDGETBASE_H
#define CRITERIAWIDGETBASE_H

#include <QWidget>

namespace Data
{
	class Criteria;
}

namespace UI
{

class CriteriaWidgetBase : public QWidget
{
    Q_OBJECT
public:
    explicit CriteriaWidgetBase(QWidget *parent = 0);
    
    virtual ~CriteriaWidgetBase() {};

    virtual void SetupWidget( const Data::Criteria * inCriteria ) = 0;

public Q_SLOTS:

	virtual bool isValid() const = 0;

Q_SIGNALS:
    
};

}

Q_DECLARE_METATYPE(UI::CriteriaWidgetBase *)

#endif // CRITERIAWIDGETBASE_H
