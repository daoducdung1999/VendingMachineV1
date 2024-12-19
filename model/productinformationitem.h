#ifndef PRODUCTINFORMATIONITEM_H
#define PRODUCTINFORMATIONITEM_H

#include "qobjectlistmodelt.h"
#include <QObject>
#include <QSharedPointer>
#include "ingredientitem.h"

class ProductInformationItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged FINAL)
    Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(double cost READ cost WRITE setCost NOTIFY costChanged FINAL)
    Q_PROPERTY(QString imgPath READ imgPath WRITE setImgPath NOTIFY imgPathChanged FINAL)
    Q_PROPERTY(QString ingredient READ ingredient WRITE setIngredient NOTIFY ingredientChanged FINAL)
    //
    Q_PROPERTY(IngredientModel* additionalProtein READ additionalProtein NOTIFY additionalProteinChanged FINAL)
    Q_PROPERTY(IngredientModel* additionalNutrients READ additionalNutrients NOTIFY additionalNutrientsChanged FINAL)
    Q_PROPERTY(bool isAddIce READ isAddIce WRITE setIsAddIce NOTIFY isAddIceChanged FINAL)
    Q_PROPERTY(double iceCost READ iceCost WRITE setIceCost NOTIFY iceCostChanged FINAL)

public:
    ProductInformationItem();
    ~ProductInformationItem();

    int id() const;
    void setId(int newId);

    int type() const;
    void setType(int newType);

    QString name() const;
    void setName(const QString &newName);

    double cost() const;
    void setCost(double newCost);

    QString imgPath() const;
    void setImgPath(const QString &newImgPath);

    QString ingredient() const;
    void setIngredient(const QString &newIngredient);

    IngredientModel* additionalProtein() const;
    void setAdditionalProtein(QSharedPointer<IngredientModel> newAdditionalProtein);

    IngredientModel* additionalNutrients() const;
    void setAdditionalNutrients(QSharedPointer<IngredientModel> newAdditionalNutrients);

    bool isAddIce() const;
    void setIsAddIce(bool newIsAddIce);

    double iceCost() const;
    void setIceCost(double newIceCost);

signals:
    void idChanged();
    void typeChanged();
    void nameChanged();
    void costChanged();
    void imgPathChanged();
    void ingredientChanged();
    //
    void additionalProteinChanged();
    void additionalNutrientsChanged();
    void isAddIceChanged();
    void iceCostChanged();

private:
    int mId {0};
    int mType {0};
    QString mName {""};
    double mCost {0};
    QString mImgPath {""};
    QString mIngredient {""};
    //additional protein
    QSharedPointer<IngredientModel> mAdditionalProtein {nullptr};
    //additional nutrients
    QSharedPointer<IngredientModel> mAdditionalNutrients {nullptr};
    //
    bool mIsAddIce {false};
    double mIceCost {500};
};
inline bool operator==(const QSharedPointer<ProductInformationItem>& lhs, const QSharedPointer<ProductInformationItem>& rhs)
{
    if (lhs.isNull() && rhs.isNull())
    {
        return true;
    }

    if (lhs.isNull() || rhs.isNull())
    {
        return false;
    }

    return lhs->id() == rhs->id();
}

using ProductInformationModel = QObjectListModelT<ProductInformationItem>;

#endif // PRODUCTINFORMATIONITEM_H
