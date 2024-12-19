#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include <QSharedPointer>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "middleware/vendingmachinemiddleware.h"
#include "action/actionprovider.h"
#include "processor/mainbusinessprocessor.h"
#include "store/mainwindowstore.h"
#include "commonsetting.h"
#include "model/productinformationitem.h"
#include "model/ingredientitem.h"

class AppManager : public QObject
{
    Q_OBJECT
public:
    static AppManager& getInstance()
    {
        return AppManager::self;
    }
    virtual ~AppManager();

    bool initSystem();
    void initNewObject();
    void initQmlAccession();
    void initStoreAndMiddlewareRegistration();
    void initSignalSlotConnection();
    void initSystemBusiness();
    void registerMetaType();

public slots:
    void slotQuit();

private:
    AppManager();
    static AppManager self;
    //middleware
    QSharedPointer<VendingMachineMiddleware> mVendingMachineMiddleware {nullptr};
    //processor
    std::unique_ptr<ProcessorAbstract> mMainBusinessProcessor {nullptr};
};

#endif // APPMANAGER_H
