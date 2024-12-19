#ifndef PROCESSORMANAGER_H
#define PROCESSORMANAGER_H

#include <QObject>
#include <QMap>
#include "processorabstract.h"

class ProcessorManager : public QObject
{
    Q_OBJECT
public:
    static ProcessorManager* getInstance();
    ~ProcessorManager();
    bool registerProcessor(ProcessorAbstract* processor);
    bool deregisterProcessor(QString processorName);
    bool publish(std::shared_ptr<InnerMessage> msg, QString processorName);

private:
    ProcessorManager();
    static ProcessorManager self;
    QMap<QString, ProcessorAbstract*> mMapProcessor;
};

#endif // PROCESSORMANAGER_H
