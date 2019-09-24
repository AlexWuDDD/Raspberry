//
// Created by wkjwo on 9/24/2019.
//

#ifndef SOMETEST_LINKLIST_H
#define SOMETEST_LINKLIST_H

struct Node{
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
    int data;
    Node *next;
};

class linklist {
public:
    linklist();
    ~linklist();
    void insertNode(int data, int index);
    void deleteNode(int index);
    Node* getNode(int index);
    void output();

private:
    Node* head; //头节点
    Node* last; //尾节点
    int size; //链表的实际长度
};


#endif //SOMETEST_LINKLIST_H
