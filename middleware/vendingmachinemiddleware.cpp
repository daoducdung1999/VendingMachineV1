#include "vendingmachinemiddleware.h"

VendingMachineMiddleware::VendingMachineMiddleware() {}

VendingMachineMiddleware::~VendingMachineMiddleware()
{
}

QSharedPointer<Action> VendingMachineMiddleware::process(const QSharedPointer<Action> &action)
{
    switch (action->getType<ActionType>()) {
    // case ActionType::NoneAction:
    //     emit signalDispatchActionToProcessor(action);
    //     return QSharedPointer<Action>(new Action(ActionType::NoneAction, QVariant()));

    case ActionType::TestAction:
        emit signalDispatchActionToProcessor(action);
        return action;

    default:
        return action;
    }
}

void VendingMachineMiddleware::dispatchActionTestAction(QVariant data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TestAction, QVariant(data)));
}
