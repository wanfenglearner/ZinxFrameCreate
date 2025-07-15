#include "stdoutchannel.hpp"
#include <iostream>
#include "zinxkernel.hpp"

StdOutChannel::StdOutChannel() {

}
StdOutChannel::~StdOutChannel() {

    
}


// 初始化函数
bool StdOutChannel::init() {

    return true;
}

// 去初始化
void StdOutChannel::fini() {

}

// 读文件描述符写数据
std::string StdOutChannel::readFd() {

    return std::string();
}

// 写文件描述符读数据
void StdOutChannel::writeFd(std::string output) {

    std::cout << "回显数据: " << output << std::endl;
}

// 得到文件描述符
int StdOutChannel::getFd() {

    return STDOUT_FILENO;
}

// 获得下一个消息处理
ZinxHandler* StdOutChannel::getInputStage(BytesMsg* msg) {

    return nullptr;
}


