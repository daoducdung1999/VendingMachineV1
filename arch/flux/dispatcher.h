#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <type_traits>
#include <utility>
#include <QObject>
#include <QSharedPointer>
#include <QVector>
#include "action.h"
#include "middleware.h"
#include "store.h"

class Dispatcher final : public QObject
{
    Q_OBJECT

public:
    static Dispatcher& instance()
    {
        static Dispatcher self;
        return self;
    }

    template<class... Args>
    void registerMiddleware(Args&& ... args)
    {
        middlewares_.push_back(QSharedPointer<Middleware>(std::forward<Args>(args)...));
    }

    template<class... Args>
    void registerStore(Args&& ... args)
    {
        stores_.push_back(QSharedPointer<Store>(std::forward<Args>(args)...));
    }

    template<class... Args>
    void dispatch(Args&& ... args)
    {
        emit newActionAdded(QSharedPointer<Action>(std::forward<Args>(args)...));
    }

signals:
    void newActionAdded(QSharedPointer<Action> action);

private:
    Dispatcher()
    {
        QObject::connect(this, &Dispatcher::newActionAdded, this, &Dispatcher::onNewActionAdded, Qt::AutoConnection);
    }
    ~Dispatcher() = default;
    Dispatcher(const Dispatcher&) = delete;
    Dispatcher(Dispatcher&&) = delete;
    Dispatcher& operator=(const Dispatcher&) = delete;
    Dispatcher& operator=(Dispatcher&&) = delete;

    void onNewActionAdded(QSharedPointer<Action> action)
    {
        if (action)
        {
            for (const auto & middleware : middlewares_)
            {
                action = middleware->process(action);
            }

            for (const auto & store : stores_)
            {
                store->process(action);
            }
        }
    }
    QVector<QSharedPointer<Middleware>> middlewares_;
    QVector<QSharedPointer<Store>> stores_;
};

#endif // DISPATCHER_H
