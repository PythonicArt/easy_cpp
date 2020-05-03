#include <cstdlib>
#include <iostream>
#include <stack>
#include <map>

#include "common.h"

using namespace std;

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

// 优先安排测试数据

int longestConsecutive(vector<int>& nums) {
    map<int, int> Signed;
    int longest = 0;
    for(int i:nums){
        if(Signed.find(i) != Signed.end()) continue;
        int RightAtMost = i;
        int LeftAtMost = i;
        int big = i+1;
        int small = i-1;
        Signed[i] = 1;
        if(Signed.find(big) != Signed.end() && Signed.find(small) != Signed.end()){
            Signed[i] += Signed[big] + Signed[small];
            RightAtMost = i + Signed[big];
            Signed[RightAtMost] = Signed[i];
            LeftAtMost = i - Signed[small];
            Signed[LeftAtMost] = Signed[i];
        }
        else if(Signed.find(big) != Signed.end()){
            Signed[i] += Signed[big];
            RightAtMost = i + Signed[big];
            Signed[RightAtMost] = Signed[i];
        }
        else if(Signed.find(small) != Signed.end()){
            Signed[i] += Signed[small];
            LeftAtMost = i - Signed[small];
            Signed[LeftAtMost] = Signed[i];
        }
        if(Signed[i] > longest) longest = Signed[i];
    }
    return longest;
}

template <typename T>
void Solution<T>::checkCase(){
    // int size1 = this -> numInput.size();
    // int size2 = this -> numOutPut.size();
    vector<int> a1 = {100, 4, 200, 1, 3, 2};
    vector<int> b1 = {5};

    vector<int> a2 = {1, 2, 3, 4};
    vector<int> b2 = {5, 6};

    vector<int> a3 = {1, 3};
    vector<int> b3 = {2};

    vector<int> a4 = {1, 2};
    vector<int> b4 = {3, 4};

    vector<vector<int> > a = {a1, a2, a3, a4};
    vector<vector<int> > b = {b1, b2, b3, b4};

    vector<int> expects = {4, 4, 1, 2};

    int size1 = a.size();
    int size2 = b.size();
    if ( size1 != size2) {
        printf("case case size unmatch!!! size %d size %d \n", size1, size2);
    }
    else{
        for (int i = 0; i < size1; i++) {
            int result = longestConsecutive(a[i]);
            int expect = expects[i];
            compare(i+1, result, expect);
        }
    }
}
