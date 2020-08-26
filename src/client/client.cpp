#include "client.h"
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <vector>
#include "config.h"
using boost::asio::ip::tcp;
using boost::asio::ip::address; 
using boost::asio::io_service;
using boost::asio::buffer;
using std::vector;
using xgc::client::Client;
Client::Client():ios_(),tcp_socket_(ios_){
    

}
void Client::Init(std::string ip=kServerIp,int port=kListenPort)
{
    xgclog<<"client starting."<<xgcendl;
    address addr=addr.from_string(ip);
    assert(addr.is_v4());
    xgclog<<addr.to_string()<<xgcendl;
    tcp::endpoint ep(addr,port);
    server_endpoint_=ep;
    xgclog<<"client started."<<xgcendl;
    
}

int Client::ConnectServer(std::string ip=kServerIp,int listen_port=kListenPort)
{
    xgclog<<"client connecting."<<xgcendl;
    tcp_socket_.connect(server_endpoint_);
    vector<char> str(100,0);
    tcp_socket_.read_some(buffer(str));
    xgclog<<"recive from ip:"<<tcp_socket_.remote_endpoint().address()<<"\t port:"<<tcp_socket_.remote_endpoint().port()<<xgcendl;
    xgclog<<"recive :"<<&str[0]<<xgcendl;
}
void Client::DisconnectServer()
{
    tcp_socket_.close();
}
