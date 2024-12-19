#include "appmanager.h"

AppManager AppManager::self;

AppManager::AppManager() {}

AppManager::~AppManager()
{
}

bool AppManager::initSystem()
{
    bool ret {true};

    //
    registerMetaType();
    initNewObject();
    initStoreAndMiddlewareRegistration();
    initQmlAccession();
    initSystemBusiness();
    initSignalSlotConnection();
    return ret;
}

void AppManager::initNewObject()
{
}

void AppManager::initQmlAccession()
{
    qmlRegisterSingletonType<ActionProvider>("Flux", 1, 0, "ActionProvider",
                                             [](QQmlEngine * engine, QJSEngine * scriptEngine) -> QObject*
    {
        Q_UNUSED(engine);
        Q_UNUSED(scriptEngine);
        QQmlEngine::setObjectOwnership(&ActionProvider::getInstance(), QQmlEngine::CppOwnership);
        return &ActionProvider::getInstance();
    });

    qmlRegisterSingletonType<MainWindowStore>("Flux", 1, 0, "MainWindowStore",
                                              [](QQmlEngine * engine, QJSEngine * scriptEngine) -> QObject*
    {
        Q_UNUSED(engine);
        Q_UNUSED(scriptEngine);
        QQmlEngine::setObjectOwnership(&ActionProvider::getInstance(), QQmlEngine::CppOwnership);
        return MainWindowStore::getInstance();
    });
}

void AppManager::initStoreAndMiddlewareRegistration()
{
    //
    Dispatcher::instance().registerStore(QSharedPointer<Store>(MainWindowStore::getInstance(), [](Store*)
                                                               {}));
}

void AppManager::initSignalSlotConnection()
{
}

void AppManager::initSystemBusiness()
{
}

void AppManager::registerMetaType()
{
    qRegisterMetaType<std::shared_ptr<InnerMessage>>("std::shared_ptr<InnerMessage>");
    qRegisterMetaType<QSharedPointer<Action>>("QSharedPointer<Action>");
    //
    qRegisterMetaType<QSharedPointer<ProductInformationModel>>("QSharedPointer<ProductInformationModel>");
    qRegisterMetaType<ProductInformationModel*>("ProductInformationModel*");
    qRegisterMetaType<QSharedPointer<ProductInformationItem>>("QSharedPointer<ProductInformationItem>");
    qRegisterMetaType<ProductInformationItem*>("ProductInformationItem*");
    //
    qRegisterMetaType<QSharedPointer<IngredientModel>>("QSharedPointer<IngredientModel>");
    qRegisterMetaType<IngredientModel*>("IngredientModel*");
    qRegisterMetaType<QSharedPointer<IngredientItem>>("QSharedPointer<IngredientItem>");
    qRegisterMetaType<IngredientItem*>("IngredientItem*");
}

void AppManager::slotQuit()
{
    qApp->quit();
}

