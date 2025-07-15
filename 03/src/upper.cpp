#include "upper.hpp"


// 消息处理
void Upper::data_process(std::string str) {

    // 将消息无条件转换成大写
    str = this->toUpper(str);

    // 将大写传递给标准输出通道
    m_outChannel->data_sendout(str);
}

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
