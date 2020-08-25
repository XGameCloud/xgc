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
int main()
{
    cout<<"client start."<<endl;
    io_service ios;
    tcp::socket sock(ios);
    address addr=addr.from_string("49.232.17.128");
    assert(addr.is_v4());
    cout<<addr.to_string()<<endl;
    tcp::endpoint ep(addr,7777);
    sock.connect(ep);
    vector<char> str(100,0);
    sock.read_some(buffer(str));
    cout<<"recive from ip:"<<sock.remote_endpoint().address()<<"\t port:"<<sock.remote_endpoint().port()<<endl;
    
    cout<<"recive :"<<&str[0]<<endl;
    sock.close();
    return 0;
}