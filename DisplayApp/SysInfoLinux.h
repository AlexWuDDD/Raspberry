//
// Created by wkjwo on 7/17/2019.
//

#ifndef DISPLAYAPP_SYSINFOLINUX_H
#define DISPLAYAPP_SYSINFOLINUX_H

#include "SysInfo.h"
#include <vector>
class SysInfoLinux : public SysInfo
{
public:
    SysInfoLinux();

    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;

private:
    std::vector<unsigned long long> cpuRawData();

private:
    std::vector<unsigned long long> mCpuLoadLastValues;
};


#endif //DISPLAYAPP_SYSINFOLINUX_H
