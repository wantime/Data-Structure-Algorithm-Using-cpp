//
// Created by wangyao on 2022/12/2.
//

#ifndef INC_02_HEAP_BASICS_MAXHEAP_H
#define INC_02_HEAP_BASICS_MAXHEAP_H

#include "Array.h"


template<class T>
class MaxHeap{
private:
    Array<T> *data;
    // 返回完全二叉树的数组表示中，一个索引所代表的左孩子节点的索引
    int leftChild(int index){
        return index*2+1;
    }
    // 返回完全二叉树的数组表示中，一个索引所代表的右孩子节点的索引
    int rightChild(int index){
        return index*2+2;
    }
    // 返回完全二叉树的数组表示中，一个索引代表的父亲节点的索引
    int parent(int index){
        return (index - 1) / 2;
    }
    void shiftUp(int k){
        while (k > 0 && data->get(parent(k)) < data->get(k)) {
            data->swap(k, parent(k));
            k = parent(k);
        }
    }
    void shiftDown(int k){
        while (leftChild(k) < data->getSize()) {

            int j = leftChild(k);
            if (j + 1 < data->getSize() && data->get(j) < data->get(j + 1))
                j = j + 1;

            if(data->get(k) > data->get(j))
                break;
            data->swap(k, j);
            k = j;
        }
    }
public:
    MaxHeap(int capacity) {
        data = new Array<T>(capacity);
    }
    MaxHeap(){
        data = new Array<T>();
    }

    MaxHeap(T arr[], int n){
        data = new Array<T>(arr, n);
        for(int i = parent(n-1); i >= 0; i--){
            shiftDown(i);
        }
    }
    int size(){
        return data->getSize();
    }
    int getCapacity(){
        return data->getCapacity();
    }
    bool isEmpty(){
        return data->isEmpty();
    }
    void add(T e){
        data->addLast(e);
        shiftUp(data->getSize() - 1);
    }
    T findMax() {
        return data->get(0);
    }
    T extractMax(){
        T ret = findMax();

        data->swap(0, data->getSize() - 1);
        data->removeLast();
        shiftDown(0);
        return ret;
    };

    T replace(T e){
        T ret = findMax();
        data->set(0, e);
        shiftDown(0);
        return ret;
    }
};


#endif //INC_02_HEAP_BASICS_MAXHEAP_H
