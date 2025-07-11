#include "stdinchannel.hpp"
#include <iostream>
#include <unistd.h>


StdInChannel::StdInChannel() {

}
StdInChannel::~StdInChannel() {
    
}

// 初始化函数
bool StdInChannel::init() {

    return true;
}

// 去初始化
void StdInChannel::fini() {
    
}


// 读文件描述符写数据
std::string StdInChannel::readFd() {

    std::string str;
    std::cin >> str;

    return str;

}

// 写文件描述符读数据
void StdInChannel::writeFd(std::string output) {

}

// 得到文件描述符
int StdInChannel::getFd() {

    return STDIN_FILENO;
}

// 处理消息
void StdInChannel::data_process(std::string output) {

    m_upper->data_process(output);
  

}

// 设置转大写类
void StdInChannel::setUpper(Upper* upper) {
    
    m_upper = upper;
}


