#ifndef MESSAGE_H
#define MESSAGE_H
#include<string>
typedef enum{Control,Info,Debug,Warning,Error} MSGTYPE; 
class Message
{
public:
    Message();
    Message(std::string time,MSGTYPE type,std::string moudle,std::string data);
    void set(std::string time,MSGTYPE type,std::string moudle,std::string data);
    template<class Archive>
    void serialize(Archive&ar,const uint version);
    std::string time;
    MSGTYPE type;
    std::string moudle;
    std::string data;
};
#endif