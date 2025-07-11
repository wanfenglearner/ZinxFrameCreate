#ifndef __ICHANNEL_H__
#define __ICHANNEL_H__

#include <string>
#include <unistd.h>



// 虚通道类
class IChannel {

public:
    IChannel() = default;
    virtual ~IChannel() = default;


    // 初始化函数
    virtual bool init() = 0;

    // 去初始化
    virtual void fini() = 0;

    // 读文件描述符写数据
    virtual std::string readFd() = 0;

    // 写文件描述符读数据
    virtual void writeFd(std::string output) = 0;

    // 得到文件描述符
    virtual int getFd() = 0;

    // 处理消息
    virtual void data_process(std::string output) = 0;

    // 消息发送
    void data_sendout(std::string output);

    // 把数据刷出去
    void flushData();


private:

    std::string m_buffer;

};


#endif 