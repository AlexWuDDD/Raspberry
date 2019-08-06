//
// Created by wkjwo on 8/2/2019.
//
#include <cstdio>
#include "test.h"
#include <unistd.h>
#include <errno.h>
#include <climits>

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

int testMode()
{
//    int fd = open("test1.txt", O_WRONLY | O_CREAT | O_TRUNC,
//            S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH);
    int fd = open("test1.txt", O_CREAT | O_EXCL | O_WRONLY,
                  S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH);
    if(fd == -1){
        perror("testMode - open");
        return -1;
    }
    char buf[5] = "aaaa";
    write(fd, buf, 5);
    close(fd);
    return 0;
}

int readAllBytes(int fd, char* buf, size_t len)
{
    if(len > SSIZE_MAX){
        len = SSIZE_MAX;
    }
    ssize_t ret = 0;
    while(len != 0 && (ret = read(fd, buf, len)) != 0){
        if(ret == -1){
            if(errno == EINTR){
                continue;
            }
            perror("read");
            break;
        }
        len -= ret;
        buf += ret;
    }
    return len;
}

int readNonBlocking(int fd, char* buf, size_t len)
{
    if(len > SSIZE_MAX){
        len = SSIZE_MAX;
    }
    ssize_t nr;
    start:
    nr = read(fd, buf, len);
    if( nr == -1){
        if(errno == EINTR){
            goto start;
        }
        if(errno == EAGAIN){
            /*resubmit later and do something else first*/
        }
        else{
            perror("read");
        }
    }
    return nr;
}

int writeAllBytes(int fd, char *buf, size_t len) {
    ssize_t ret, nr;
    while(len != 0 && (ret = write(fd, buf, len)) != 0){
        if(ret == -1){
            if(errno == EINTR){
                continue;
            }
            perror("write");
            break;
        }
        len -= ret;
        buf += ret;
    }
}

int main()
{
    //testO_TRUNC();
    testMode();
}