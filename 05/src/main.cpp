#include <iostream>

#include "zinxkernel.hpp"
#include "stdinchannel.hpp"
#include "stdoutchannel.hpp"
#include "upper.hpp"

int main() {


    StdInChannel in_channel;
    StdOutChannel out_channel;
    Upper upper;

    in_channel.setUpper(&upper);
    upper.setoutChannel(&out_channel);


    ZinxKernel::getInstance()->addChannel(&in_channel);
    ZinxKernel::getInstance()->addChannel(&out_channel);

   
    

    ZinxKernel::getInstance()->run();

    return 0;
}