//
// Created by wkjwo on 9/23/2019.
//
#include <cstdio>
#include "arrayTest.h"

arrayTest::arrayTest(int capacity) {
    this->array = new int[capacity];
    this->size = 0;
    this->capacity = capacity;
}

arrayTest::~arrayTest() {
    delete []array;
}

void arrayTest::insert(int element, int index) {
    if(index <0 || index > size){
        fprintf(stderr, "index: %d is out of range", index);
        return;
    }

    if(size >= capacity){
        resize();
    }

    //从右向左循环，将元素逐个向右移一个位置
    for(int i = size - 1; i >= index; i--){
        array[i+1] = array[i];
    }
    array[index] = element;
    ++size;
}

void arrayTest::output() {
    for(int i = 0; i< size; ++i){
        printf("%d\n", array[i]);
    }
}

void arrayTest::resize() {
    int * tmp = array;
    array = new int(capacity*2);
    this->capacity *= 2;
    for(int i =0; i < size; ++i){
        array[i] = tmp[i];
    }
    delete [] tmp;
}

int arrayTest::deleteElement(int index) {
    if(index <0 || index >= size){
        fprintf(stderr, "index: %d is out of range", index);
        return -1;
    }

    int deletedElemnt = array[index];
    //从左向右循环，将元素逐个向左挪一位
    for(int i = index; i < size-1; ++i){
        array[i] = array[i+1];
    }
    --size;
    return deletedElemnt;
}
