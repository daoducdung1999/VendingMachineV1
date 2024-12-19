#ifndef MAINWINDOWSTORE_H
#define MAINWINDOWSTORE_H

#include <QObject>
#include <QSharedPointer>
#include "arch/flux/action.h"
#include "arch/flux/store.h"
#include "action/actiontype.h"
#include "model/productinformationitem.h"
#include "commonsetting.h"

class MainWindowStore : public QObject, public Store
{
    Q_OBJECT
    Q_PROPERTY(ProductInformationModel* proteinProductInfoModel READ proteinProductInfoModel NOTIFY proteinProductInfoModelChanged FINAL)
    Q_PROPERTY(ProductInformationModel* bcaaProductInfoModel READ bcaaProductInfoModel NOTIFY bcaaProductInfoModelChanged FINAL)
    Q_PROPERTY(ProductInformationModel* preWorkoutProductInfoModel READ preWorkoutProductInfoModel NOTIFY preWorkoutProductInfoModelChanged FINAL)
    Q_PROPERTY(ProductInformationModel* supAndDietProductInfoModel READ supAndDietProductInfoModel NOTIFY supAndDietProductInfoModelChanged FINAL)
    //
    Q_PROPERTY(ProductInformationItem* productInfoDetailItem READ proteinProductInfoDetailItem NOTIFY productInfoDetailItemChanged FINAL)
    Q_PROPERTY(ProductInformationModel* selectedProductModel READ selectedProductModel NOTIFY selectedProductModelChanged FINAL)
    Q_PROPERTY(double totalPayment READ getTotalPayment NOTIFY selectedProductModelChanged FINAL)

public:
    ~MainWindowStore();
    static MainWindowStore* getInstance();

    double getTotalPayment();

    void process(const QSharedPointer<Action>& action) Q_DECL_OVERRIDE;

    ProductInformationModel* proteinProductInfoModel() const;
    void setProteinProductInfoModel(QSharedPointer<ProductInformationModel> newProteinProductInfoModel);

    ProductInformationModel* bcaaProductInfoModel() const;
    void setBcaaProductInfoModel(QSharedPointer<ProductInformationModel> newBcaaProductInfoModel);

    ProductInformationModel* preWorkoutProductInfoModel() const;
    void setPreWorkoutProductInfoModel(QSharedPointer<ProductInformationModel> newPreWorkoutProductInfoModel);

    ProductInformationItem *proteinProductInfoDetailItem() const;
    void setProteinProductInfoDetailItem(QSharedPointer<ProductInformationItem> newProteinProductInfoDetailItem);

    ProductInformationModel* supAndDietProductInfoModel() const;
    void setSupAndDietProductInfoModel(QSharedPointer<ProductInformationModel> newSupAndDietProductInfoModel);

    ProductInformationModel* selectedProductModel() const;
    void setSelectedProductModel(QSharedPointer<ProductInformationModel> newSelectedProductModel);

signals:
    void proteinProductInfoModelChanged();
    void bcaaProductInfoModelChanged();
    void preWorkoutProductInfoModelChanged();
    void supAndDietProductInfoModelChanged();
    //
    void productInfoDetailItemChanged();

    void selectedProductModelChanged();

private:
    /**
     * @brief loadProteinProductInfo
     */
    void loadProteinProductInfo();

    /**
     * @brief loadBcaaProductInfo
     */
    void loadBcaaProductInfo();

    /**
     * @brief loadPreWorkoutProductInfo
     */
    void loadPreWorkoutProductInfo();

    /**
     * @brief loadSupAndDietProductInfo
     */
    void loadSupAndDietProductInfo();
    //
    /**
     * @brief processActionSelectProduct
     * @param action
     */
    void processActionSelectProduct(QSharedPointer<Action> action);

    /**
     * @brief processActionAddIngredient
     * @param action
     */
    void processActionAddIngredient(QSharedPointer<Action> action);

    /**
     * @brief processActionSubIngredient
     * @param action
     */
    void processActionSubIngredient(QSharedPointer<Action> action);

    /**
     * @brief processActionSelectProteinProduct
     * @param itemId
     */
    void processActionSelectProteinProduct(int itemId);

    /**
     * @brief processActionSelectBcaaProduct
     * @param itemId
     */
    void processActionSelectBcaaProduct(int itemId);

    /**
     * @brief processActionSelectPreWorkoutProduct
     * @param itemId
     */
    void processActionSelectPreWorkoutProduct(int itemId);

    /**
     * @brief processActionSelectSupAndDietProduct
     * @param itemId
     */
    void processActionSelectSupAndDietProduct(int itemId);

private:
    MainWindowStore();
    static MainWindowStore* instance;
    //item for display detail
    QSharedPointer<ProductInformationItem> mProductInfoDetailItem {nullptr};
    QSharedPointer<ProductInformationModel> mSelectedProductModel {nullptr};
    //protein
    QSharedPointer<ProductInformationModel> mProteinProductInfoModel {nullptr};
    //bcaa
    QSharedPointer<ProductInformationModel> mBcaaProductInfoModel {nullptr};
    //pre-workout
    QSharedPointer<ProductInformationModel> mPreWorkoutProductInfoModel {nullptr};
    //sup and diet
    QSharedPointer<ProductInformationModel> mSupAndDietProductInfoModel {nullptr};
};

#endif // MAINWINDOWSTORE_H
