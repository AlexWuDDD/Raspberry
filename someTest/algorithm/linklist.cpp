//
// Created by wkjwo on 9/24/2019.
//

#include <cstdio>
#include "linklist.h"

linklist::linklist() {
    head = nullptr;
    last = nullptr;
    size = 0;
}

linklist::~linklist() {
    Node *node = head;
    while(node!= nullptr){
        Node * tmp = node;
        node = node->next;
        delete tmp;
    }
}

void linklist::insertNode(int data, int index) {
    if(index < 0 || index > size){
        printf("out of link list range");
        return;
    }
    Node *node = new Node(data);
    if(size == 0) {
        head = node;
        last = node;
    }
    else if(index == 0) {
       //插入头部
       node->next = head;
       head = node;
    }
    else if(index == size){
        //尾部插入
        last->next = node;
        last = node;
    }
    else{
        //插入中间
        Node *nodePrev = getNode(index - 1);
        node->next = nodePrev->next;
        nodePrev->next = node;
    }
    ++size;
}

void linklist::deleteNode(int index) {
    if(index<0 || index >= size){
        printf("out of link list range");
    }
    Node *node = nullptr;
    if(index == 0){
        //删除头节点
        node = head;
        head = head->next;
    }
    else if(index == size-1){
        //删除尾节点
        node = last;
        Node* prev = getNode(index-1);
        last = prev;
    }
    else{
        //删除中间节点
        Node* prevNode = getNode(index-1);
        node = prevNode->next;
        prevNode->next = node->next;
    }
    delete node;
}

Node *linklist::getNode(int index) {
    if(index < 0 || index >= size){
        printf("out of link list range");
    }
    Node* node = head;
    for(int i = 0; i < index; i++){
        node = node->next;
    }
    return node;
}

void linklist::output() {
    Node *node = head;
    while(nullptr != node ){
        printf("%d\n",node->data);
        node = node->next;
    }
}
