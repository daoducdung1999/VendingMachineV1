#include "mainwindowstore.h"

MainWindowStore* MainWindowStore::instance = nullptr;

MainWindowStore::~MainWindowStore()
{
}

MainWindowStore::MainWindowStore() {
    mProteinProductInfoModel = QSharedPointer<ProductInformationModel>(new ProductInformationModel());
    connect(mProteinProductInfoModel.get(),
            &QObjectListModel::countChanged,
            this,
            &MainWindowStore::proteinProductInfoModelChanged);
    //
    mBcaaProductInfoModel = QSharedPointer<ProductInformationModel>(new ProductInformationModel());
    connect(mBcaaProductInfoModel.get(),
            &QObjectListModel::countChanged,
            this,
            &MainWindowStore::bcaaProductInfoModelChanged);
    //
    mPreWorkoutProductInfoModel = QSharedPointer<ProductInformationModel>(new ProductInformationModel());
    connect(mPreWorkoutProductInfoModel.get(),
            &QObjectListModel::countChanged,
            this,
            &MainWindowStore::preWorkoutProductInfoModelChanged);
    //
    mSupAndDietProductInfoModel = QSharedPointer<ProductInformationModel>(new ProductInformationModel());
    connect(mSupAndDietProductInfoModel.get(),
            &QObjectListModel::countChanged,
            this,
            &MainWindowStore::supAndDietProductInfoModelChanged);
    //
    mProductInfoDetailItem = QSharedPointer<ProductInformationItem>(new ProductInformationItem());
    //
    loadProteinProductInfo();
    loadBcaaProductInfo();
    loadPreWorkoutProductInfo();
    loadSupAndDietProductInfo();
}

ProductInformationModel *MainWindowStore::supAndDietProductInfoModel() const
{
    return mSupAndDietProductInfoModel.get();
}

void MainWindowStore::setSupAndDietProductInfoModel(QSharedPointer<ProductInformationModel> newSupAndDietProductInfoModel)
{
    if (mSupAndDietProductInfoModel == newSupAndDietProductInfoModel)
        return;
    mSupAndDietProductInfoModel = newSupAndDietProductInfoModel;
    emit supAndDietProductInfoModelChanged();
}

ProductInformationItem* MainWindowStore::proteinProductInfoDetailItem() const
{
    return mProductInfoDetailItem.get();
}

void MainWindowStore::setProteinProductInfoDetailItem(QSharedPointer<ProductInformationItem> newProteinProductInfoDetailItem)
{
    if (mProductInfoDetailItem == newProteinProductInfoDetailItem)
        return;
    mProductInfoDetailItem = newProteinProductInfoDetailItem;
    emit productInfoDetailItemChanged();
}

ProductInformationModel *MainWindowStore::preWorkoutProductInfoModel() const
{
    return mPreWorkoutProductInfoModel.get();
}

void MainWindowStore::setPreWorkoutProductInfoModel(QSharedPointer<ProductInformationModel> newPreWorkoutProductInfoModel)
{
    if (mPreWorkoutProductInfoModel == newPreWorkoutProductInfoModel)
        return;
    mPreWorkoutProductInfoModel = newPreWorkoutProductInfoModel;
    emit preWorkoutProductInfoModelChanged();
}

ProductInformationModel *MainWindowStore::bcaaProductInfoModel() const
{
    return mBcaaProductInfoModel.get();
}

void MainWindowStore::setBcaaProductInfoModel(QSharedPointer<ProductInformationModel> newBcaaProductInfoModel)
{
    if (mBcaaProductInfoModel == newBcaaProductInfoModel)
        return;
    mBcaaProductInfoModel = newBcaaProductInfoModel;
    emit bcaaProductInfoModelChanged();
}

MainWindowStore *MainWindowStore::getInstance()
{
    if (instance == nullptr)
    {
        instance = new MainWindowStore();
    }

    return instance;
}

void MainWindowStore::process(const QSharedPointer<Action> &action)
{

    switch (action->getType<ActionType>()) {
    case ActionType::SelectProduct:
    {
        processActionSelectProduct(action);
        break;
    }
    default:
        break;
    }
}

