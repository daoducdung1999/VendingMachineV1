#include "actionprovider.h"

void ActionProvider::testAction(QVariant data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TestAction, QVariant(data)));
}

void ActionProvider::selectProduct(QVariantMap data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::SelectProduct, QVariant(data)));
}

void ActionProvider::confirmSelectProduct()
{
    Dispatcher::instance().dispatch(new Action(ActionType::ConfirmSelectProduct, QVariant()));
}

void ActionProvider::cancelAllSelectedProduct()
{
    Dispatcher::instance().dispatch(new Action(ActionType::CancelAllSelectedProduct, QVariant()));
}

void ActionProvider::addIngredient(QVariantMap data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::AddIngredient, QVariant(data)));
}

void ActionProvider::subIngredient(QVariantMap data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::SubIngredient, QVariant(data)));
}
