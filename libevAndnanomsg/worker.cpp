//
// Created by wkjwo on 8/26/2019.
//

#include "worker.h"



void *worker1(void* args)
{
    int sock = nn_socket(AF_SP, NN_PUSH);
    if(sock < 0){
        printf("nn_socket failed - %d - %s\n", nn_errno(), nn_strerror(nn_errno()));
    }
    else {
        int rv = nn_connect(sock, inprocAddr.c_str());
        if (rv < 0) {
            printf("nn_connect failed - %d - %s\n", nn_errno(), nn_strerror(nn_errno()));
        }
        else {
            std::string msg = "I am worker1";

            for (int i = 0; i < 50; ++i) {
                int byte = nn_send(sock, msg.c_str(), msg.size(), 0);
                if (byte < 0) {
                    printf("nn_send failed - %d - %s\n", nn_errno(), nn_strerror(nn_errno()));
                    break;
                }
                std::cout << "worker1 sending No." << i << " msg!" << std::endl;
                sleep(1);
            }
        }
        nn_shutdown(sock, 0);
        nn_close(sock);
    }

    pthread_exit(nullptr);

}
void *worker2(void* args)
{
    int sock = nn_socket(AF_SP, NN_PUSH);
    if(sock < 0){
        printf("nn_socket failed - %d - %s\n", nn_errno(), nn_strerror(nn_errno()));
    }
    else {
        int rv = nn_connect(sock, inprocAddr.c_str());
        if (rv < 0) {
            printf("nn_connect failed - %d - %s\n", nn_errno(), nn_strerror(nn_errno()));
        }
        else {
            std::string msg = "I am worker2";

            for (int i = 0; i < 50; ++i) {
                int byte = nn_send(sock, msg.c_str(), msg.size(), 0);
                if (byte < 0) {
                    printf("nn_send failed - %d - %s\n", nn_errno(), nn_strerror(nn_errno()));
                    break;
                }
                std::cout << "worker2 sending No." << i << " msg!" << std::endl;
                sleep(1);
            }
        }
        nn_shutdown(sock, 0);
        nn_close(sock);
    }

    pthread_exit(nullptr);
}
