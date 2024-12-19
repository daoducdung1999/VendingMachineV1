#ifndef INNEREVENT_H
#define INNEREVENT_H

#include "arch/messageabs/innermessage.h"
#include <QString>
#include <QVariant>

class InnerEvent : public InnerMessage
{
public:
    enum EventType
    {
        UNKNOWN_EVENT,
    };

    InnerEvent(const EventType& type, int payload = 0);
    InnerEvent(const EventType& type, const QString& msg);

    EventType getType() const;

    int getPayload() const;

    QString getMessage() const;
    void setMessage(const QString &newMessage);

    QVariant getData() const;
    void setData(const QVariant &newData);

private:
    EventType mType {EventType::UNKNOWN_EVENT};
    int mPayload {0};
    QString mMessage {""};
    QVariant data;
};

#endif // INNEREVENT_H
