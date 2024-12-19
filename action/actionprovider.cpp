#include "actionprovider.h"

void ActionProvider::testAction(QVariant data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TestAction, QVariant(data)));
}

void ActionProvider::selectProduct(QVariantMap data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::SelectProduct, QVariant(data)));
}
