#ifndef __UPPER_H__
#define __UPPER_H__



#include <string>
#include <algorithm>
#include "ichannel.hpp"


// 转大写类
class Upper : public ZinxHandler{

public:

    Upper() = default;
    ~Upper() = default;

    // 转大写
    std::string toUpper(std::string str);

    // 记录标准输出通道
    void setoutChannel(IChannel* outChannel);

private:
    // 内部消息处理
    ZinxMsg* internel_handler(ZinxMsg* input);

    // 得到下一个消息处理
    ZinxHandler* getNextHandler(ZinxMsg* output);

private:

    IChannel* m_outChannel;

};







#endif 