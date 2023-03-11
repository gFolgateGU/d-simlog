#ifndef DSIMLOG_UDPRECEIVER_HPP
#define DSIMLOG_UDPRECEIVER_HPP

#include <string>

class UdpReceiver
{

public:

    UdpReceiver(unsigned int port);

    ~UdpReceiver() = default;

    void listenForTraffic();

private:

    void initReceiver();
    
    static constexpr unsigned int MAX_BUFF_SIZE = 4096;

    int          mSockFd { -1 };
    unsigned int mPort { 0 };
    char         mBuffer[MAX_BUFF_SIZE];
    bool         mIsInitialized { false };

};

#endif