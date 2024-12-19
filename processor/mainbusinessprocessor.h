#ifndef MAINBUSINESSPROCESSOR_H
#define MAINBUSINESSPROCESSOR_H

#include "arch/processorabs/processorabstract.h"
#include "middleware/vendingmachinemiddleware.h"
#include "arch/flux/action.h"
#include "model/innerevent.h"

class MainBusinessProcessor : public ProcessorAbstract
{
    Q_OBJECT
public:
    MainBusinessProcessor(const QString& processorName);
    ~MainBusinessProcessor() override;

    void onStartProcess() override;

    void onStopProcess() override;

    void onMessage(std::shared_ptr<InnerMessage> msg) override;

    void setMiddleware(QSharedPointer<VendingMachineMiddleware> newMiddleware);

signals:
    void signalQuit();

public slots:
    void slotReceiveActionFromMiddleware(const QSharedPointer<Action>& action);

private:
    QSharedPointer<VendingMachineMiddleware> mMiddleware {nullptr};
};

#endif // MAINBUSINESSPROCESSOR_H
