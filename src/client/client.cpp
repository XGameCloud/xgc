#include "client.h"
#include <boost/lexical_cast.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <vector>
using boost::asio::ip::tcp;
using boost::asio::ip::address;
using boost::asio::io_service;
using boost::asio::buffer;
using std::cout;
using std::endl;
using std::vector;
class Client
{
public:
    Client();
    void Init(void );
    
};
int client()
{
    cout<<"client start."<<endl;
    io_service ios;
    tcp::socket tcp_socket(ios);
    address addr=addr.from_string(kServerIp);
    assert(addr.is_v4());
    cout<<addr.to_string()<<endl;
    tcp::endpoint ep(addr,kListenPort);
    tcp_socket.connect(ep);
    vector<char> str(100,0);
    tcp_socket.read_some(buffer(str));
    cout<<"recive from ip:"<<tcp_socket.remote_endpoint().address()<<"\t port:"<<tcp_socket.remote_endpoint().port()<<endl;
    cout<<"recive :"<<&str[0]<<endl;
    tcp_socket.close();
    return 0;
}