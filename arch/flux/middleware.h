#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H

#include <QSharedPointer>

class Action;

class Middleware
{
public:
    virtual ~Middleware() = default;

    virtual QSharedPointer<Action> process(const QSharedPointer<Action>& action) = 0;

protected:
    Middleware() = default;
    Middleware(const Middleware&) = default;
    Middleware(Middleware&&) = default;
    Middleware& operator=(const Middleware&) = default;
    Middleware& operator=(Middleware&&) = default;
};

#endif // MIDDLEWARE_H
