#include "fifochannel.hpp"
#include <fcntl.h>
#include <unistd.h>

FIFOChannel::FIFOChannel(std::string file_name, bool isread) :
    m_filename(file_name),
    m_isRead(isread),
    m_outchannel(nullptr),
    m_fd(-1)
{


}

FIFOChannel::~FIFOChannel() {

}


// 设置输出端的通道信息
void FIFOChannel::setOutChannel(FIFOChannel* channel) {

    m_outchannel = channel;

}

// 初始化函数
bool FIFOChannel::init() {

    bool bRet = false;
    // 打开管道, 得到文件描述符

    // 默认读端
    int flag = O_RDONLY;

    if(m_isRead == false) {

        flag = O_WRONLY;
    }
    int fd = open(m_filename.c_str(), flag | O_NONBLOCK);
    if(fd >= 0) {
        m_fd = fd;
        bRet = true;
    }

    return bRet;

}

// 去初始化
void FIFOChannel::fini() {

    if(m_fd != -1) {
        
        close(m_fd);
    }
}

// 读文件描述符写数据
std::string FIFOChannel::readFd() {

    // 读出数据返回
    char buf[1024] = {0};

    int len = read(m_fd, buf, sizeof(buf));

    return std::string(buf, len);

}

// 写文件描述符读数据
void FIFOChannel::writeFd(std::string output) {

    write(m_fd, output.c_str(), output.size());

}

// 得到文件描述符
int FIFOChannel::getFd() {

    return m_fd;
}

// 处理消息
void FIFOChannel::data_process(std::string output) {

    // 将数据发送给输出端
    m_outchannel->data_sendout(output);

}
