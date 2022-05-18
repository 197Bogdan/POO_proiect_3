#pragma once
#include <vector>


template <class T>
class HeapFactory{

public:
    static HeapFactory<T>* getInstance(){
        if(!singleton_ptr)
            singleton_ptr = new HeapFactory<T>;
        return singleton_ptr;

    }

    Heap<T>* createHeap(std::string type, std::vector<T> v = {}) {
        if(type == "max")
            return new HeapMax<T>(v);
        else if(type == "min")
            return new HeapMin<T>(v);
        return nullptr;     // invalid type

    }

private:
    HeapFactory(){};

    static HeapFactory<T>* singleton_ptr;

};

template <class T>
HeapFactory<T>* HeapFactory<T>::singleton_ptr = nullptr;
