//
// Created by wkjwo on 7/17/2019.
//

#include "app.h"
#include <ifaddrs.h>
#include <netinet/in.h>
#include <string.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include "Debug.h"
#include "SysInfoLinux.h"
#include "libcurl/libcurl.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include <map>
#include <regex>
std::map<std::string, std::string> WHEATHER =
        {
            {"小雨","XYU.BMP"},
            {"中雨", "ZYU.BMP"},
            {"大雨", "DYU.BMP"},
            {"暴雨", "WET.BMP"},
            {"晴", "QING.BMP"},
            {"多云", "DYZQ.BMP"},
            {"阴", "YIN.BMP"},
            {"雷阵雨", "LZYU.BMP"},
            {"阵雨", "YGTQ.BMP"},
            {"霾", "FOG.BMP"},
            {"雾", "WU.BMP"},
            {"雪", "XUE.BMP"},
            {"雨夹雪", "YJX.BMP"},
            {"冰雹", "BBAO.BMP"}
        };

std::string PicFolder = "../pic/";


SysInfo &ePaparDisplay::sysInfo = SysInfoLinux::instance();

ePaparDisplay::ePaparDisplay()
{
    BlackImage = NULL;
    sysInfo.init();
    current = 0;
}

ePaparDisplay::~ePaparDisplay()
{
    DEV_Module_Exit();
}
void ePaparDisplay::init()
{
    Debug("*****************init****************\n");
    DEV_Module_Init();
    printf("e-Paper Init and Clear...\n");
    EPD_2IN7_Init();
    EPD_2IN7_Clear();
    DEV_Delay_ms(500);

    //Create a new image cache
    /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
    UWORD Imagesize = ((EPD_2IN7_WIDTH % 8 == 0)? (EPD_2IN7_WIDTH / 8 ): (EPD_2IN7_WIDTH / 8 + 1)) * EPD_2IN7_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return ;
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_2IN7_WIDTH, EPD_2IN7_HEIGHT, ROTATE_270, WHITE);

}

void ePaparDisplay::end()
{
    printf("Goto Sleep...\r\n");
    EPD_2IN7_Sleep();
    free(BlackImage);
    BlackImage = NULL;

    // close 5V
    printf("close 5V, Module enters 0 power consumption ...\r\n");
    DEV_Module_Exit();
}

void ePaparDisplay::show_default()
{
    show_jerry();
}

std::string ePaparDisplay::get_IP(std::string ethinterface)
{
    int sock_get_ip;
    char ipaddr[50];

    struct   sockaddr_in *sin;
    struct   ifreq ifr_ip;

    if ((sock_get_ip=socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        Debug("socket create fails--- errno: %d - %s!\n", errno, strerror(errno));
        return "NaN";
    }

    memset(&ifr_ip, 0, sizeof(ifr_ip));
    strncpy(ifr_ip.ifr_name, ethinterface.c_str(), sizeof(ifr_ip.ifr_name) - 1);

    if( ioctl( sock_get_ip, SIOCGIFADDR, &ifr_ip) < 0 )
    {
        Debug("socket ioctl fails--- errno: %d - %s!\n", errno, strerror(errno));
        return "NaN";
    }
    sin = (struct sockaddr_in *)&ifr_ip.ifr_addr;
    strcpy(ipaddr,inet_ntoa(sin->sin_addr));

    Debug("%s ip : %s\n", ethinterface.c_str(), ipaddr);
    close( sock_get_ip );

    return std::string(ipaddr);
}

double ePaparDisplay::get_CpuFree()
{
    return  100.0 - sysInfo.cpuLoadAverage();
}

double ePaparDisplay::get_MemFree()
{
    return 100.0 - sysInfo.memoryUsed();
}

void ePaparDisplay::refresh()
{
    if(current == 1){
        show_sysInfo();
    }
}

void ePaparDisplay::show_sysInfo()
{
    init();
    printf("SelectImage:BlackImage\r\n");
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);

    double cpufree = get_CpuFree();
    double memfree = get_MemFree();

    Paint_DrawString_EN(10, 0, "Jerry is very handsome !!!", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(10, 20, ("CPU free: " + std::to_string(cpufree)).c_str(), &Font12, WHITE, BLACK);
    Paint_DrawString_EN(10, 40, ("Mem free: " + std::to_string(memfree)).c_str(), &Font12, WHITE, BLACK);
    Paint_DrawString_EN(10, 60, ("Eth cable: " + get_IP("eth0")).c_str(), &Font12, WHITE, BLACK);
    Paint_DrawString_EN(10, 80, ("Wifi: " + get_IP("wlan0")).c_str(), &Font12, WHITE, BLACK);

    printf("EPD_Display\r\n");
    EPD_2IN7_Display(BlackImage);
    DEV_Delay_ms(2000);
    end();
    current = 1;
}

void ePaparDisplay::show_jerry()
{
    DEV_Module_Init();

    printf("e-Paper Init and Clear...\n");
    EPD_2IN7_Init();
    EPD_2IN7_Clear();
    DEV_Delay_ms(500);

    //Create a new image cache
    UWORD Imagesize = ((EPD_2IN7_WIDTH % 8 == 0)? (EPD_2IN7_WIDTH / 8 ): (EPD_2IN7_WIDTH / 8 + 1)) * EPD_2IN7_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return;
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_2IN7_WIDTH, EPD_2IN7_HEIGHT, ROTATE_270, WHITE);


    printf("show bmp-----------------\r\n");
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);
    GUI_ReadBmp("../pic/jerry.bmp", 44, 0);
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

