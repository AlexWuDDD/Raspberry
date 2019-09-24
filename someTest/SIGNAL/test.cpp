//
// Created by wkjwo on 9/23/2019.
//

#include <cstdio>
#include <cstdlib>
#include <csignal>
#include "test.h"
#include <unistd.h>

void sigint_handler(int signo) {
/*
 * Technically, you shouldn't use printf() in a
 * signal handler, but it isn't the end of the
 * world. I'll discuss why in the section
 * "Reentrancy."
 */
    printf ("Caught SIGINT!\n");
    printf ("Caught %s\n", sys_siglist[signo]);
    exit (EXIT_SUCCESS);
}

void testSIGINT() {
    /*
    * Register sigint_handler as our signal handler
    * for SIGINT.
    */
    if(signal(SIGINT, sigint_handler) == SIG_ERR){
        fprintf(stderr, "Cannot handler SIGINT\n");
        exit(EXIT_FAILURE);
    }
    for(;;)
        pause();

}

