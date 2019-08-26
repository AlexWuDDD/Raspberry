//
// Created by wkjwo on 8/26/2019.
//

#ifndef LIBEVANDNANOMSG_WORKER_H
#define LIBEVANDNANOMSG_WORKER_H
#include <pthread.h>
#include "nanomsg/nn.h"
#include "nanomsg/pipeline.h"
#include <string>
#include <unistd.h>
#include <iostream>

const std::string inprocAddr = "inproc:///tmp/test.ipc";
void *worker1(void* args);
void *worker2(void* args);



#endif //LIBEVANDNANOMSG_WORKER_H
