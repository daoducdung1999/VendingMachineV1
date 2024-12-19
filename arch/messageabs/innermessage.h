#ifndef INNERMESSAGE_H
#define INNERMESSAGE_H

#include <string>
#include <cstdio>
#include "cereal/archives/portable_binary.hpp"
#include <QDateTime>

class InnerMessage
{
public:
    InnerMessage();

    virtual ~InnerMessage();

    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(mCreateDate, mErrorCode, mMessageId);
    }

    template <class classtype>
    bool doSerialize(std::string& out, std::shared_ptr<classtype> obj)
    {
        try {
            std::ostringstream outputStr;
            cereal::PortableBinaryOutputArchive arcOut(outputStr);
            arcOut(obj);
            out = outputStr.str();
        } catch (cereal::Exception ex) {
            return false;
        }

        return true;
    }

    template <class classtype>
    bool doDeSerialize(uint8_t* buf, int len, std::shared_ptr<classtype>& obj)
    {
        try {
            std::istringstream inputStream(std::string((char*)buf, len));
            cereal::PortableBinaryInputArchive arcIn(inputStream);
            arcIn(obj);
        } catch (cereal::Exception ex) {
            return false;
        }

        return true;
    }

    int messageId() const;
    void setMessageId(int newMessageId);

    int errorCode() const;
    void setErrorCode(int newErrorCode);

    long long createDate() const;
    void setCreateDate(long long newCreateDate);

private:
    long long mCreateDate;
    int mErrorCode {0};
    int mMessageId {-1};
};


#endif // INNERMESSAGE_H
