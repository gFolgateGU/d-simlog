#include "Test.hpp"
#include "UdpReceiver.hpp"

#include <iostream>

int main()
{
    std::cout << "Hello world" << std::endl;

    UdpReceiver receiver(8080);

    std::cout << "Listening for traffic.." << std::endl;
    receiver.listenForTraffic();

    std::cout << "Program complete" << std::endl;
    return 0;
}