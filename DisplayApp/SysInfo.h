//
// Created by wkjwo on 7/17/2019.
//

#ifndef DISPLAYAPP_SYSINFO_H
#define DISPLAYAPP_SYSINFO_H


class SysInfo
{
public:
    static SysInfo& instance();
    virtual ~SysInfo();
    virtual void init() = 0;
    virtual double cpuLoadAverage() = 0;
    virtual double memoryUsed() = 0;

protected:
    explicit SysInfo();

private:
    SysInfo(const SysInfo& rhs); //copy constructor
    SysInfo& operator=(const SysInfo& rhs); //assignment operator
};


#endif //DISPLAYAPP_SYSINFO_H
