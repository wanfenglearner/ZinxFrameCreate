
#ifndef __ZINXTCPCONNECT__
#define __ZINXTCPCONNECT__

#include "ZinxTCP.h"


// TCP连接对象
class TCPData : public Ichannel {

public:
	
	TCPData(int cfd);
	virtual ~TCPData();

public:		// 通过 Ichannel 继承
	bool Init();

	bool ReadFd(std::string& _input);

	bool WriteFd(std::string& _output);

	void Fini();

	int GetFd();

	std::string GetChannelInfo();

	AZinxHandler* GetInputNextStage(BytesMsg& _oInput);

private:

	// 存储连接文件描述符
	int m_cfd;

};


// TCP连接抽象工厂
class TCPConnFactory {

public:

	// 重写方法,创建TCPData对象
	virtual TCPData* createTCPData(int cfd) = 0;

private:


};


// TCP监听类
class TCPListen : public Ichannel {

public:

	TCPListen(unsigned short port, TCPConnFactory* tcpFact);
	~TCPListen();

public:

	// 通过 Ichannel 继承
	bool Init() ;

	bool ReadFd(std::string& _input) ;

	bool WriteFd(std::string& _output) ;

	void Fini() ;

	int GetFd() ;

	std::string GetChannelInfo() ;

	AZinxHandler* GetInputNextStage(BytesMsg& _oInput) ;

private:

	// 存储监听的端口
	unsigned short m_port;

	// 监听的文件描述符
	int m_lfd;

	// 存储TCP创建工程
	TCPConnFactory* m_tcpFact;

};



#endif 



