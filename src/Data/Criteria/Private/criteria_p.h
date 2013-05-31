#ifndef CRITERIA_P_H
#define CRITERIA_P_H

#include <QObject>
#include <QPointer>

namespace UI
{
	class CriteriaWidgetBase;
}

namespace Data
{

class Criteria;

class CriteriaPrivate : public QObject
{
	Q_OBJECT
    Q_DECLARE_PUBLIC(Data::Criteria);
    Q_DISABLE_COPY(CriteriaPrivate);

public:
    explicit CriteriaPrivate();
    virtual ~CriteriaPrivate() {};
	
    virtual void init();

	QPointer<UI::CriteriaWidgetBase> m_widget;
    Criteria * q_ptr;

public Q_SLOTS:

};

}

#endif // CRITERIA_P_H