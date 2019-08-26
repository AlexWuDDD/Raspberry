#include <iostream>
#include "worker.h"
#include "ev.h"


void watcher_action (struct ev_loop *loop ,struct ev_io *w, int revents) {
    void *user_data = ev_userdata(loop);
    int sock= *(int*) user_data;
    char *buf = NULL;
    int bytes = nn_recv(sock, &buf, NN_MSG, NN_DONTWAIT);
    if (bytes <= 0) {
        return;
    }
    printf("RECEIVED : %s\n", buf);
    nn_freemsg(buf);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int sock = nn_socket(AF_SP, NN_PULL);
    if(sock < 0){
        printf("nn_socket failed - %d - %s\n", nn_errno(), nn_strerror(nn_errno()));
        return -1;
    }
    else {
        int rv = nn_bind(sock, inprocAddr.c_str());
        if (rv < 0) {
            printf("nn_connect failed - %d - %s\n", nn_errno(), nn_strerror(nn_errno()));
            return -1;
        }

        struct ev_loop *loop = ev_loop_new(EVBACKEND_EPOLL);
        if (nullptr == loop) {
            printf("create loop failed\r\n");
            return -1;
        }

        pthread_t worker1t;
        pthread_t worker2t;

        int ret1 = pthread_create(&worker1t, NULL, worker1, NULL);
        int ret2 = pthread_create(&worker2t, NULL, worker2, NULL);

        int fd;
        size_t sz = sizeof(fd);

        if (nn_getsockopt(sock, NN_SOL_SOCKET, NN_RCVFD, &fd, &sz) < 0) {
            perror("nn_getsocket");
            return -1;
        }

        //传参
        ev_set_userdata(loop, &sock);


        ev_io watcher;
        ev_io_init(&watcher,watcher_action,fd,EV_READ);
        ev_io_start(loop, &watcher);


        ev_run(loop, 0);


        pthread_cancel(worker1t);
        pthread_cancel(worker2t);


        pthread_join(worker1t, nullptr);
        pthread_join(worker2t, nullptr);


        nn_shutdown(sock, 0);
        nn_close(sock);
    }






    return 0;
}