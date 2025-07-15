#include <iostream>
#include "zinxhandler.hpp"
#include <string>
#include <algorithm>

class MyMsg : public ZinxMsg {

public:

    std::string m_data;
    
};



// 标准输入转大写到标准输出


class OutHandler : public ZinxHandler{

public:

    // 内部消息处理
    ZinxMsg* internel_handler(ZinxMsg* input) {

        auto pmsg = dynamic_cast<MyMsg*>(input);

        std::string pstr = pmsg->m_data;
        std::cout << "转换: " << pstr << std::endl;

        return nullptr;
    }

    // 得到下一个消息处理
    ZinxHandler* getNextHandler(ZinxMsg* output) {

        return nullptr;
    }

private:

} pOut;

class InHandler : public ZinxHandler {

public:

    // 内部消息处理
    ZinxMsg* internel_handler(ZinxMsg* input) {

        
        // 将该消息转成大写
        auto pmsg = dynamic_cast<MyMsg*>(input);
        std::string pstr = pmsg->m_data;

        std::string res_str;
        std::transform(pstr.begin(), pstr.end(), std::back_inserter(res_str), [](char c){

            return std::toupper(c);

        });

        // 返回消息
        MyMsg * res_myMsg = new MyMsg();
        res_myMsg->m_data = res_str;

        return res_myMsg;

    }

    // 得到下一个消息处理
    ZinxHandler* getNextHandler(ZinxMsg* output) {

        return &pOut;
    }

private:
    
} pIn;


void test() {

    while (true)
    {
        std::string str;
        std::cin >> str;
        MyMsg msg;
        msg.m_data = str;

        pIn.handler(&msg);
    }
    

}

int main() {

    test();



    return 0;
}