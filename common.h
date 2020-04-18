#include <vector>
using namespace std;

// int fun(vector<int> v);

// template <typename T>
template <typename T>
class Solution{
    public:
         Solution(){};
         int mySqrt(int x);
         vector<int> numInput;
         vector<int> numOutPut;
         void setTestCase();
         void checkCase();
};

template class Solution<int>;

template <typename T>
void compare(int id, T result, T expect);


// template <typename T>
// class my{
//     public:
//         void man();
// };
