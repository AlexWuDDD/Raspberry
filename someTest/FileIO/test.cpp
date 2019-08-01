//
// Created by wkjwo on 8/2/2019.
//
#include <cstdio>
#include "test.h"
#include <unistd.h>

int testO_TRUNC()
{
    int fd = open("../FileIO/testfile.txt", O_WRONLY | O_TRUNC);
    if(fd == -1){
        perror("open");
        return -1;
    }
    char buf[5] = "bbbb";
    write(fd, buf, 5);
    close(fd);
    return 0;
}

int main()
{
    testO_TRUNC();
}