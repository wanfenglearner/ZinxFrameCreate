#include "zinxkernel.hpp"
#include <unistd.h>
#include <iostream>




ZinxKernel::ZinxKernel() {

    m_epfd = -1;

    // 创建epoll节点
    int fd = epoll_create(1);
    if(fd != -1) {
        m_epfd = fd;
    }
}
ZinxKernel::~ZinxKernel() {

    // 释放epoll节点
    if(m_epfd != -1) {
        close(m_epfd);
    }
}

ZinxKernel* ZinxKernel::getInstance() {

    static ZinxKernel kernel;

    return &kernel;

}

// 运行
void ZinxKernel::run() {

    struct epoll_event envs[1024];
    int envs_len = sizeof(envs) / sizeof(envs[0]);

    // 循环监听
    while (true)
    {

        // 1. 等输入
        int nums = epoll_wait(m_epfd, envs, envs_len, -1);

        for(int i = 0; i < nums; ++i) {
            
            auto channel = static_cast<IChannel*>(envs[i].data.ptr);

            if((envs[i].events & EPOLLIN) != 0) {

                // 有数据输入
                std::string str =  channel->readFd();
                channel->data_process(str);
            }

            if((envs[i].events & EPOLLOUT) != 0) {

                // 有数据输出
                channel->flushData();

                // 把监听标准输出方向事件删除
                modChannel_delOut(channel);
            }        
            
        }

    }

}

// 添加通道
void ZinxKernel::addChannel(IChannel* channnel) {

    // 调用通道的初始化
    channnel->init();


    // 创建监听标准输入事件
    struct epoll_event env;

    env.data.ptr = channnel;
    env.events = EPOLLIN;

    // 添加事件到epoll树上
    epoll_ctl(m_epfd, EPOLL_CTL_ADD, channnel->getFd(), &env);

}

// 删除通道
void ZinxKernel::delChannel(IChannel* channel) {

    epoll_ctl(m_epfd, EPOLL_CTL_DEL, channel->getFd(), nullptr);

    channel->fini();
}

// 修改epoll节点监听事件
void ZinxKernel::modChannel_addOut(IChannel* channel) {

    // 增加标准输出的事件
    struct epoll_event env;
    env.events = EPOLLIN | EPOLLOUT;
    env.data.ptr = channel;

    epoll_ctl(m_epfd, EPOLL_CTL_MOD, channel->getFd(), &env);

}
void ZinxKernel::modChannel_delOut(IChannel* channel) {

    // 删除标准输出的事件
    struct epoll_event env;
    env.events = EPOLLIN;
    env.data.ptr = channel;

    epoll_ctl(m_epfd, EPOLL_CTL_MOD, channel->getFd(), &env);
}