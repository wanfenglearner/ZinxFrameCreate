#include "zinxhandler.hpp"


// 消息处理进入口
void ZinxHandler::handler(ZinxMsg* msg) {


    // 内部处理
    auto pmsg = this->internel_handler(msg);

    if(pmsg != nullptr) {

        // 得到下一个处理
        auto nhandler  = this->getNextHandler(pmsg);
        if(nhandler != nullptr) {
            nhandler->handler(pmsg);
        }

        delete pmsg;
    }

}

// ------------消息方向--------------
SysIOMsg::SysIOMsg(SysIOMsg::IORirect direct):
    m_direct(direct)
{


}

// ----------------具体的消息-----------------
BytesMsg::BytesMsg(const std::string& content, const SysIOMsg::IORirect& direct) :
    m_content(content),
    SysIOMsg(direct)
{

}