ProductInformationModel *MainWindowStore::proteinProductInfoModel() const
{
    return mProteinProductInfoModel.get();
}

void MainWindowStore::setProteinProductInfoModel(QSharedPointer<ProductInformationModel> newProteinProductInfoModel)
{
    if (mProteinProductInfoModel == newProteinProductInfoModel)
        return;
    mProteinProductInfoModel = newProteinProductInfoModel;
    emit proteinProductInfoModelChanged();
}

void MainWindowStore::loadProteinProductInfo()
{
    QList<QSharedPointer<ProductInformationItem>> listObjects;
    for (int i = 0; i < 6; i++)
    {
        QSharedPointer<ProductInformationItem> item = QSharedPointer<ProductInformationItem>(new ProductInformationItem());
        item->setId(i + 1);
        item->setType(PRODUCT_TYPE::PROTEIN);
        item->setName("Chocolate-Powder");
        item->setCost(3000);
        item->setIngredient("protein: 20g, carbohydrates: 2g, fat: 1g, ernegy: 11kcal");
        //
        QList<QSharedPointer<IngredientItem>> listAdditionalItem;
        for (int j = 0; j < 4; j++)
        {
            QSharedPointer<IngredientItem> additionalItem = QSharedPointer<IngredientItem>(new IngredientItem);
            additionalItem->setName("Creatine");
            additionalItem->setQuantity(5);
            additionalItem->setCost(1000);
            additionalItem->setAmount(0);
            listAdditionalItem.append(additionalItem);
        }
        item->additionalProtein()->setObjectList(listAdditionalItem);
        item->additionalNutrients()->setObjectList(listAdditionalItem);
        listObjects.append(item);
    }
    mProteinProductInfoModel->setObjectList(listObjects);
}

void MainWindowStore::loadBcaaProductInfo()
{
    QList<QSharedPointer<ProductInformationItem>> listObjects;
    for (int i = 0; i < 4; i++)
    {
        QSharedPointer<ProductInformationItem> item = QSharedPointer<ProductInformationItem>(new ProductInformationItem());
        item->setId(i + 1);
        item->setType(PRODUCT_TYPE::BCAA);
        item->setName("Blood-Orange");
        item->setCost(4000);
        item->setIngredient("protein: 20g, carbohydrates: 2g, fat: 1g, ernegy: 11kcal");
        //
        QList<QSharedPointer<IngredientItem>> listAdditionalItem;
        for (int j = 0; j < 4; j++)
        {
            QSharedPointer<IngredientItem> additionalItem = QSharedPointer<IngredientItem>(new IngredientItem);
            additionalItem->setName("Creatine");
            additionalItem->setQuantity(5);
            additionalItem->setCost(1000);
            additionalItem->setAmount(0);
            listAdditionalItem.append(additionalItem);
        }
        item->additionalProtein()->setObjectList(listAdditionalItem);
        item->additionalNutrients()->setObjectList(listAdditionalItem);
        listObjects.append(item);        
    }
    mBcaaProductInfoModel->setObjectList(listObjects);
}

void MainWindowStore::loadPreWorkoutProductInfo()
{
    QList<QSharedPointer<ProductInformationItem>> listObjects;
    for (int i = 0; i < 5; i++)
    {
        QSharedPointer<ProductInformationItem> item = QSharedPointer<ProductInformationItem>(new ProductInformationItem());
        item->setId(i + 1);
        item->setType(PRODUCT_TYPE::PREWORKOUT);
        item->setName("Blue-Raspberry");
        item->setCost(6900);
        item->setIngredient("protein: 20g, carbohydrates: 2g, fat: 1g, ernegy: 11kcal");
        //
        QList<QSharedPointer<IngredientItem>> listAdditionalItem;
        for (int j = 0; j < 4; j++)
        {
            QSharedPointer<IngredientItem> additionalItem = QSharedPointer<IngredientItem>(new IngredientItem);
            additionalItem->setName("Creatine");
            additionalItem->setQuantity(5);
            additionalItem->setCost(1000);
            additionalItem->setAmount(0);
            listAdditionalItem.append(additionalItem);
        }
        item->additionalProtein()->setObjectList(listAdditionalItem);
        item->additionalNutrients()->setObjectList(listAdditionalItem);
        listObjects.append(item);
    }
    mPreWorkoutProductInfoModel->setObjectList(listObjects);
}

