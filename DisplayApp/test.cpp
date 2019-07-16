//
// Created by wkjwo on 7/16/2019.
//

#include <GUI/GUI_Paint.h>
#include "test.h"
#include <stdlib.h>
#include <GUI/GUI_BMPfile.h>

void alexTest1()
{
    printf("Alex Test Display 1\n");
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
    Paint_NewImage(BlackImage, EPD_2IN7_WIDTH, EPD_2IN7_HEIGHT, 270, WHITE);
    /********************************************************************************************/

    printf("show window BMP-----------------\r\n");
    Paint_SelectImage(BlackImage);

    Paint_Clear(WHITE);
    GUI_ReadBmp("./pic/1in54.bmp", 0, 0);
    EPD_2IN7_Display(BlackImage);
    DEV_Delay_ms(500);

    printf("show bmp------------------------\r\n");
    Paint_Clear(WHITE);
    GUI_ReadBmp("./pic/2in7.bmp", 0, 0);
    EPD_2IN7_Display(BlackImage);
    DEV_Delay_ms(2000);


    /********************************************************************************************/
    printf("Clear...\r\n");
    EPD_2IN7_Clear();

    printf("Goto Sleep...\r\n");
    EPD_2IN7_Sleep();
    free(BlackImage);
    BlackImage = NULL;

    // close 5V
    printf("close 5V, Module enters 0 power consumption ...\r\n");
    DEV_Module_Exit();
}