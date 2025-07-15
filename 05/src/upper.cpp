#include "upper.hpp"


// 转大写
std::string Upper::toUpper(std::string str) {

    std::transform(str.begin(), str.end(), str.begin(), [](char c){
        return std::toupper(c);
    });
    

    return str;
}

// 记录标准输出通道
void Upper::setoutChannel(IChannel* outChannel) {

    m_outChannel = outChannel;
}

// 内部消息处理
ZinxMsg* Upper::internel_handler(ZinxMsg* input) {

    // 得到消息进行转换
    auto msg = dynamic_cast<BytesMsg*>(input);

    if(msg != nullptr) {

        std::string pStr = msg->m_content;

        std::string resStr =  this->toUpper(pStr);

        // 返回转换的结果
        return new BytesMsg(resStr, SysIOMsg::OUT);
    }


}

// 得到下一个消息处理
ZinxHandler* Upper::getNextHandler(ZinxMsg* output) {

    return m_outChannel;
}