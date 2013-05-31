#ifndef CRITERIA_H
#define CRITERIA_H

#include <QObject>

namespace UI
{
	class CriteriaWidgetBase;
}

namespace Data
{

class CriteriaPrivate;

class Criteria : public QObject
{
	Q_OBJECT
    Q_DECLARE_PRIVATE(Data::Criteria);
    Q_DISABLE_COPY(Criteria);
	
public:
    explicit Criteria(QObject * parent = 0);
    virtual ~Criteria() {};
    
	virtual bool Met(const Criteria * other) const = 0;
	
    virtual UI::CriteriaWidgetBase * CreateWidget() = 0;
	
public Q_SLOTS:

Q_SIGNALS:
	
protected:
    explicit Criteria(CriteriaPrivate & d, QObject * parent = 0);
    CriteriaPrivate * const d_ptr;
};

}

#endif // CRITERIA_H
