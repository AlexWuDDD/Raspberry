//
// Created by wkjwo on 8/2/2019.
//

#ifndef SOMETEST_TEST_H
#define SOMETEST_TEST_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int testO_TRUNC();
int testMode();
int readAllBytes(int fd, char* buf, size_t len);
int readNonBlocking(int fd, char* buf, size_t len);
int writeAllBytes(int fd, char* buf, size_t len);
int testTruncate();
int selectExample();
int selectSleep(int sec, int usec);
int pollExample();
int testfdopen();
int testungetc();
int testfgets();
int testfread();
int testBufferedIO();
int writevExample();
int readvExample();
int mappingExample(int argc, char*argv[]);
int Print_inode_Number(int argc, char* argv[]);
int logical_to_physical(int argc, char* argv[]);
int atexitSample();
int waitExample();

int cpuIsSet();
int processBindCpu();
int getProcessScheduler();


#endif //SOMETEST_TEST_H
