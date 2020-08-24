#ifndef SERIALIZATION_H
#define SERIALIZATION_H
#include<string>
#include<iostream>
#include "Message.h"
class Serialization
{
public:
    static std::string serialize(const Message & msg);
    static Message disSerialize(const std::string msg);

};
#endif