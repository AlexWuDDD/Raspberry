//
// Created by wkjwo on 9/16/2019.
//
#include <cstdio>
#include <unistd.h>
#include <cstdlib>

int main()
{
    int ret = link("alex.txt", "a.txt");
    if(ret){
        perror("unlink");
    }

    return 0;
}
