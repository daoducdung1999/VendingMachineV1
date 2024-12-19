#include "processormanager.h"
ProcessorManager ProcessorManager::self;

ProcessorManager::ProcessorManager() {}

ProcessorManager *ProcessorManager::getInstance()
{
    return &self;
}

ProcessorManager::~ProcessorManager()
{

}

bool ProcessorManager::registerProcessor(ProcessorAbstract *processor)
{
    if (mMapProcessor.contains(processor->getProcessorName()))
    {
        return false;
    }
    else
    {
        mMapProcessor.insert(processor->getProcessorName(), processor);
    }
    return true;
}

bool ProcessorManager::deregisterProcessor(QString processorName)
{
    if (!mMapProcessor.contains(processorName))
    {
        return false;
    }
    else
    {
        mMapProcessor.remove(processorName);
    }
    return true;
}

bool ProcessorManager::publish(std::shared_ptr<InnerMessage> msg, QString processorName)
{
    if (!mMapProcessor.contains(processorName))
    {
        return false;
    }
    else
    {
        emit mMapProcessor[processorName]->sendMessage(msg);
    }
    return true;
}
