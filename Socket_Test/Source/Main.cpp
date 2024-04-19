#include "../Include/Server/Server.hpp"
#include "../Include/Client/Client.hpp"
#include <thread>
void Server()
{
    Socket::TCP_Server My_Server{8000};
    My_Server.Client_Connected=[](Socket::Connection_Pointer My_Server)
    {
        std::cout<<"Client_Connected : "<<My_Server->Print_Username()<<std::endl;
    };
    My_Server.Client_Disconnected=[](Socket::Connection_Pointer My_Server)
    {
        std::cout<<"Client_Disconnected : "<<My_Server->Print_Username()<<std::endl;
    };
    My_Server.Message_Received=[&My_Server](const std::string &Message)
    {
        std::cout<<Message;
        //My_Server.Broadcast(Message);
    };
    My_Server.Run();
}
void Client()
{
    Socket::TCP_Client My_Client{"pc",8000};
    My_Client.Message_Received=[](const std::string &Message)
    {
        std::cout<<"- New Message : "<<Message;
        //My_Server.Broadcast(Message);
    };
    My_Client.Run();
}
int main() 
{
    Client();

    return 0;
}

