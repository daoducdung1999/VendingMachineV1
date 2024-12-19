#include "innermessage.h"

InnerMessage::InnerMessage() {
    mCreateDate = QDateTime::currentMSecsSinceEpoch();
    mErrorCode = -1;
}

InnerMessage::~InnerMessage()
{

}

int InnerMessage::messageId() const
{
    return mMessageId;
}

void InnerMessage::setMessageId(int newMessageId)
{
    mMessageId = newMessageId;
}

int InnerMessage::errorCode() const
{
    return mErrorCode;
}

void InnerMessage::setErrorCode(int newErrorCode)
{
    mErrorCode = newErrorCode;
}

long long InnerMessage::createDate() const
{
    return mCreateDate;
}

void InnerMessage::setCreateDate(long long newCreateDate)
{
    mCreateDate = newCreateDate;
}
