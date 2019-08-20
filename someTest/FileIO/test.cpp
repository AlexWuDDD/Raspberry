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
#include <limits.h>
#include <errno.h>
#include <cstring>
#include <sys/uio.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fs.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sched.h>

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

int testfdopen() {
    FILE *stream;
    int fd;

    fd = open("../FileIO/testfile.txt", O_RDWR);
    if(fd == -1){
        perror("open");
        return -1;
    }
    stream = fdopen(fd, "w+");
    if(!stream){
        perror("fdopen");
        return -2;
    }

    fclose(stream);
    return 0;
}

int testungetc() {
    FILE *stream = fopen("test.txt", "r");
    if(!stream){
        perror("fopen");
        return -1;
    }
    int ret;
    ret = fgetc(stream);
    if(ret == EOF){
        perror("fgetc");
        return -1;
    }
    printf("ret = %c\n", (char)ret);

    ret = fgetc(stream);
    if(ret == EOF){
        perror("fgetc");
        return -1;
    }
    printf("ret = %c\n", (char)ret);

    ret = ungetc(ret, stream);
    if(ret == EOF){
        perror("ungetc");
        return -1;
    }
    printf("ret = %c\n", (char)ret);

    ret = fgetc(stream);
    if(ret == EOF){
        perror("fgetc");
        return -1;
    }
    printf("ret = %c\n", (char)ret);


    fclose(stream);

    return 0;
}

int testfgets() {
    FILE *stream = fopen("aaaa.txt", "r");
    while(1) {
        char buf[LINE_MAX] = {0};
        if (!fgets(buf, LINE_MAX, stream)) {
            perror("fgets - 1");
            break;
        }
        printf("%s", buf);
    }
    return 0;
}

int testfread() {
    FILE *stream = fopen("aaaa.txt", "r");
    char buf[64] = {0};
    size_t nr;
    nr = fread(buf, 3, sizeof(buf), stream);
    printf("nr: %d\n", nr);
    printf("%s", buf);
    fclose(stream);
    return 0;
}

int testBufferedIO() {
    FILE *in, *out;
    struct pirate{
        char name[100];
        unsigned long booty;
        unsigned long beard_len;
    }p, blackbeard = {"Edward Teach", 950, 48};

    out = fopen("data", "w");
    if(!out){
        perror("fopen");
        return 1;
    }
    if(!fwrite(&blackbeard,
            1, sizeof(blackbeard), out)){
        perror("fwrite");
        return 1;
    }

    if (fclose (out)) {
        perror ("fclose");
        return 1; }
    in = fopen ("data", "r");
    if (!in) {
        perror ("fopen");
        return 1; }
    if (!fread (&p, 1, sizeof(struct pirate), in)) {
        perror ("fread");
        return 1;
    }
    if (fclose (in)) {
        perror ("fclose");
        return 1;
    }
    printf ("name=\"%s\" booty=%lu beard_len=%u\n", p.name, p.booty, p.beard_len);
    return 0;

}

int writevExample() {
    struct iovec iov[3];
    ssize_t nr;
    int fd, i;
    char *buf[] = {
            "The term buccaneer comes from the word boucan.\n",
            "A boucan is a wooden frame used for cooking meat.\n",
            "Buccaneer is the West Indies name for a pirate.\n"
    };

    fd = open("buccaneer.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if(fd == -1){
        perror("open");
        return 1;
    }
    for(i = 0; i < 3; ++i){
        iov[i].iov_base = buf[i];
        iov[i].iov_len = strlen(buf[i]) + 1;
    }
    nr = writev(fd, iov, 3);
    if(nr == -1){
        perror("writev");
        return 1;
    }
    printf("write %d bytes\n", nr);
    if(close(fd)){
        perror("close");
        return 1;
    }
    return 0;
}

int readvExample() {
    char foo[48], bar[51], baz[49];
    struct iovec iov[3];
    ssize_t nr;
    int fd, i;
    fd = open("buccaneer.txt", O_RDONLY);
    if(fd == -1){
        perror("open");
        return 1;
    }
    iov[0].iov_base = foo;
    iov[0].iov_len = sizeof(foo);
    iov[1].iov_base = bar;
    iov[1].iov_len = sizeof(bar);
    iov[2].iov_base = baz;
    iov[2].iov_len = sizeof(baz);

    nr = readv(fd, iov, 3);
    if(nr == -1){
        perror("readv");
        return 1;
    }
    for(i = 0; i < 3; ++i){
        printf("%d: %s", i, (char*)iov[i].iov_base);
    }
    if(close(fd)){
        perror("close");
        return 1;
    }
    return 0;
}

int mappingExample(int argc, char*argv[]) {
    struct stat sb;
    off_t len;
    char *p;
    int fd;
    if(argc < 2){
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1){
        perror("open");
        return 1;
    }
    if(fstat(fd, &sb) == -1){
        perror("fstat");
        return 1;
    }
    if(!S_ISREG(sb.st_mode)){
        fprintf(stderr, "%s is not a file\n", argv[1]);
        return 1;
    }
    p = (char*)mmap(0, sb.st_size,
            PROT_READ, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED){
        perror("mmap");
        return 1;
    }
    if(close(fd) == -1){
        perror("close");
        return 1;
    }

    for(len = 0; len < sb.st_size; ++len)
        putchar(p[len]);
    if(munmap(p, sb.st_size) == -1){
        perror("munmap");
        return 1;
    }
    return 0;

}

