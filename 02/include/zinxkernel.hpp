#ifndef __ZINXKERNEL_H__
#define __ZINXKERNEL_H__

#include "stdinchannel.hpp"
#include "ichannel.hpp"
#include <sys/epoll.h>

class ZinxKernel {
public:

    virtual ~ZinxKernel();

    static ZinxKernel* getInstance();

    // 运行
    void run();
    
    // 添加通道
    void addChannel(IChannel* channnel);

    // 删除通道
    void delChannel(IChannel* channel);

    // 修改epoll节点监听事件
    void modChannel_addOut(IChannel* channel);
    void modChannel_delOut(IChannel* channel);

private:
    ZinxKernel();

private:

    // 存储epoll树节点
    int m_epfd;

};


#endif 