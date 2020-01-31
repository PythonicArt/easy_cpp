#include <iostream>
#include <vector>

using namespace std;

int fun(std::vector<int> v);

template <typename T>

void compare(int id, T result, T expect){
    if (result == expect) {
        printf("\033[32m case %d passed\n\033[0m", id);
    }
    else{
        printf("\033[31m case %d unpassed\n\033[0m", id);
        cout<< "result is " << result <<endl;
        cout<< "expect is " << expect <<endl;
        cout<<endl;
    }
}

int main(int argc, char const *argv[]) {
    // vector<std::vector<int> > aList = {
    //     {0,1,0,2,1,0,1,3,2,1,2,1}
    // };
    // vector<int> bList = {
    //     2
    // };
    // vector<int> rList = {
    //     6
    // };
    // int size1 = aList.size();
    // int size2 = rList.size();
    // if ( size1 != size2) {
    //     printf("\033[33mcase case size unmatch!!! size %d size %d \n\033[0m", size1, size2);
    // }
    // else{
    //     for (int i = 0; i < size1; i++) {
    //         int result = fun(aList[i]);
    //         int expect = rList[i];
    //         compare(i+1, result, expect);
    //     }
    // }
    // return 0;

}
