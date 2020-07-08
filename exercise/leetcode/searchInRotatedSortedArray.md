Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

```cpp
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        return find(nums, target, 0, size - 1);
    }

    int find(vector<int>& nums, int target, int low, int high){
        if(low > high) return -1;
        int mid = (low + high)/2;
        if(nums[mid] == target) return mid;

        if(nums[low] < nums[mid]){
            if(nums[low]<=target && nums[mid] > target){
                return find(nums, target, low, mid - 1);
            }
            return find(nums, target, mid + 1, high);
        }

        if(nums[mid] < nums[high]){
            if(nums[mid]<target && nums[high] >= target){
                return find(nums, target, mid + 1, high);
            }
            return find(nums, target, low, mid - 1);
        }

        if(mid == low) return find(nums, target, mid + 1, high);

        return -1;
    }

```

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?


```cpp
bool search(vector<int>& nums, int target) {
        int size = nums.size();
        return find(nums, target, 0, size - 1);
    }

bool find(vector<int>& nums, int target, int low, int high){
    if(low > high) return false;
    int mid = low + (high - low)/2;
    if(nums[mid] == target) return true;

    if(nums[low] < nums[mid]){
        if(nums[low]<=target && nums[mid] > target){
            return find(nums, target, low, mid - 1);
        }
        return find(nums, target, mid + 1, high);
    }
    else if(nums[low] > nums[mid]){
        if(nums[mid]<target && nums[high] >= target){
            return find(nums, target, mid + 1, high);
        }
        return find(nums, target, low, mid - 1);
    }
    else{
        return find(nums, target, low+1, high);
    } // 有点纠结这个条件， 只能low+1往下一步看， 其他都规避不了

}
```
