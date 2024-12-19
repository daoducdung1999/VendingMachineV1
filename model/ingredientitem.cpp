#include "ingredientitem.h"

IngredientItem::IngredientItem() {}

IngredientItem::~IngredientItem() {}

QString IngredientItem::name() const
{
    return mName;
}

void IngredientItem::setName(const QString &newName)
{
    if (mName == newName)
        return;
    mName = newName;
    emit nameChanged();
}

double IngredientItem::quantity() const
{
    return mQuantity;
}

void IngredientItem::setQuantity(double newQuantity)
{
    if (qFuzzyCompare(mQuantity, newQuantity))
        return;
    mQuantity = newQuantity;
    emit quantityChanged();
}

int IngredientItem::amount() const
{
    return mAmount;
}

void IngredientItem::setAmount(int newAmount)
{
    if (mAmount == newAmount)
        return;
    mAmount = newAmount;
    emit amountChanged();
}

double IngredientItem::cost() const
{
    return mCost;
}

void IngredientItem::setCost(double newCost)
{
    if (qFuzzyCompare(mCost, newCost))
        return;
    mCost = newCost;
    emit costChanged();
}
