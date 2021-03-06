#include "Serialization.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>
#include "Message.h"
using message::Message;
std::string Serialization::serialize(const Message &msg)
{
    std::ostringstream os;
    boost::archive::text_oarchive archive(os);
    archive<<msg;
    return os.str();
}
Message Serialization::disSerialize(const std::string message)
{
    Message msg;
    std::istringstream is(message);
    boost::archive::text_iarchive archive(is);
    archive>>msg;
    return msg;
}