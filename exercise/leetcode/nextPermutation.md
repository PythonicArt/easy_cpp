

先找到 最后一个 相邻递增 的两个元素。 
xx a b c1 c2 c3

如果找到了
则 需要与a掉换的元素为 min(b, c1, c2, c3)

调换之后再把后面的所有元素排序即可

如果没有找到
    则全部排序。

void nextPermutation(vector<int>& nums) {
    int last = -1;

    for (int i = nums.size() - 1; i > 0; --i)
    {
        if(nums[i-1] < nums[i]){
            last = i-1;
            break;
        }
    }

    
    if(last >= 0){
        int idx = last + 1;
        for (int i = idx + 1; i < nums.size(); ++i)
        {
            if(nums[i]>nums[last] && nums[i]<nums[idx])
                idx = i;
        }
        swap(nums[last], nums[idx]);
        sort(nums.begin() + last + 1, nums.end());
    }
    else{
        sort(nums.begin(), nums.end());
    }
        
}


一种优化的思路， 从后往前找递增的数。
xx a b c1 c2 c3
这里 a<b > c1 > c2 > c3

第二步 从右往左找 第一个小于 a 的值。和a 交换
c2 < b > c1 > c2 > c3
此时 c2后面的数是递减区间， 只要反转即可而无需排序。

时间效率 提升 50%

void nextPermutation(vector<int>& nums) {
    int last = -1;

    for (int i = nums.size() - 1; i > 0; --i)
    {
        if(nums[i-1] < nums[i]){
            last = i-1;
            break;
        }
    }

    
    if(last >= 0){
        int idx = nums.size() -1;
        for (int i = idx; i > last; --i)
        {
            if(nums[i]>nums[last]){
                idx = i;
                break;
            }
        }

        swap(nums[last], nums[idx]);
        reverse(nums.begin() + last + 1, nums.end());
    }
    else{
        reverse(nums.begin(), nums.end());
    }
        
}