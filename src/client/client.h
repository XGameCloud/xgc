#ifndef XGC_CLIENT_CLIENT_H
#define XGC_CLIENT_CLIENT_H
#include <string>
static const std::string kServerIp="49.232.17.128";
static const int kListenPort=7777;
namespace xgc
{
namespace client
{
class client
{
private:
    /* data */
public:
    client(/* args */);
    void Init();
    ~client();
};

}
}

#endif