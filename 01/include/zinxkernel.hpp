#ifndef __ZINXKERNEL_H__
#define __ZINXKERNEL_H__

#include "stdinchannel.hpp"
#include <sys/epoll.h>

class ZinxKernel {


public:

    ZinxKernel();
    virtual ~ZinxKernel();

    // 运行
    void run();
    
    // 添加通道
    void addChannel(StdInChannel* channnel);

    // 删除通道
    void delChannel(StdInChannel channel);

private:

    // 存储标准输入类
    StdInChannel* m_stdInchannel;

    // 存储epoll树节点
    int m_epfd;

};


#endif 