#ifndef __STDINCHANNEL_H__
#define __STDINCHANNEL_H__
#include <string>

#include "ichannel.hpp"
#include "stdoutchannel.hpp"
#include "upper.hpp"

class StdInChannel : public IChannel {

public:

    StdInChannel();
    ~StdInChannel();



    // 初始化函数
    bool init();

    // 去初始化
    void fini();

    // 读文件描述符写数据
    std::string readFd();

    // 写文件描述符读数据
    void writeFd(std::string output);

    // 得到文件描述符
    int getFd();

    // 处理消息
    void data_process(std::string output);

    // 设置转大写类
    void setUpper(Upper* upper);
    

private:

    Upper* m_upper;
};



#endif // __STDINCHANNEL_H__