void MainWindowStore::loadSupAndDietProductInfo()
{
    QList<QSharedPointer<ProductInformationItem>> listObjects;
    for (int i = 0; i < 7; i++)
    {
        QSharedPointer<ProductInformationItem> item = QSharedPointer<ProductInformationItem>(new ProductInformationItem());
        item->setId(i + 1);
        item->setType(PRODUCT_TYPE::SUPANDDIET);
        item->setName("Creatine");
        item->setCost(9600);
        item->setIngredient("protein: 20g, carbohydrates: 2g, fat: 1g, ernegy: 11kcal");
        //
        QList<QSharedPointer<IngredientItem>> listAdditionalItem;
        for (int j = 0; j < 4; j++)
        {
            QSharedPointer<IngredientItem> additionalItem = QSharedPointer<IngredientItem>(new IngredientItem);
            additionalItem->setName("Creatine");
            additionalItem->setQuantity(5);
            additionalItem->setCost(1000);
            additionalItem->setAmount(0);
            listAdditionalItem.append(additionalItem);
        }
        item->additionalProtein()->setObjectList(listAdditionalItem);
        item->additionalNutrients()->setObjectList(listAdditionalItem);
        listObjects.append(item);
    }
    mSupAndDietProductInfoModel->setObjectList(listObjects);
}

void MainWindowStore::processActionSelectProduct(QSharedPointer<Action> action)
{
    if (!action)
    {
        return;
    }
    auto data = action->getPayload<QVariant>().toMap();
    int type = data["type"].toInt();
    int itemId = data["itemId"].toInt();
    switch (type) {
    case PRODUCT_TYPE::PROTEIN:
    {
        processActionSelectProteinProduct(itemId);
        break;
    }

    case PRODUCT_TYPE::BCAA:
    {
        processActionSelectBcaaProduct(itemId);
        break;
    }

    case PRODUCT_TYPE::PREWORKOUT:
    {
        processActionSelectPreWorkoutProduct(itemId);
        break;
    }

    case PRODUCT_TYPE::SUPANDDIET:
    {
        processActionSelectSupAndDietProduct(itemId);
        break;
    }
    default:
        break;
    }
}

void MainWindowStore::processActionSelectProteinProduct(int itemId)
{
    for (int i = 0; i < mProteinProductInfoModel->size(); i++)
    {
        if (itemId == mProteinProductInfoModel->at(i)->id())
        {
            mProductInfoDetailItem = mProteinProductInfoModel->at(i);
            emit productInfoDetailItemChanged();
        }
    }
}

void MainWindowStore::processActionSelectBcaaProduct(int itemId)
{
    for (int i = 0; i < mBcaaProductInfoModel->size(); i++)
    {
        if (itemId == mBcaaProductInfoModel->at(i)->id())
        {
            mProductInfoDetailItem = mBcaaProductInfoModel->at(i);
            emit productInfoDetailItemChanged();
        }
    }
}

void MainWindowStore::processActionSelectPreWorkoutProduct(int itemId)
{
    for (int i = 0; i < mPreWorkoutProductInfoModel->size(); i++)
    {
        if (itemId == mPreWorkoutProductInfoModel->at(i)->id())
        {
            mProductInfoDetailItem = mPreWorkoutProductInfoModel->at(i);
            emit productInfoDetailItemChanged();
        }
    }
}

void MainWindowStore::processActionSelectSupAndDietProduct(int itemId)
{
    for (int i = 0; i < mSupAndDietProductInfoModel->size(); i++)
    {
        if (itemId == mSupAndDietProductInfoModel->at(i)->id())
        {
            mProductInfoDetailItem = mSupAndDietProductInfoModel->at(i);
            emit productInfoDetailItemChanged();
        }
    }
}
