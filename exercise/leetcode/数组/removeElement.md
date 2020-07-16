```cpp
int removeElement(vector<int>& nums, int val) {
        int idx = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != val){
                nums[++idx] = nums[i];
            }
        }

        return idx+1;
}
```
