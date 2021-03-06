INCLUDEPATH +=  src \
    src/Data \
    src/Data/Private \
    src/Data/Criteria \
    src/Data/Criteria/Private \
    src/Data/Criteria/Widgets \
    src/Data/Criteria/Widgets/Private \
    src/Data/Goal \
    src/Data/Goal/Private \
    src/Data/Goal/Widgets \
    src/Data/Goal/Widgets/Calendar \
    src/Data/Goal/Widgets/Calendar/Private \
    src/Data/Goal/Widgets/Private

SOURCES += src/timefunctions.cpp \
    src/widgetfunctions.cpp \
    src/Data/challenge.cpp \
    src/Data/datastore.cpp \
    src/Data/Criteria/wordscriteria.cpp \
    src/Data/Criteria/pagescriteria.cpp \
    src/Data/Criteria/criteria.cpp \
    src/Data/Goal/yeargoal.cpp \
    src/Data/Goal/weekgoal.cpp \
    src/Data/Goal/monthgoal.cpp \
    src/Data/Goal/goal.cpp \
    src/Data/Goal/daygoal.cpp \
    src/Data/Goal/goalfactory.cpp \
    src/Data/Goal/customgoal.cpp \
    src/Data/Goal/Widgets/yeargoalwidget.cpp \
    src/Data/Goal/Widgets/weekgoalwidget.cpp \
    src/Data/Goal/Widgets/monthgoalwidget.cpp \
    src/Data/Goal/Widgets/daygoalwidget.cpp \
    src/Data/Goal/Widgets/customgoalwidget.cpp \
    src/Data/Goal/Widgets/goalwidgetbase.cpp \
    src/Data/Goal/Widgets/Calendar/goalcalendar.cpp \
    src/Data/Goal/Widgets/Calendar/calendarday.cpp \
    src/Data/Goal/Widgets/Calendar/calendarmonth.cpp \
    src/Data/Goal/Widgets/Calendar/selectionmanager.cpp \
    src/Data/Goal/Widgets/Calendar/selectablewidget.cpp \
    src/Data/Goal/Widgets/Calendar/goalcalendaritem.cpp \
    src/Data/Goal/Widgets/Calendar/calendarmodel.cpp \
    src/Data/Goal/Widgets/Calendar/calendargoal.cpp \
    src/Data/Criteria/Widgets/wordscriteriawidget.cpp \
    src/Data/Criteria/Widgets/pagescriteriawidget.cpp \
    src/Data/Criteria/Widgets/criteriawidgetbase.cpp

HEADERS  += src/commontypes.h \
    src/timefunctions.h \
    src/widgetfunctions.h \
    src/Data/challenge.h \
    src/Data/datastore.h \
    src/Data/Private/challenge_p.h \
    src/Data/Criteria/wordscriteria.h \
    src/Data/Criteria/pagescriteria.h \
    src/Data/Criteria/criteria.h \
    src/Data/Criteria/Private/wordscriteria_p.h \
    src/Data/Criteria/Private/pagescriteria_p.h \
    src/Data/Criteria/Private/criteria_p.h \
    src/Data/Goal/goal.h \
    src/Data/Goal/daygoal.h \
    src/Data/Goal/yeargoal.h \
    src/Data/Goal/weekgoal.h \
    src/Data/Goal/monthgoal.h \
    src/Data/Goal/customgoal.h \
    src/Data/Goal/goalfactory.h \
    src/Data/Goal/Widgets/yeargoalwidget.h \
    src/Data/Goal/Widgets/weekgoalwidget.h \
    src/Data/Goal/Widgets/monthgoalwidget.h \
    src/Data/Goal/Widgets/daygoalwidget.h \
    src/Data/Goal/Widgets/customgoalwidget.h \
    src/Data/Goal/Widgets/goalwidgetbase.h \
    src/Data/Goal/Widgets/Calendar/goalcalendar.h \   
    src/Data/Goal/Private/yeargoal_p.h \
    src/Data/Goal/Private/weekgoal_p.h \
    src/Data/Goal/Private/monthgoal_p.h \
    src/Data/Goal/Private/daygoal_p.h \
    src/Data/Goal/Private/customgoal_p.h \
    src/Data/Goal/Private/goal_p.h \
    src/Data/Goal/Widgets/Calendar/Private/goalcalendar_p.h \
    src/Data/Goal/Widgets/Calendar/calendarday.h \
    src/Data/Goal/Widgets/Calendar/Private/calendarday_p.h \
    src/Data/Goal/Widgets/Calendar/calendarmonth.h \
    src/Data/Goal/Widgets/Calendar/Private/calendarmonth_p.h \
    src/Data/Goal/Widgets/Private/customgoalwidget_p.h \
    src/Data/Goal/Widgets/Private/yeargoalwidget_p.h \
    src/Data/Goal/Widgets/Private/weekgoalwidget_p.h \
    src/Data/Goal/Widgets/Private/monthgoalwidget_p.h \
    src/Data/Goal/Widgets/Private/daygoalwidget_p.h \
    src/Data/Goal/Widgets/Calendar/selectionmanager.h \
    src/Data/Goal/Widgets/Calendar/selectablewidget.h \
    src/Data/Goal/Widgets/Calendar/goalcalendaritem.h \
    src/Data/Goal/Widgets/Calendar/Private/selectionmanager_p.h \
    src/Data/Goal/Widgets/Calendar/Private/selectablewidget_p.h \
    src/Data/Goal/Widgets/Calendar/Private/goalcalendaritem_p.h \
    src/Data/Goal/Widgets/Calendar/Private/calendarmodel_p.h \
    src/Data/Goal/Widgets/Calendar/calendarmodel.h \
    src/Data/Goal/Widgets/Calendar/calendargoal.h \
    src/Data/Goal/Widgets/Calendar/Private/calendargoal_p.h \
    src/Data/Criteria/Widgets/wordscriteriawidget.h \
    src/Data/Criteria/Widgets/pagescriteriawidget.h \
    src/Data/Criteria/Widgets/criteriawidgetbase.h \
    src/Data/Criteria/Widgets/Private/wordscriteriawidget_p.h \
    src/Data/Criteria/Widgets/Private/pagescriteriawidget_p.h
	
FORMS    += src/Data/Goal/Widgets/yeargoalwidget.ui \
    src/Data/Goal/Widgets/weekgoalwidget.ui \
    src/Data/Goal/Widgets/monthgoalwidget.ui \
    src/Data/Goal/Widgets/daygoalwidget.ui \
    src/Data/Goal/Widgets/customgoalwidget.ui \
    src/Data/Goal/Widgets/Calendar/goalcalendar.ui \
    src/Data/Goal/Widgets/Calendar/calendarday.ui \
    src/Data/Goal/Widgets/Calendar/calendarmonth.ui \
    src/Data/Goal/Widgets/Calendar/calendargoal.ui \
    src/Data/Criteria/Widgets/wordscriteriawidget.ui \
    src/Data/Criteria/Widgets/pagescriteriawidget.ui
