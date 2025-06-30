#include <iostream>

#include "zinxkernel.hpp"
#include "stdinchannel.hpp"
#include "stdoutchannel.hpp"
#include "fifochannel.hpp"

int main() {


    StdInChannel in_channel;
    StdOutChannel out_channel;

    in_channel.setStdOutChannel(&out_channel);

    ZinxKernel::getInstance()->addChannel(&in_channel);
    ZinxKernel::getInstance()->addChannel(&out_channel);


    
    // 管道
    FIFOChannel input_fifo("input", true);
    FIFOChannel output_fifo("output", false);

    input_fifo.setOutChannel(&output_fifo);

    ZinxKernel::getInstance()->addChannel(&input_fifo);
    ZinxKernel::getInstance()->addChannel(&output_fifo);


    ZinxKernel::getInstance()->run();

    return 0;
}