//
// Created by wkjwo on 7/17/2019.
//

#include "SysInfoLinux.h"

#include <sys/types.h>
#include <sys/sysinfo.h> //Linux-specific API
#include <fstream>
#include <iostream>


SysInfoLinux::SysInfoLinux() :
        SysInfo(),
        mCpuLoadLastValues()
{

}

void SysInfoLinux::init()
{
    mCpuLoadLastValues = cpuRawData();
}

double SysInfoLinux::cpuLoadAverage()
{
    std::vector<unsigned long long> firstSample = mCpuLoadLastValues;
    std::vector<unsigned long long> secondSample = cpuRawData();
    mCpuLoadLastValues = secondSample;

    double overall = (secondSample[0] - firstSample[0])
                     + (secondSample[1] - firstSample[1])
                     + (secondSample[2] - firstSample[2])
                     + (secondSample[3] - firstSample[3])
                     + (secondSample[4] - firstSample[4])
                     + (secondSample[5] - firstSample[5])
                     + (secondSample[6] - firstSample[6]);

    if(overall == 0){
        return 0;
    }

    double idle = (secondSample[3] - firstSample[3]);
    double usage = (overall - idle)/overall *100;

    return usage;
}

double SysInfoLinux::memoryUsed()
{
    struct sysinfo memInfo;
    sysinfo(&memInfo);

    unsigned long long totalMemory = memInfo.totalram;
    totalMemory += memInfo.totalswap;
    totalMemory *= memInfo.mem_unit;

    unsigned long long totalMemoryUsed = memInfo.totalram - memInfo.freeram;
    totalMemoryUsed += memInfo.totalswap - memInfo.freeswap;
    totalMemoryUsed *= memInfo.mem_unit;

    double percent = (double)totalMemoryUsed / (double)totalMemory * 100.0;
    return percent;
}

std::vector<unsigned long long> SysInfoLinux::cpuRawData()
{
    char data[512] = {};
    std::ifstream infile;
    infile.open("/proc/stat");
    infile.getline(data, 512);
    infile.close();

    std::cout << data << std::endl;
    unsigned long long user = 0,nice = 0,sys = 0,idle =0,iowait = 0,irq = 0,softirq = 0;
    std::sscanf(data, "cpu %llu %llu %llu %llu %llu %llu %llu",
                &user,&nice,&sys,&idle,&iowait,&irq,&softirq);

    std::vector<unsigned long long> rawData;
    rawData.push_back(user);
    rawData.push_back(nice);
    rawData.push_back(sys);
    rawData.push_back(idle);
    rawData.push_back(iowait);
    rawData.push_back(irq);
    rawData.push_back(softirq);

    return rawData;
}
