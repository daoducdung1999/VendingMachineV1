#ifndef STORE_H
#define STORE_H

#include <QSharedPointer>

class Action;

class Store
{
public:
    virtual ~Store() = default;

    virtual void process(const QSharedPointer<Action>& action) = 0;

protected:
    Store() = default;
    Store(const Store&) = default;
    Store(Store&&) = default;
    Store& operator=(const Store&) = default;
    Store& operator=(Store&&) = default;
};
#endif // STORE_H
