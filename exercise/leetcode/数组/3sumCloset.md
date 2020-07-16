# [3sum-closest](https://leetcode.com/problems/3sum-closest/)

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

# 思路

3Sum的一个简单版本， 记录一个最接近的值, 扫描一遍即可求解

优化
考虑可以跳过的情况
i, j, k

测试结果， 方法一 272ms, 方法二 16ms, 优化力度明显

```cpp
 int threeSumClosest(vector<int>& nums, int target) {
     sort(nums.begin(), nums.end());
     int size = nums.size();
     int closet = 3001;
     for (auto i = 0; i < size - 2; i++) {
         for(auto j = i+1; j< size -1;j++){
             for(auto k = j+1; k<size;k++){
                 auto sum = nums[i] + nums[j] + nums[k];
                 auto left = abs(target - sum);
                 if(left == 0) return target;
                 if(left < abs(target - closet)){
                     closet = sum;
                 }
             }
         }
     }
     return closet;
}

 int threeSumClosest(vector<int>& nums, int target) {
     sort(nums.begin(), nums.end());
     int size = nums.size();
     int closet = 3001;
     int lastLeft = closet;
     for (auto i = 0; i < size - 2; i++) {
         auto j = i+1;
         auto k = size -1;
         while(j<k){
             auto sum = nums[i] + nums[j] + nums[k];
             auto left = abs(target - sum);
             if(left == 0) return sum;
             if(left < lastLeft){
                 closet = sum;
                 lastLeft = left;
             }
             if(sum < target){
                 j++;
             }
             else{
                 k--;
             }
     }
     return closet;
 }
}

```
