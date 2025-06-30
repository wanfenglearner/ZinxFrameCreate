#include "stdinchannel.hpp"

#include <iostream>
std::string StdInChannel::readFd() {

    std::string str;
    std::cin >> str;

    return str;
}