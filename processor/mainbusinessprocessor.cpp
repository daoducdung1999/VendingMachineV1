#include "mainbusinessprocessor.h"

MainBusinessProcessor::MainBusinessProcessor(const QString &processorName)
    : ProcessorAbstract(processorName)
{
}

MainBusinessProcessor::~MainBusinessProcessor()
{
}

void MainBusinessProcessor::onStartProcess()
{
    ProcessorAbstract::onStartProcess();
}

void MainBusinessProcessor::onStopProcess()
{
    ProcessorAbstract::onStopProcess();
}

void MainBusinessProcessor::onMessage(std::shared_ptr<InnerMessage> msg)
{
    if (auto event = std::dynamic_pointer_cast<InnerEvent>(msg))
    {
        switch (event->getType()) {
        default:
            break;
        }
    }
    else
    {
        //do nothing
    }
}

void MainBusinessProcessor::setMiddleware(QSharedPointer<VendingMachineMiddleware> newMiddleware)
{
    mMiddleware = newMiddleware;
}

void MainBusinessProcessor::slotReceiveActionFromMiddleware(const QSharedPointer<Action> &action)
{
    switch (action->getType<ActionType>())
    {
    case ActionType::TestAction:
    {
        auto data = action->getPayload<QVariant>();
        break;
    }
    default:
        break;
    }
}
