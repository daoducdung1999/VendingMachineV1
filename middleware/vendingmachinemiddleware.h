#ifndef VENDINGMACHINEMIDDLEWARE_H
#define VENDINGMACHINEMIDDLEWARE_H

#include <QObject>
#include <QString>
#include "arch/flux/middleware.h"
#include "arch/flux/dispatcher.h"
#include "arch/flux/action.h"
#include "action/actiontype.h"

class VendingMachineMiddleware : public QObject, public Middleware
{
    Q_OBJECT
public:
    VendingMachineMiddleware();
    virtual ~VendingMachineMiddleware();

    QSharedPointer<Action> process(const QSharedPointer<Action>& action) override;

    //dispatch functions
    void dispatchActionTestAction(QVariant data);

signals:
    void signalDispatchActionToProcessor(QSharedPointer<Action> action);
};

#endif // VENDINGMACHINEMIDDLEWARE_H
