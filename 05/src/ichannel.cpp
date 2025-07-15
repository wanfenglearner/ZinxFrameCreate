
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


// 内部消息处理
ZinxMsg* IChannel::internel_handler(ZinxMsg* input) {

    // 判断消息的输入输出方向
    auto pinput = dynamic_cast<SysIOMsg*>(input);
    if(pinput != nullptr) {

        // 输入方向
        if(pinput->m_direct == SysIOMsg::IN) {

            // 读fd
            std::string resStr = this->readFd();
            // 将消息进行返回
            return new BytesMsg(resStr, pinput->m_direct);
        }
        else {

            auto pmsg = dynamic_cast<BytesMsg*>(pinput);
            if(pmsg != nullptr) {

                // 缓存数据
                m_buffer.append(pmsg->m_content);
                // 添加监听写缓冲区通道
                ZinxKernel::getInstance()->modChannel_addOut(this);
            }

        }
    }
    
    
    return nullptr;


}

// 得到下一个消息处理
ZinxHandler* IChannel::getNextHandler(ZinxMsg* output) {


    // 消息转换
    auto msg = dynamic_cast<BytesMsg*>(output);
    if(msg != nullptr) {

        return this->getInputStage(msg);
    }

}
