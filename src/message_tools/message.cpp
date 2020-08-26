#include "message.h"
using xgc::message_tools::Message;
using xgc::message_tools::ControlType;
Message::Message(ControlType control_word):control_word_(control_word)
{
    data_="\0";
    CalculateDataSize();
    CalculateCheckSum();
}
Message::Message(ControlType control_word,size_t message_number,
                 unsigned int sender_identity,unsigned int receiver_identity,
                 std::string data):
        control_word_(control_word),message_number_(message_number),
        sender_identity_(sender_identity),receiver_identity_(receiver_identity),data_(data){
    CalculateDataSize();
    CalculateCheckSum();
}

void Message::SetControlWord(ControlType control_word){
    control_word_=control_word;
    CalculateCheckSum();
}

void Message::SetSenderIdentity(unsigned int sender_identity){
    sender_identity_=sender_identity;
    CalculateCheckSum();
}

void Message::SetReceiverIdentity(unsigned int receiver_identity){
    receiver_identity_=receiver_identity;
    CalculateCheckSum();
}

ControlType Message::GetControlWord(void){
    return control_word_;
}

unsigned int Message::GetSenderIdentity(void){
    return sender_identity_;
}

unsigned int Message::GetReceiverIdentity(void){
    return receiver_identity_;
}

std::string Message::GetMessageData(void){
    if(data_size_!=0)
        return data_;
}



void Message::SetMessageData(std::string data){
    data_ = data;
    CalculateDataSize();
    CalculateCheckSum();
}

void Message::CalculateDataSize(){
    if(!data_.empty())
    {
        data_size_=data_.size();
    }
    else
    {
        data_size_=0;
    }
    
}
void Message::CalculateCheckSum(){
    check_sum_=0;

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
