#include "CustomConn.h"
using namespace std;

CustomConn::CustomConn()
{
//    cout << "hi" << endl;
//    lenght = 50;
//    for(int i=0; i<lenght; i++)
//    {
//        RecivedDouble[i]=i*2;
//        cout << i;
//    }

}

int CustomConn::Init()
{
    cout << "start connection" << endl;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        cout << "\n Socket creation error \n" << endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        cout << "\nInvalid address/ Address not supported \n" << endl;
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        cout << "\n Connection to socket failed \n" << endl;
        return -1;
    }

    Send("Handshake");
    // emptying socket
    char buffer[1024] = "xxx";

    if (read(sock , buffer, 1024) == -1)
    {
        cout << "ERROR READ 1" << endl;
        return 1;
    }

    return 0;
}

int CustomConn::Send(string Message)
{
    send(sock, Message.c_str(), Message.size(), 0);
    cout << "Message Send\n" << endl;

    return 1;
}

string CustomConn::ReciveString()
{
    string X = "";
    char buffer[1024] = "xxx";//{'m','m','m'};

    if (read(sock , buffer, 1024) == -1)
    {
        cout << "ERROR READ 2" << endl;
        return X;
    }

    X += buffer;

    return X;
}

int CustomConn::ReciveMessage()
{
    unsigned char buffer[4];// = new buffer;
    unsigned int RecivedInt = 0;

    if (read(sock , buffer, 4) == -1)
    {
        cout << "ERROR READ TYPE" << endl;
        return 1;
    }

    //for (int j=0; j<4; j++)
    //    cout << "Type: " << j << " value: " << hex(buffer[j]) << endl;


    memcpy(&RecivedInt, buffer, sizeof(RecivedInt));
    //cout << "Type full: " << RecivedInt << endl;

    if (RecivedInt == 0xf1f1f1f1)
        return 1;

    if (RecivedInt == 0xf2f2f2f2)
        return -1;

    return 0;

}

int CustomConn::ReciveMessageCount()
{

    unsigned char buffer[4];// = new buffer;
    int RecivedInt = 0;

    if (read(sock , buffer, 4) == -1)
    {
        cout << "ERROR READ TYPE" << endl;
        return 1;
    }

    //for (int j=0; j<4; j++)
    //    cout << "Type: " << j << " value: " << hex(buffer[j]) << endl;


    memcpy(&RecivedInt, buffer, sizeof(RecivedInt));
    //cout << "Type full: " << RecivedInt << endl;

    return RecivedInt;
}


int CustomConn::ReciveFullMessage()
{
    unsigned char buffer[1024];// = new buffer;
    double TmpDouble = 0;

    if (ReciveMessage() != 1)
    {
        cout << "Not message";
        return -1;
    }

    this->lenght = ReciveMessageCount();


    if (read(sock , buffer, lenght*8) == -1)
    {
        cout << "ERROR READ 5" << endl;
        return -2;
    }

    //for (int j=0; j<lenght*8; j++)
    //    cout << "Byte: " << j << " of double: " << j/8 << " value " << hex(buffer[j]) << endl;

    for (int i=0; i<lenght; i++)
    {
        memcpy(&TmpDouble, &buffer[i*8], sizeof(TmpDouble));

        //cout << TmpDouble << endl;
        RecivedDouble[i] =  TmpDouble;
    }
    //string x;
    //cin >> x;
    this->messageCnt = ReciveMessageCount();

    //cout << "check if end" << endl;
    if (ReciveMessage() != -1)
    {
        cout << "Message didnt end here!";
        return -3;
    }

    return 0;

}

double CustomConn::GetDouble(int i)
{
    return RecivedDouble[i];
}
