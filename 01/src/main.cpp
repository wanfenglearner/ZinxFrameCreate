#include <iostream>

#include "zinxkernel.hpp"
#include "stdinchannel.hpp"

int main() {

   
   ZinxKernel kernel;

    StdInChannel in_channel;

    // 添加通道到框架中
   kernel.addChannel(&in_channel);

    kernel.run();


    return 0;
}