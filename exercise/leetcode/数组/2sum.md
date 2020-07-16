
# [Two Sum](https://leetcode.com/problems/two-sum/)

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].


```cpp

 vector<int> twoSum(vector<int>& nums, int target) {

	map<int, int> mark;
	vector<int> result;

	for(int i = 0; i< nums.size(); i++){
		mark[nums[i]] = i;
	}

	for(int i = 0; i< nums.size(); i++){
		int b = target - nums[i];
        // 这里需要判断 mark[b] != i 因为 元素不能重复利用
		if(mark.find(b)!=mark.end() && mark[b] != i){
			int idx = mark[b];
			result.push_back(i);
			result.push_back(idx);
			break;
		}
	}

	return result;
}

// 一个小的优化: 上面循环执行了两遍， 可以合并， 只执行一遍
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> mark;
    vector<int> result;

    for(int i = 0; i< nums.size(); i++){
        int b = target - nums[i];
        if(mark.find(b)!=mark.end() && mark[b] != i){
            int idx = mark[b];
            result.push_back(i);
            result.push_back(idx);
            break;
        }
        else{
            mark[nums[i]] = i;
        }
    }

    return result;
}

```
