#ifndef __STDOUTCHANNEL_H__
#define __STDOUTCHANNEL_H__

#include "ichannel.hpp"


class StdOutChannel : public IChannel {

public:
    
    StdOutChannel();
    ~StdOutChannel();

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

    // 获得下一个消息处理
    ZinxHandler* getInputStage(BytesMsg* msg);

public:
private:


};


#endif 