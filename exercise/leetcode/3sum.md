Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]


```cpp
vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> result;
    if(nums.size() < 3) return result;

    sort(nums.begin(), nums.end());

    for(int i = 0;i < nums.size()-2;i++){
        if(i> 0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = nums.size() - 1;
        while(j<k){
            int tsum = nums[i] + nums[j] + nums[k];
            if(tsum == 0){
                result.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while(j<k && nums[j] == nums[j-1]) j++;
                while(j<k && nums[k] == nums[k+1]) k--;
            }
            else if(tsum > 0){
                k--;
                while(j<k && nums[k] == nums[k+1]) k--;
            }
            else if(tsum < 0){
                j++;
                while(j<k && nums[j] == nums[j-1]) j++;
            }

        }    
    }

    // 需要考虑元素重复的情况, 有两种方式， 一个是判断相邻元素是否相同， 另一个是在最后执行去重操作

    //sort(result.begin(), result.end());
    //result.resize( distance(result.begin(),unique(result.begin(), result.end())));
    return result;
}

```
