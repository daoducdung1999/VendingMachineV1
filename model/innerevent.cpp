#include "innerevent.h"

InnerEvent::InnerEvent(const EventType &type, int payload)
    : mType(type), mPayload(payload)
{
}

InnerEvent::InnerEvent(const EventType &type, const QString &msg)
    : mType(type), mMessage(msg)
{
}

InnerEvent::EventType InnerEvent::getType() const
{
    return mType;
}

int InnerEvent::getPayload() const
{
    return mPayload;
}

QString InnerEvent::getMessage() const
{
    return mMessage;
}

void InnerEvent::setMessage(const QString &newMessage)
{
    mMessage = newMessage;
}

QVariant InnerEvent::getData() const
{
    return data;
}

void InnerEvent::setData(const QVariant &newData)
{
    data = newData;
}