int get_inode(int fd)
{
    struct stat buf;
    int ret;
    ret = fstat(fd, &buf);
    if(ret < 0){
        perror("fstat");
        return -1;
    }
    return buf.st_ino;
}


int Print_inode_Number(int argc, char* argv[]) {
    int fd, inode;
    if(argc<2){
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        return 1;
    }
    fd = open(argv[1], O_RDONLY);
    if(fd<0){
        perror("open");
        return 1;
    }

    inode = get_inode(fd);
    printf("%s - inode: %d\n", argv[1], inode);
    if(close(fd) < 0){
        perror("close");
    }
    return 0;
}

int get_block(int fd, int logical_block)
{
    int ret;
    ret = ioctl(fd, FIBMAP, &logical_block);
    if(ret < 0) {
        perror("ioctl");
        return -1;
    }
    return logical_block;
}

int get_nr_blocks(int fd)
{
    struct stat buf;
    int ret;
    ret = fstat(fd, &buf);
    if(ret < 0){
        perror("fstat");
        return -1;
    }
    return buf.st_blocks;
}

void print_blocks(int fd)
{
    int nr_blocks, i;
    nr_blocks = get_nr_blocks(fd);
    if(nr_blocks < 0){
        fprintf(stderr, "get_nr_blocks failed!\n");
        return;
    }
    if(nr_blocks == 0){
        printf("no allocared blocks\n");
        return;
    }
    else if(nr_blocks == 1){
        printf("1 block\n\n");
    }
    else{
        printf("%d blocks\n\n", nr_blocks);
    }

    for(i = 0; i < nr_blocks; ++i){
        int phys_block = get_block(fd, i);
        if(phys_block < 0){
            fprintf(stderr, "get_block failed!\n");
            return;
        }
        if(!phys_block){
            continue;
        }
        printf("(%u, %u)", i, phys_block);
    }
    putchar('\n');
}



int logical_to_physical(int argc, char **argv) {

    int fd;

    if(argc < 2){
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        return 1;
    }
    fd = open(argv[1], O_RDONLY);
    if(fd < 0){
        perror("open");
        return 1;
    }
    print_blocks(fd);
    if(close(fd) < 0){
        perror("close");
    }
    return 0;
}

void out(void)
{
    long atexit_max;
    atexit_max = sysconf(_SC_ATEXIT_MAX);
    printf("atexit() succeeded! atexit_max=%ld\n",
            atexit_max);
}


int atexitSample() {
    if(atexit(out)){
        fprintf(stderr, "atexit() failed!\n");
    }
    return 0;
}

int waitExample() {
    int status;
    pid_t pid;
    if(!fork()){
        return 1;
    }

    pid = wait(&status);
    if(pid == -1){
        perror("wait");
    }
    printf("pid=%d\n", pid);

    if(WIFEXITED(status)){
        printf("Normal termination with exit status=%d\n",
                WEXITSTATUS(status));
    }

    if(WIFSIGNALED(status)){
        printf("Killed by signal=%d%s\n",
                WTERMSIG(status),
                WCOREDUMP(status)?"(dumped core)": "");
    }

    if(WIFSTOPPED(status)){
        printf("Stopped by signal = %d\n",
                WSTOPSIG(status));
    }

    if(WIFCONTINUED(status)){
        printf("Continued\n");
    }

    return 0;
}

int cpuIsSet() {
    cpu_set_t set;
    int ret, i;
    CPU_ZERO(&set);
    ret = sched_getaffinity(0, sizeof(cpu_set_t), &set);
    if(ret == -1)
        perror("sched_getaffinity");
    for(i=0; i< CPU_SETSIZE; ++i){
        int cpu = CPU_ISSET(i, &set);
        printf("cpu=%i is %s \n"
               ""
               "", i, cpu?"set": "unset");
    }
    return 0;
}

int processBindCpu() {
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(0, &set);
    CPU_CLR(1, &set);
    CPU_CLR(2, &set);
    CPU_CLR(3, &set);
    int ret = sched_setaffinity(0, sizeof(cpu_set_t), &set);
    if(ret == -1)
        perror("sched_setaffinity");
    for(int i = 0; i < CPU_SETSIZE; ++i){
        int cpu = CPU_ISSET(i, &set);
        printf("cpu=%i is %s\n", i, cpu?"set":"unset");
    }



    return 0;
}

int getProcessScheduler() {
    int policy;
    policy = sched_getscheduler(0);

    switch (policy){
        case SCHED_OTHER:
            printf("Policy is normal\n");
            break;
        case SCHED_RR:
            printf("Policy is round_robin\n");
            break;
        case SCHED_FIFO:
            printf("Policy is first-in, first-out\n");
            break;
        case -1:
            perror("sched_getscheduler");
            break;
        default:
            fprintf(stderr, "Unknown policy!\n");
    }

    return 0;
}

int main(int argc, char*argv[])
{
    getProcessScheduler();
    return 0;
}
