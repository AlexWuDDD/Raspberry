//
// Created by wkjwo on 8/22/2019.
//
#include "event2/event.h"

int main()
{
    const char**methods = event_get_supported_methods();
    printf("Starting Libevent %s. Available methods are:\n",
            event_get_version());
    for(int i = 0; methods[i] != NULL; ++i){
        printf("    %s\n", methods[i]);
    }
}

