//
// Created by wkjwo on 7/17/2019.
//

#include "SysInfo.h"
#include "SysInfoLinux.h"


SysInfo& SysInfo::instance()
{
    static SysInfoLinux singleton;

    return singleton;
}

SysInfo::SysInfo()
{
}

SysInfo::~SysInfo()
{
}
