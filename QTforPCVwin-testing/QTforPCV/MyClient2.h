#ifndef CIRCLE_H
#define CIRCLE_H

//#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
//#include <string.h> 

//#define PORT 8080 
#define PORT 56789
//#define PORT 22
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

class CustomConn
{
    public:
    
    int Init();
    
    string ReciveString();
    
    int ReciveFullMessage();

    private:

    int ReciveMessage();

    int ReciveMessageCount();
    
    int Send(string Message);
    
    int sock = 0;
    
};

struct HexCharStruct
{
  unsigned char c;
  HexCharStruct(unsigned char _c) : c(_c) { }
};

inline std::ostream& operator<<(std::ostream& o, const HexCharStruct& hs)
{
  return (o << std::hex << (int)hs.c);
}

inline HexCharStruct hex(unsigned char _c)
{
  return HexCharStruct(_c);
}



#endif
