Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.

设置两个标记 i, j, i为整理后的数组的最后一个元素的下标， j为探测的下标。
直接撸

```cpp
int removeDuplicates(vector<int>& nums) {
    int count = nums.size();
    int i = 0, j = 1;
    while(j < count){
        if(nums[i] == nums[j]){
            j++;
        }
        else{
            nums[++i] = nums[j++];
        }
    }
    return count==0?0:i+1;
}

```

Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.

```cpp
int removeDuplicates(vector<int>& nums) {
    int count = nums.size();
    int i = 0, j = 1;
    int n = 1;
    while(j < count){
        if(nums[i] == nums[j]){
            if(n == 1){
                // i++; 这里不能等待出现不同的元素才开始复制, 有可能最后一个元素与当前元素相等， 而且n=1的情况， 此时就会漏掉复制
                nums[++i] = nums[j++];
                n++;
            }
            else
                j++;
        }
        else{
            nums[++i] = nums[j++];
            n=1;
        }
    }
    return count==0?0:i+1;
}

```
