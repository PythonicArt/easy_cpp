#include <cstdlib>
#include <iostream>
/* This program inputs two numbers x and y and outputs their sum */

#include "common.h"

template <typename T>
void compare(int id, T result, T expect){
    if (result == expect) {
        printf("case %d passed\n\n", id);
    }
    else{
        printf("xxxxxxx-case %d unpassed\n", id);
        cout<< "result is " << result <<endl;
        cout<< "expect is " << expect << "\n" <<endl;
        cout<<endl;
    }
}

template <typename T>
void Solution<T>::checkCase(){
    int size1 = this -> numInput.size();
    int size2 = this -> numOutPut.size();
    if ( size1 != size2) {
        printf("case case size unmatch!!! size %d size %d \n", size1, size2);
    }
    else{
        for (int i = 0; i < size1; i++) {
            int result = this -> mySqrt(numInput[i]);
            int expect = numOutPut[i];
            compare(i+1, result, expect);
        }
    }
}

// 优先安排测试数据
template <typename T>
void Solution<T>::setTestCase() {
    vector<int> inputs = { 0, 4, 8 };
    vector<int> expects = { 0, 2, 2 };
    this -> numInput = inputs;
    this -> numOutPut = expects;
}

// 其次写代码
template <typename T>
int Solution<T>::mySqrt(int x) {
    int a = 1;
    int b = x/2;
    int last;
    if(x < 2) return x;
    while(a<=b){
        int mid = a + (b - a) / 2;
        if(x / mid > mid){
            a = mid + 1;
            last = mid;
        }
        else if(x / mid < mid){
            b = mid - 1;
        }
        else
        return mid;
    }
    return last;
}
