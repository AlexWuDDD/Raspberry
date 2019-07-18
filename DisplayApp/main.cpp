#include <iostream>
#include <stdlib.h>
#include <csignal>
#include "DEV_Config.h"
#include "test.h"
#include "app.h"
#include "SysInfoLinux.h"
#include <memory>
#include "Debug.h"

void Handler(int signo)
{
    //System Exit
    printf("\r\nHandler: exit\r\n");
    DEV_Module_Exit();
    exit(0);
}


int main() {
    int timeout = 0;
    std::cout << "Hello, Raspberry Pi" << std::endl;
    signal(SIGINT, Handler);

    std::unique_ptr<ePaparDisplay> app(new ePaparDisplay);
    app->show_default();

    pinMode(KEY1,INPUT);
    pinMode(KEY2,INPUT);
    pinMode(KEY3,INPUT);
    pinMode(KEY4,INPUT);
    pullUpDnControl(KEY1, PUD_UP);
    pullUpDnControl(KEY2, PUD_UP);
    pullUpDnControl(KEY3, PUD_UP);
    pullUpDnControl(KEY4, PUD_UP);
    printf("All Key Ready!!!\n");
    while(1){
        if(digitalRead(KEY1) == 0){
            printf("KEY1 PRESS\n");
            while(digitalRead(KEY1) == 0){
                app->show_sysInfo();
                delay(100);
                timeout = 0;
            }
            delay(100);
        }
        else if(digitalRead(KEY2) == 0){
            printf("KEY2 PRESS\n");
            while(digitalRead(KEY2) == 0){
                app->getWhetherInfo();
                delay(100);
                timeout = 0;
            }
            delay(100);
        }
        else if(digitalRead(KEY3) == 0){
            printf("KEY3 PRESS\n");
            while(digitalRead(KEY3) == 0){
                delay(100);
                timeout = 0;
            }
            delay(100);
        }
        else if(digitalRead(KEY4) == 0){
            printf("KEY4 PRESS\n");
            while(digitalRead(KEY4) == 0){
                app->refresh();
                delay(100);
                timeout = 0;
            }
            delay(100);
        }
        else{
            //Debug("into timeout cnt - %d\n", timeout);
            ++timeout;
            delay(100);
            if(timeout == 600 && app->getCurrent() != 0){
                Debug("60s time out\n");
                app->show_jerry();
                timeout = 0;
                app->setCurrent(0);
            }
        }
    }
    return 0;
}