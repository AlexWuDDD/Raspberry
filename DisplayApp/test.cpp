//
// Created by wkjwo on 7/16/2019.
//

#include <GUI/GUI_Paint.h>
#include "test.h"
#include <stdlib.h>
#include <GUI/GUI_BMPfile.h>
#include "wiringPi.h"
#include "HW.hpp"

void alexTest4()
{
    printf("Alex Test Display 3 --- text test\n");
    DEV_Module_Init();

    printf("e-Paper Init and Clear...\r\n");
    EPD_2IN7_Init();
    EPD_2IN7_Clear();
    DEV_Delay_ms(500);

    //Create a new image cache
    UBYTE *BlackImage;
    /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
    UWORD Imagesize = ((EPD_2IN7_WIDTH % 8 == 0)? (EPD_2IN7_WIDTH / 8 ): (EPD_2IN7_WIDTH / 8 + 1)) * EPD_2IN7_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return ;
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_2IN7_WIDTH, EPD_2IN7_HEIGHT, ROTATE_270, WHITE);
    /************************************/
    printf("SelectImage:BlackImage\r\n");
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);

    Paint_DrawString_EN(10, 0, "waveshare", &Font16, BLACK, WHITE);
    Paint_DrawString_EN(10, 20, "hello world", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(10, 40, "waveshare", &Font16, BLACK, WHITE);
    Paint_DrawString_EN(10, 60, "hello world", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(10, 80, "waveshare", &Font16, BLACK, WHITE);
    Paint_DrawString_EN(10, 100, "hello world", &Font12, WHITE, BLACK);

    printf("EPD_Display\r\n");
    EPD_2IN7_Display(BlackImage);
    DEV_Delay_ms(2000);

    /************************************/
//    printf("Clear...\r\n");
//    EPD_2IN7_Clear();

    printf("Goto Sleep...\r\n");
    EPD_2IN7_Sleep();
    free(BlackImage);
    BlackImage = NULL;

    // close 5V
    printf("close 5V, Module enters 0 power consumption ...\r\n");
    DEV_Module_Exit();
    return;
}

void alexTest3()
{
    printf("Alex Test Display 3 --- all key test\n");
    if(wiringPiSetup() < 0) return;
    pinMode(KEY1,INPUT);
    pinMode(KEY2,INPUT);
    pinMode(KEY3,INPUT);
    pinMode(KEY4,INPUT);
    pullUpDnControl(KEY1, PUD_UP);
    pullUpDnControl(KEY2, PUD_UP);
    pullUpDnControl(KEY3, PUD_UP);
    pullUpDnControl(KEY4, PUD_UP);
    printf("All Key Test Program!!!\n");
    while(1){
        if(digitalRead(KEY1) == 0){
            printf("KEY1 PRESS\n");
            while(digitalRead(KEY1) == 0){
                delay(100);
            }
            delay(100);
        }
        if(digitalRead(KEY2) == 0){
            printf("KEY2 PRESS\n");
            while(digitalRead(KEY2) == 0){
                delay(100);
            }
            delay(100);
        }
        if(digitalRead(KEY3) == 0){
            printf("KEY3 PRESS\n");
            while(digitalRead(KEY3) == 0){
                delay(100);
            }
            delay(100);
        }
        if(digitalRead(KEY4) == 0){
            printf("KEY4 PRESS\n");
            while(digitalRead(KEY4) == 0){
                delay(100);
            }
            delay(100);
        }
    }

}



void alexTest2()
{
    char KEY = 21;

    printf("Alex Test Display 2 --- key test\n");
    if(wiringPiSetup() < 0) return;
    pinMode(KEY, INPUT);

    pullUpDnControl(KEY, PUD_UP);
    printf("Key Test Program!!!\n");
    while(1){
        if(digitalRead(KEY) == 0){
            printf("KEY PRESS\n");
            while(digitalRead(KEY) == 0){
                delay(100);
            }
            delay(100);
        }
    }


}

void alexTest1()
{
    printf("Alex Test Display 1 --- work or not?\n");
    DEV_Module_Init();

    printf("e-Paper Init and Clear...\n");
    EPD_2IN7_Init();
    EPD_2IN7_Clear();
    DEV_Delay_ms(500);

    //Create a new image cache
    UBYTE *BlackImage;
    UWORD Imagesize = ((EPD_2IN7_WIDTH % 8 == 0)? (EPD_2IN7_WIDTH / 8 ): (EPD_2IN7_WIDTH / 8 + 1)) * EPD_2IN7_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return;
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_2IN7_WIDTH, EPD_2IN7_HEIGHT, ROTATE_0, WHITE);


    printf("show bmp-----------------\r\n");
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);
    GUI_ReadBmp("../pic/2in7.bmp", 0, 0);
    EPD_2IN7_Display(BlackImage);
    DEV_Delay_ms(500);


    /********************************************************************************************/
//    printf("Clear...\r\n");
//    EPD_2IN7_Clear();

    printf("Goto Sleep...\r\n");
    EPD_2IN7_Sleep();
    free(BlackImage);
    BlackImage = NULL;

    // close 5V
    printf("close 5V, Module enters 0 power consumption ...\r\n");
    DEV_Module_Exit();
}