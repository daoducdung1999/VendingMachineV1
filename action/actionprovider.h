#ifndef ACTIONPROVIDER_H
#define ACTIONPROVIDER_H

#include <QObject>
#include <QString>
#include <QVariantMap>
#include "arch/flux/action.h"
#include "arch/flux/dispatcher.h"
#include "actiontype.h"

class ActionProvider final : public QObject
{
    Q_OBJECT
public:
    static ActionProvider& getInstance()
    {
        static ActionProvider self;
        return self;
    }

    //action provider functions
    Q_INVOKABLE void testAction(QVariant data);

    //
    Q_INVOKABLE void selectProduct(QVariantMap data);
    Q_INVOKABLE void confirmSelectProduct();
    Q_INVOKABLE void cancelAllSelectedProduct();
    //
    Q_INVOKABLE void addIngredient(QVariantMap data);
    Q_INVOKABLE void subIngredient(QVariantMap data);

private:
    ActionProvider() = default;
    ~ActionProvider() = default;
    ActionProvider(const ActionProvider&) = delete;
    ActionProvider(ActionProvider&&) = delete;
    ActionProvider& operator=(const ActionProvider&) = delete;
    ActionProvider& operator=(ActionProvider&&) = delete;
};

#endif // ACTIONPROVIDER_H
