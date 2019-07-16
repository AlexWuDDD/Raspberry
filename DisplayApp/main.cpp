#include <iostream>
#include <stdlib.h>
#include <csignal>
#include "DEV_Config.h"
#include "test.h"


void Handler(int signo)
{
    //System Exit
    printf("\r\nHandler: exit\r\n");
    DEV_Module_Exit();
}


int main() {
    std::cout << "Hello, Raspberry Pi" << std::endl;
    signal(SIGINT, Handler);

    alexTest1();

    return 0;
}