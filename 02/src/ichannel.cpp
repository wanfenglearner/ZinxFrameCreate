
#include "ichannel.hpp"
#include "zinxkernel.hpp"


// 消息发送
void IChannel::data_sendout(std::string output) {

    // 将数据存储到缓存
    m_buffer.append(output);

    // 修改epoll树上监听事件(增加监听标准输出的事件)
    ZinxKernel::getInstance()->modChannel_addOut(this);

}


// 把数据刷出去
void IChannel::flushData() {

    writeFd(m_buffer);
    
    m_buffer.clear();
}