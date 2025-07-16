#include "zinxtcpconnect.h"

TCPData::TCPData(int cfd):
    m_cfd(cfd)
{
}

TCPData::~TCPData()
{
}

bool TCPData::Init()
{
    return false;
}

bool TCPData::ReadFd(std::string& _input)
{
    return false;
}

bool TCPData::WriteFd(std::string& _output)
{
    return false;
}

void TCPData::Fini()
{
}

int TCPData::GetFd()
{
    return 0;
}

std::string TCPData::GetChannelInfo()
{
    return std::string();
}

AZinxHandler* TCPData::GetInputNextStage(BytesMsg& _oInput)
{
    return nullptr;
}


//-------------TCP监听类-------------


TCPListen::TCPListen(unsigned short port, TCPConnFactory* tcpFact):
    m_port(port),
    m_tcpFact(tcpFact)
{
}


// 在框架自动释放堆区TCP连接工厂
TCPListen::~TCPListen()
{
    if (m_tcpFact != nullptr) {
        delete m_tcpFact;
    }
}

bool TCPListen::Init()
{
    return false;
}

bool TCPListen::ReadFd(std::string& _input)
{
    return false;
    
    
}

bool TCPListen::WriteFd(std::string& _output)
{
    return false;
}

void TCPListen::Fini()
{
}

int TCPListen::GetFd()
{
    return 0;
}

std::string TCPListen::GetChannelInfo()
{
    return std::string();
}

AZinxHandler* TCPListen::GetInputNextStage(BytesMsg& _oInput)
{
    return nullptr;
}
