#ifndef __FIFOCHANNEL_H__
#define __FIFOCHANNEL_H__


#include "ichannel.hpp"


// 管道通道
class FIFOChannel : public IChannel {


public:

    // file_name 指明路径名 isread 判断是读还是写端
    FIFOChannel(std::string file_name, bool isread);

    ~FIFOChannel();

    // 设置输出端的通道信息
    void setOutChannel(FIFOChannel* channel);


public: // 继承
    // 初始化函数
    bool init();

    // 去初始化
    void fini();

    // 读文件描述符写数据
    std::string readFd();

    // 写文件描述符读数据
    void writeFd(std::string output);

    // 得到文件描述符
    int getFd();

    // 处理消息
    void data_process(std::string output);


private:

    // 存储管道路径名
    std::string m_filename;

    // 打开管道对应的文件描述符
    int m_fd;

    // 记录读还是写状态
    bool m_isRead;

    // 记录输出端的信息
    FIFOChannel* m_outchannel;

};





#endif 