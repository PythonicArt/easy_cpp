#include <vector>
using namespace std;

// int fun(vector<int> v);

// template <typename T>
template <typename T>
class Solution{
    public:
         Solution(){};
         int mySqrt(int x);
         bool canJump(vector<int>& nums);
         int jump(vector<int>& nums);
         bool canReach(vector<int>& arr, int start);
         double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
         //
         // void setTestCase();
         void checkCase();
    private:
        vector<vector<int> > vectorInput;
        vector<int> numInput;
        vector<int> numOutPut;
        vector<bool> boolOutPut;
};

template class Solution<int>;

template <typename T>
void compare(int id, T result, T expect);
