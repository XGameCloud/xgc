#ifndef XGC_MESSAGE_TOOLS_SERIALIZATION_H
#define XGC_MESSAGE_TOOLS_SERIALIZATION_H
#include<string>
#include<iostream>
#include "Message.h"
namespace xgc::message_tools
{
class Serialization
{
public:
    static std::string serialize(const Message & msg);
    static Message disSerialize(const std::string msg);

};
}
#endif