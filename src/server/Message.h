#ifndef XGC_SERVER_MESSAGE_H
#define XGC_SERVER_MESSAGE_H
#include<stdint.h>
#include<string>
#include<string>
namespace message
{
enum class ControlType : uint8_t
{
    kVideo,
    kVoice,
    kOpintion,
    kLogin,
    kLogout,
    kAck,
    kSendPort
};
class Message
{
public:
    Message ();
    Message(ControlType conrtol_word,
            size_t message_number,
            unsigned int sender_identity,
            unsigned int receiver_identity,
            std::string data);
    void SetMessageData(std::string data);
    template<class Archive>
    void serialize(Archive&ar,const uint version);

private:
    void CalculateCheckSum(void);
    void CalculateDataSize(void);
    ControlType control_word_;
    size_t data_size_;  // 标识数据区的长度
    size_t message_number_;  // 表示这个消息在消息流的位置
    unsigned int sender_identity_;  // 标识发送方的信息
    unsigned int receiver_identity_;  // 标识接收方的信息
    unsigned int check_sum_;  // 校验头部信息准确性
    std::string data_;  // 数据信息

};

} 
//typedef enum{Control,Info,Debug,Warning,Error} MSGTYPE;
// class Message
// {
// public:
//     Message();
//     Message(std::string time,MSGTYPE type,std::string moudle,std::string data);
//     void set(std::string time,MSGTYPE type,std::string moudle,std::string data);
//     template<class Archive>
//     void serialize(Archive&ar,const uint version);
//     std::string time;
//     MSGTYPE type;
//     std::string moudle;
//     std::string data;
// };
#endif