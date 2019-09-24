//
// Created by wkjwo on 9/23/2019.
//

#include <cstdio>
#include "test.h"

#include "arrayTest.h"
#include "linklist.h"


int testArray()
{
    arrayTest* myArray = new arrayTest(3);
    myArray->insert(3, 0);
    myArray->insert(7, 1);
    myArray->insert(9, 2);
    myArray->insert(5, 3);
    myArray->insert(6, 1);
    myArray->output();

    delete myArray;
    return 0;
}

int testLinkList() {
    linklist *myLinkList = new linklist();
    myLinkList->insertNode(0, 0);
    myLinkList->insertNode(1, 1);
    myLinkList->insertNode(2, 2),
    myLinkList->insertNode(3, 3);
    myLinkList->insertNode(4, 4);
    myLinkList->insertNode(5, 5);
    myLinkList->output();
    printf("**************************\n");
    myLinkList->deleteNode(0);
    myLinkList->deleteNode(4);
    myLinkList->deleteNode(1);
    myLinkList->output();



    delete myLinkList;


    return 0;
}
