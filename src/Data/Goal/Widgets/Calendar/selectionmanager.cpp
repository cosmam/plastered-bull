#include "selectionmanager.h"
#include "selectionmanager_p.h"

using namespace UI;

SelectionManager::SelectionManager(QObject *parent) :
    QObject(parent),
    d_ptr( new SelectionManagerPrivate( this ) )
{
}

SelectionManager::~SelectionManager()
{
    delete d_ptr;
}

/**************** Private Class ***************/

SelectionManagerPrivate::SelectionManagerPrivate(SelectionManager *parent) :
    QObject(parent),
    q_ptr(parent)
{
}

SelectionManagerPrivate::~SelectionManagerPrivate()
{
}