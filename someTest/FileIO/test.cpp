//
// Created by wkjwo on 8/2/2019.
//
#include <cstdio>
#include "test.h"
#include <unistd.h>
#include <errno.h>
#include <climits>
#include <sys/types.h>
#include <poll.h>


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
    return ret;
}

int testTruncate() {
    int ret = truncate("../FileIO/pirate.txt", 45);
    if(ret == -1){
        perror("truncate");
        return -1;
    }
    return 0;
}


#define TIMEOUT 5 /* select timeout in seconds */
#define BUF_LEN 1024 /* read buffer in bytes */

int selectExample() {
    struct timeval tv;
    fd_set readfds;
    int ret;

    /*wait on stdin for input*/
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    /*Wait up to five seconds*/
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    /*All right, now block!*/
    ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);
    if(ret == -1){
        perror("select");
        return 1;
    }
    else if(!ret){
        printf("%d seconds elapsed\n", TIMEOUT);
        return 0;
    }

    if(FD_ISSET(STDIN_FILENO, &readfds)){
        char buf[BUF_LEN+1];
        int len;
        /*guaranteed to not block*/
        len = read(STDIN_FILENO, buf, BUF_LEN);
        if(len == -1){
            perror("read");
            return -1;
        }
        if(len){
            buf[len] = '\0';
            printf("read: %s\n", buf);
        }
        return 0;
    }

    fprintf(stderr, "This should not happen!\n");
    return 1;
}

int selectSleep(int sec, int usec) {
    struct timeval tv;
    tv.tv_sec = sec;
    tv.tv_usec = usec;

    /*select for 500 microseconds*/
    select(0, NULL, NULL, NULL, &tv);
    return 0;
}

int pollExample() {
    struct pollfd fds[2];
    int ret;

    /*watch stdin for input*/
    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;

    /*All set, block!*/
    while(1) {
        ret = poll(fds, 1, TIMEOUT * 1000);
        if (ret == -1) {
            perror("poll");
        }
        if (!ret) {
            printf("%d seconds elapsed.\n", TIMEOUT);
        }

        if (fds[0].revents & POLLIN) {
            char buf[BUF_LEN + 1];
            int len;
            /*guaranteed to not block*/
            len = read(STDIN_FILENO, buf, BUF_LEN);
            if (len == -1) {
                perror("read");
            }
            if (len) {
                buf[len] = '\0';
                printf("read: %s\n", buf);
            }
        }
    }

    return 0;

}

int main()
{
    //testO_TRUNC();
    //testMode();
    //testTruncate();
//    while(1){
//        printf("Hello!\n");
//        selectSleep(1, 0);
//    }

    pollExample();
    return 0;
}