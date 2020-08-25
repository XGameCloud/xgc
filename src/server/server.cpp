#include <boost/lexical_cast.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using boost::asio::ip::tcp;
using boost::asio::io_service;
using boost::asio::buffer;
using namespace std;
using namespace boost;
class RelationUint//装有一对链接的客户，存端口号，表示一对连接
{
    public:
    int client1;
    int client2;
    int port;
};

class ConnectManager
{
public:
    static list<RelationUint> ConnectList;//装有现有连接
    RelationUint createConnect();
};
int server()
{
    io_service ios;
    tcp::acceptor ap(ios,tcp::endpoint(tcp::v4(),7777));
    cout<<ap.local_endpoint().address()<<endl;
    while(true)
    {
        tcp::socket sock(ios);
        ap.accept(sock);
        cout<<"client:ip:"<<sock.remote_endpoint().address()<<"\tport:"<<sock.remote_endpoint().port()<<endl;
        cout<<"max listen is "<<sock.max_listen_connections<<endl;
        sock.write_some(buffer("hello asio"));
    }
    //当收到一个socket的连接时，服务端要发出一个端口号，用于新建连接

    return 0;
}