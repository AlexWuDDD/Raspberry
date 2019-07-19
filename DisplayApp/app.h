//
// Created by wkjwo on 7/17/2019.
//

#ifndef DISPLAYAPP_APP_H
#define DISPLAYAPP_APP_H

#include <GUI/GUI_Paint.h>
#include "test.h"
#include <stdlib.h>
#include <GUI/GUI_BMPfile.h>
#include "wiringPi.h"
#include "HW.hpp"
#include <string>
#include "sourceMonitor.hpp"
#include "SysInfo.h"

typedef struct {
    std::string city;
    std::string temperature;
    std::string humidity;
    std::string info;
    std::string date;
    std::string highAndlow;
}WhetherInfo;

class ePaparDisplay
{
public:
    explicit ePaparDisplay();
    ~ePaparDisplay();

    void show_default();
    void show_sysInfo();
    void show_jerry();
    std::string get_IP(std::string ethinterface);
    double get_CpuFree();
    double get_MemFree();

    void refresh();

    void init();
    void end();

    void getWhetherInfo();
    std::string CalculateWeekDay(std::string date);
private:
    UBYTE *BlackImage;
    static SysInfo &sysInfo;
    int current;

    WhetherInfo m_whetherInfo;
public:
    void setCurrent(int current);

public:
    int getCurrent() const;
};


#endif //DISPLAYAPP_APP_H
