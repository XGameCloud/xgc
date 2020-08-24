#include "Message.h"
using message::Message;
using message::ControlType;
Message::Message(ControlType conrtol_word,size_t message_number,
                 unsigned int sender_identity,unsigned int receiver_identity,
                 std::string data):
    control_word_(conrtol_word),message_number_(message_number),
    sender_identity_(sender_identity),receiver_identity_(receiver_identity),data_(data){
    CalculateDataSize();
    CalculateCheckSum();
}
void Message::SetMessageData(std::string data)
{
    data_ = data;
    CalculateDataSize();
    CalculateCheckSum();
}

template<class Archive>
void Message::serialize(Archive &ar,const uint version)
{
    ar & control_word_ & data_size_ & message_number_ & sender_identity_ &
         receiver_identity_ & check_sum_ & data_ ;
}


// Message::Message(std::string time,MSGTYPE type,std::string moudle,std::string data)
// {
//     set(time,type,moudle,data);
// }
// Message::Message()
// {
//     MSGTYPE type;
//     type=MSGTYPE::Info;
//     set(0,type,"null","null");
// }
// void Message::set(std::string time,MSGTYPE type,std::string moudle,std::string data)
// {
//     this->time=time;
//     this->type=type;
//     this->moudle=moudle;
//     this->data=data;
// }

// template<class Archive>
// void Message::serialize(Archive &ar,const uint version)
// {
//     ar &time &type &moudle &data;
// }
