#include<iostream>
#include "client.h"
using namespace std;
using namespace xgc::client;
int main(){
    Client test_client;
    test_client.Init();
    test_client.ConnectServer();
    test_client.DisconnectServer();

}
