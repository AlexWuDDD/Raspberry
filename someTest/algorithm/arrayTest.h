//
// Created by wkjwo on 9/23/2019.
//

#ifndef SOMETEST_ARRAYTEST_H
#define SOMETEST_ARRAYTEST_H

class arrayTest
{
public:
    arrayTest(int capacity);
    ~arrayTest();

    /**
     * 数组插入元素
     * @param element 插入的元素
     * @param index 插入的位置
     */
    void insert(int element, int index);
    void output();
    void resize();

    /**
     * 数组删除元素
     * @param index 删除的位置
     */
     int deleteElement(int index);

private:
    int *array;
    int size; //实际元素的数量
    int capacity; //数组的容量
};




#endif //SOMETEST_ARRAYTEST_H
