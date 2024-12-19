#include "processorabstract.h"
#include "processormanager.h"

ProcessorAbstract::ProcessorAbstract(const QString &processorName)
    : mProcessorName(processorName)
{
    ProcessorManager::getInstance()->registerProcessor(this);
    //
    mThread = QSharedPointer<WorkerThread>(new WorkerThread());
    mThread->setObjectName(processorName);
    this->moveToThread(mThread.data());
    QObject::connect(mThread.data(), &QThread::finished, this, &ProcessorAbstract::deleteLater);
    mThread->start(QThread::NormalPriority);
    connect(this, &ProcessorAbstract::sendMessage, this, &ProcessorAbstract::onMessage, Qt::QueuedConnection);
    connect(this, &ProcessorAbstract::startProcess, this, &ProcessorAbstract::onStartProcess, Qt::QueuedConnection);
    connect(this, &ProcessorAbstract::stopProcess, this, &ProcessorAbstract::onStopProcess, Qt::QueuedConnection);
}

ProcessorAbstract::~ProcessorAbstract()
{
    ProcessorManager::getInstance()->deregisterProcessor(this->getProcessorName());
    mThread->quit();
    mThread->wait();
}

QString ProcessorAbstract::getProcessorName() const
{
    return mProcessorName;
}

bool ProcessorAbstract::publish(std::shared_ptr<InnerMessage> msg, const QString &processorName)
{
    if (msg == nullptr)
    {
        return false;
    }
    else
    {
        ProcessorManager::getInstance()->publish(msg, processorName);
    }
    return true;
}

void ProcessorAbstract::onStartProcess()
{

}

void ProcessorAbstract::onStopProcess()
{

}
