// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

#define swap(a, b) int _formacro_tmp = (a); (a) = (b); (b) = _formacro_tmp;
// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
    vdata.push_back(value);
    int i=vdata.size()-1, ip, tmp;
    while(i!=0){
        ip=(i-1)/2;
        if(vdata[ip]<=vdata[i]) break;
        swap(vdata[i], vdata[ip]);
        i=ip;
    }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
    if(empty()) return;
    vdata.front()=vdata.back();
    vdata.pop_back();
    int i=0, il, ir, imin;
    while(1){
        il=2*i+1;
        ir=il+1;
        imin=i;
        if(il<vdata.size()&&vdata[il]<vdata[imin]) imin=il;
        if(ir<vdata.size()&&vdata[ir]<vdata[imin]) imin=ir;
        if(imin==i) break;
        if(imin==il){
            swap(vdata[i], vdata[il]);
            i=il;
        }
        if(imin==ir){
            swap(vdata[i], vdata[ir]);
            i=ir;
        }
    }
}

// Returns the minimum element in the heap
int Heap::top(){
    if(empty()) return -1;
    return vdata.front();
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
    return vdata.empty();
}
    