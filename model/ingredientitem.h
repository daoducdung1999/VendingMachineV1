#ifndef INGREDIENTITEM_H
#define INGREDIENTITEM_H

#include "qobjectlistmodelt.h"
#include <QObject>
#include <QSharedPointer>

class IngredientItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(double quantity READ quantity WRITE setQuantity NOTIFY quantityChanged FINAL)
    Q_PROPERTY(int amount READ amount WRITE setAmount NOTIFY amountChanged FINAL)
    Q_PROPERTY(double cost READ cost WRITE setCost NOTIFY costChanged FINAL)

public:
    IngredientItem();
    ~IngredientItem();

    QString name() const;
    void setName(const QString &newName);

    double quantity() const;
    void setQuantity(double newQuantity);

    int amount() const;
    void setAmount(int newAmount);

    double cost() const;
    void setCost(double newCost);

signals:
    void nameChanged();
    void quantityChanged();
    void amountChanged();
    void costChanged();

private:
    QString mName {""};
    double mQuantity {0};
    int mAmount {0};
    double mCost {0};
};
using IngredientModel = QObjectListModelT<IngredientItem>;

#endif // INGREDIENTITEM_H
