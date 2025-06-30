#include "zinxkernel.hpp"


#include <unistd.h>
#include <iostream>

ZinxKernel::ZinxKernel() {

    m_stdInchannel = nullptr;
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
            
            // 取出事件
            auto channel = static_cast<StdInChannel*>(envs[i].data.ptr);

            // 2. 调用标准输入类中的读函数得到数据
            auto str = channel->readFd();

            // 3. 将数据进行回显
            std::cout << "回显数据: " << str << std::endl;
        }

    }
    

}

// 添加通道
void ZinxKernel::addChannel(StdInChannel* channnel) {

    // 创建监听标准输入事件
    struct epoll_event env;

    env.data.ptr = channnel;
    env.events = EPOLLIN;

    // 添加事件到epoll树上
    epoll_ctl(m_epfd, EPOLL_CTL_ADD, STDIN_FILENO, &env);

}

// 删除通道
void ZinxKernel::delChannel(StdInChannel channel) {

    epoll_ctl(m_epfd, EPOLL_CTL_DEL, STDIN_FILENO, nullptr);
}
