#include<iostream>
#include "server.h"
#include "message.h"
using namespace std;
using namespace xgc::server;
int main()
{

    Server listen_server;
    listen_server.Init();
    listen_server.WaitforConnect();
}