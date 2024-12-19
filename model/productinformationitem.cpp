#include "productinformationitem.h"

ProductInformationItem::ProductInformationItem()
{
    mAdditionalProtein = QSharedPointer<IngredientModel>(new IngredientModel());
    connect(mAdditionalProtein.get(),
            &QObjectListModel::countChanged,
            this,
            &ProductInformationItem::additionalProteinChanged);
    //
    mAdditionalNutrients = QSharedPointer<IngredientModel>(new IngredientModel());
    connect(mAdditionalNutrients.get(),
            &QObjectListModel::countChanged,
            this,
            &ProductInformationItem::additionalNutrientsChanged);
}

ProductInformationItem::~ProductInformationItem()
{
}

int ProductInformationItem::id() const
{
    return mId;
}

void ProductInformationItem::setId(int newId)
{
    if (mId == newId)
        return;
    mId = newId;
    emit idChanged();
}

int ProductInformationItem::type() const
{
    return mType;
}

void ProductInformationItem::setType(int newType)
{
    if (mType == newType)
        return;
    mType = newType;
    emit typeChanged();
}

QString ProductInformationItem::name() const
{
    return mName;
}

void ProductInformationItem::setName(const QString &newName)
{
    if (mName == newName)
        return;
    mName = newName;
    emit nameChanged();
}

double ProductInformationItem::cost() const
{
    return mCost;
}

void ProductInformationItem::setCost(double newCost)
{
    if (qFuzzyCompare(mCost, newCost))
        return;
    mCost = newCost;
    emit costChanged();
}

QString ProductInformationItem::imgPath() const
{
    return mImgPath;
}

void ProductInformationItem::setImgPath(const QString &newImgPath)
{
    if (mImgPath == newImgPath)
        return;
    mImgPath = newImgPath;
    emit imgPathChanged();
}

QString ProductInformationItem::ingredient() const
{
    return mIngredient;
}

void ProductInformationItem::setIngredient(const QString &newIngredient)
{
    if (mIngredient == newIngredient)
        return;
    mIngredient = newIngredient;
    emit ingredientChanged();
}

IngredientModel *ProductInformationItem::additionalProtein() const
{
    return mAdditionalProtein.get();
}

void ProductInformationItem::setAdditionalProtein(QSharedPointer<IngredientModel> newAdditionalProtein)
{
    if (mAdditionalProtein == newAdditionalProtein)
        return;
    mAdditionalProtein = newAdditionalProtein;
    emit additionalProteinChanged();
}

IngredientModel* ProductInformationItem::additionalNutrients() const
{
    return mAdditionalNutrients.get();
}

void ProductInformationItem::setAdditionalNutrients(QSharedPointer<IngredientModel> newAdditionalNutrients)
{
    if (mAdditionalNutrients == newAdditionalNutrients)
        return;
    mAdditionalNutrients = newAdditionalNutrients;
    emit additionalNutrientsChanged();
}

bool ProductInformationItem::isAddIce() const
{
    return mIsAddIce;
}

void ProductInformationItem::setIsAddIce(bool newIsAddIce)
{
    if (mIsAddIce == newIsAddIce)
        return;
    mIsAddIce = newIsAddIce;
    emit isAddIceChanged();
}

double ProductInformationItem::iceCost() const
{
    return mIceCost;
}

void ProductInformationItem::setIceCost(double newIceCost)
{
    if (qFuzzyCompare(mIceCost, newIceCost))
        return;
    mIceCost = newIceCost;
    emit iceCostChanged();
}
