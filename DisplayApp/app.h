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
private:
    UBYTE *BlackImage;
    static SysInfo &sysInfo;
    int current;
public:
    void setCurrent(int current);

public:
    int getCurrent() const;
};


#endif //DISPLAYAPP_APP_H
