#ifndef __UPPER_H__
#define __UPPER_H__



#include <string>
#include <algorithm>
#include "ichannel.hpp"

// 转大写类
class Upper {

public:

    Upper() = default;
    ~Upper() = default;

    // 消息处理
    void data_process(std::string str);

    // 转大写
    std::string toUpper(std::string str);

    // 记录标准输出通道
    void setoutChannel(IChannel* outChannel);


private:

    IChannel* m_outChannel;

};







#endif 