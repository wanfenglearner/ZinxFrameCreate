#ifndef __ZINXHANDLER_H__
#define __ZINXHANDLER_H__


#include <string>

// 基类 消息类
class ZinxMsg {


public:
    ZinxMsg() = default;
    virtual ~ZinxMsg() = default;

private:

};

// 基类 消息处理类
class ZinxHandler {

public:
    ZinxHandler() = default;
    virtual ~ZinxHandler() = default;

    // 消息处理进入口
    void handler(ZinxMsg* msg);

    // 内部消息处理
    virtual ZinxMsg* internel_handler(ZinxMsg* input) = 0;

    // 得到下一个消息处理
    virtual ZinxHandler* getNextHandler(ZinxMsg* output) = 0;

private:

};





#endif 