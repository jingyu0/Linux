#include "ImServer.hpp"

int main()
{
    //MysqlClient *mc = new MysqlClient();
    //mc->ConnectMysql();
    //mc->InsertUser("赵六", "4321");
    //delete mc;
    ImServer *im = new ImServer();
    im->InitServer();
    im->Start();
    return 0;
}