int ePaparDisplay::getCurrent() const {
    return current;
}

void ePaparDisplay::setCurrent(int current) {
    ePaparDisplay::current = current;
}

void ePaparDisplay::getWhetherInfo() {
    std::string key = "7dec5f6344097139a28740b630476910";
    std::string url = "http://apis.juhe.cn/simpleWeather/query";
    std::string realURL = url + "?city=%e4%b8%8a%e6%b5%b7" + "&key=" + key;
    Debug("Target: %s\n", realURL.c_str());

    std::string weatherInfo;
    HttpGet(realURL.c_str(), weatherInfo);

    rapidjson::Document doc;

    if(!doc.Parse(weatherInfo.data()).HasParseError()){
        if(doc.HasMember("result")){
            rapidjson::Value &result = doc["result"];
            m_whetherInfo.city = result["city"].GetString();

            rapidjson::Value &realtime = result["realtime"];
            m_whetherInfo.temperature = realtime["temperature"].GetString();
            m_whetherInfo.humidity = realtime["humidity"].GetString();
            m_whetherInfo.info = realtime["info"].GetString();

            rapidjson::Value &future = result["future"];
            m_whetherInfo.date = future[0]["date"].GetString();
            m_whetherInfo.highAndlow = future[0]["temperature"].GetString();
        }
    }
    else{
        Debug("analysis weather info error\n");
    }

    init();
    printf("SelectImage:BlackImage\r\n");
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);

//    Paint_DrawString_EN(10, 0, "City: Shanghai", &Font12, WHITE, BLACK);
//    Paint_DrawString_EN(10, 20, ("temperature: "+ m_whetherInfo.temperature).c_str(), &Font12, WHITE, BLACK);
//    Paint_DrawString_EN(10, 40, ("humidity: " + m_whetherInfo.humidity).c_str(), &Font12, WHITE, BLACK);
//    Paint_DrawString_EN(10, 60, ("info: " + m_whetherInfo.info).c_str(), &Font12, WHITE, BLACK);
//    Paint_DrawString_EN(10, 90, ("date: " + m_whetherInfo.date).c_str(), &Font12, WHITE, BLACK);
//    Paint_DrawString_EN(10, 110, ("H&L: " + m_whetherInfo.highAndlow).c_str(), &Font12, WHITE, BLACK);

    Paint_DrawString_EN(10, 10, "T", &Font24, WHITE, BLACK);
    Paint_DrawString_EN(20, 15, "(CEL):", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(10, 40, m_whetherInfo.temperature.c_str(), &Font24, WHITE, BLACK);
    Paint_DrawLine(88, 5, 88, 70, BLACK, DOT_PIXEL_3X3, LINE_STYLE_SOLID);
    Paint_DrawString_EN(98, 10, "HUM:", &Font24, WHITE, BLACK);
    Paint_DrawString_EN(98, 40, (m_whetherInfo.humidity + "%").c_str(), &Font24, WHITE, BLACK);
    Paint_DrawLine(176, 5, 176, 70, BLACK, DOT_PIXEL_3X3, LINE_STYLE_SOLID);
    GUI_ReadBmp((PicFolder + WHEATHER.at(m_whetherInfo.info)).c_str(), 190, 5);
    Paint_DrawLine(5, 70, 260, 70, BLACK, DOT_PIXEL_3X3, LINE_STYLE_SOLID);
    Paint_DrawString_EN(40, 90, (m_whetherInfo.highAndlow.substr(0,5) + "   "
            + CalculateWeekDay(m_whetherInfo.date)).c_str(), &Font24, WHITE, BLACK);
    Paint_DrawLine(5, 130, 260, 130, BLACK, DOT_PIXEL_3X3, LINE_STYLE_SOLID);
    Paint_DrawString_EN(40, 140, m_whetherInfo.date.c_str(), &Font24, WHITE, BLACK);

    printf("EPD_Display\r\n");
    EPD_2IN7_Display(BlackImage);
    DEV_Delay_ms(2000);
    end();
    current = 2;

    return;
}

std::string ePaparDisplay::CalculateWeekDay(std::string date)
{
    std::regex pattern("^(\\d+)-(\\d+)-(\\d+)$");
    std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
    int y = 0, m = 0, d = 0;
    if(std::regex_match (date,sm,pattern)) {
        y = std::stoi(sm[1]);
        m = std::stoi(sm[2]);
        d = std::stoi(sm[3]);
    }
    Debug("%d - %d - %d\n", y, m, d);

    if(m==1||m==2) {
        m+=12;
        y--;
    }
    int iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    switch(iWeek)
    {
        case 0: return "MON"; break;
        case 1: return "TUE"; break;
        case 2: return "WED"; break;
        case 3: return "THU"; break;
        case 4: return "FRI"; break;
        case 5: return "SAT"; break;
        case 6: return "SUN"; break;
        default: return "ERR";
    }
}