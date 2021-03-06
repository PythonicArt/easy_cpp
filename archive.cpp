#include <cstdlib>
#include <iostream>
#include <stack>

#include "common.h"

using namespace std;

template <typename T>
bool Solution<T>::canReach(vector<int>& arr, int start) {
    // int n = arr.size();
    // if(start<0 && start >= n) return false;
    // if(arr[start] == 0) return true;
    // int left = start - arr[start];
    // int right = start + arr[start];
    // return canReach(arr, left) || canReach(arr, right);
    //
    int n = arr.size();
    std::stack<int> s;
    s.push(start);
    std::vector<bool> sign(n, false);
    while(!s.empty()){
        int t = s.top();
        s.pop();
        if(arr[t] == 0) return true;
        int left = t - arr[t];
        int right = t + arr[t];
        //
        if(right>=0 && right < n && sign[right]!=true) {
            s.push(right);
            sign[right]=true;
        }
        if(left>=0 && left < n && sign[left]!=true) {
            s.push(left);
            sign[left]=true;
        }
    }
    return false;
}

template <typename T>
int Solution<T>::jump(vector<int>& nums){
    int n = nums.size();
    if(n<=1) return 0;
    int minReach = 0;
    int maxReach = nums[0];
    int step = 1;
    if(maxReach>=n-1) return step;
    int t = maxReach;
    while(step < n){
        for (int i = minReach + 1; i <= maxReach; i++) {
            if(i + nums[i] >= t){
                // 更新最远位置
                t = i + nums[i];
            }
            if(t >= n-1) return ++step;
        }
        if(t > maxReach){
            // 下一轮从 [maxReach+1, t] 内判断
            minReach = maxReach;
            maxReach = t;
            step++;
        }
        else
        // 无法跳跃当前范围, 终点不可达--
            return 0;
    }
    return 0;
}

template <typename T>
bool Solution<T>::canJump(vector<int>& nums){
    int n = nums.size();
    vector<int> f(n);
    f[0] = 0;
    for (int i = 1; i < n; i++) {
        if(f[i-1] < 0) return false;
        f[i] = max(f[i-1], nums[i-1]) - 1;
    }
    return f[n-1] >= 0;
}

template <typename T>
int Solution<T>::mySqrt(int x) {
    int a = 1;
    int b = x/2;
    int last;
    if(x < 2) return x;
    while(a <= b){
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
