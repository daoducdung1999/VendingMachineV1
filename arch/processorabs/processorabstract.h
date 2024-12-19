#ifndef PROCESSORABSTRACT_H
#define PROCESSORABSTRACT_H

#include <QObject>
#include <QSharedPointer>
#include <memory>
#include <QTimer>
#include <QVector>
#include "arch/messageabs/innermessage.h"
#include "workerthread.h"
#include <unistd.h>

class ProcessorAbstract : public QObject
{
    Q_OBJECT
public:
    ProcessorAbstract(const QString& processorName);
    virtual ~ProcessorAbstract();
    QString getProcessorName() const;

    bool publish(std::shared_ptr<InnerMessage> msg, const QString& processorName);

signals:
    void sendMessage(std::shared_ptr<InnerMessage> msg);
    void startProcess();
    void stopProcess();

public slots:
    virtual void onMessage(std::shared_ptr<InnerMessage> msg) = 0;
    virtual void onStartProcess();
    virtual void onStopProcess();

private:
    ProcessorAbstract(const ProcessorAbstract&) = delete;
    ProcessorAbstract(ProcessorAbstract&&) = delete;
    ProcessorAbstract& operator=(const ProcessorAbstract&) = delete;
    ProcessorAbstract& operator=(ProcessorAbstract&&) = delete;

private:
    QString mProcessorName;
    QSharedPointer<WorkerThread> mThread;
    QVector<QSharedPointer<QTimer>> mTimerVector;
};

#endif // PROCESSORABSTRACT_H
