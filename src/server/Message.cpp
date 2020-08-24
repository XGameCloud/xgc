#include "Message.h"
Message::Message(std::string time,MSGTYPE type,std::string moudle,std::string data)
{
    set(time,type,moudle,data);
}
Message::Message()
{
    MSGTYPE type;
    type=MSGTYPE::Info;
    set(0,type,"null","null");
}
void Message::set(std::string time,MSGTYPE type,std::string moudle,std::string data)
{
    this->time=time;
    this->type=type;
    this->moudle=moudle;
    this->data=data;
}

template<class Archive>
void Message::serialize(Archive&ar,const uint version)
{
    ar &time &type &moudle &data;
}
