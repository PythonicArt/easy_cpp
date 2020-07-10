4sum
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

给定 target 和 sum
从一个列表中， 找到4个数字组合， 这四个数字的和为 target

1. 夹逼的方式
2. 根据两个数的和 构建 map， key 为 sum, value 为 和为 key的两个数的元组集合
	依次选取两个数 nums[a], nums[b] ， 其和为 s1, s2 = target - s1, 用 s2查表
		如果不存在， 则跳过
		如果存在, 则判断  a b c d 是否是否重叠, map可以存储下标. 保证 a < b < c < d

3. 存储结构同2， 使用 multi_map, 将结果进行组合
	遍历到 s1, s2=target - s1, 使用 s2 查表，对得到的结果进行判断
		(a, b) (c, d)
		a!=c a!=d b!=c b!=d 即可加入结果

去重的方法
unique(start, end)  这个方法 返回去重后的列表的重复元素开始的位置迭代器， 从这里到原列表结束都删除即可
erase(unique(start, end), end)

```cpp
for i, elem in nums:
	diff = target - elem
	if(elem in maps){
		j = maps[elem];
		result.push_back(j+1)
		result.push_back(i+1)
	}else{
		maps[elem]=i
	}
return result;


sort(nums)
for(i = 0;i<size-2;i++){
	if(a[i] == a[i+1]) continue;
	j = i + 1;
	for(k = size - 1; k>j;){
		t = sum(nums, i, j, k)
		t == target:
			result.push_back(i, j, k);
			k--;j++; // 需要先执行一遍再接着下面的循环判断
			while(k>j and a[k-1] == a[k]) k--;
			while(j<k and a[j+1] == a[j]) j++;
		t > target:
			k--;
			while(k>j and a[k-1] == a[k]) k--;
		t < target:
			j++;
			while(j<k and a[j+1] == a[j]) j++;
	}
}

sort(nums)
minDiff = 999999999;
for(i = 0;i<size-2;i++){
	if(a[i] == a[i+1]) continue;
	j = i + 1;
	for(k = size - 1; k>j;){
		t = sum(nums, i, j, k)
		t == target:
			return target;
		else:
			diff = abs(t-target)
			diff < minDiff:
				minDiff = diff;
				result = t
            // 这里可以通过判断减少一些可选项
            t > target:
                k--;
            t < target:
                j++;
	}
}


nums
target
for i in [0, size-2]:
	for j in [i+1, size-1]:
		t = nums[i] + nums[j]
		t in maps:
			list = maps[t]
			list.push([i, j])
		else:
			maps[t]=[[i, j]]
for t, elemList in maps:
	s = target - t
	s in maps:
        elemList2 = maps[s]
        for elem1 in elemList1:
            for elem2 in elemList2:
                [a, b] = elem1
                [c, d] = elem2
                a != c and a!=d and b!=c and b!=d:
                tlist = sort([a, b, c, d])
                result.push(tlist)
去重result


```

使用map
```cpp

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {		
		vector<vector<int>> result;
		if(nums.size() < 4) return result;

		map<int, vector<vector<int>>> sumMap;

		map<int, vector<vector<int>>>::iterator it;
		vector<vector<int>>::iterator vit;

		for(int i = 0;i<nums.size()-1;i++){
			for(int j = i+1;j< nums.size();j++){
				int sum = nums[i] + nums[j];
				if(sumMap.find(sum)!=sumMap.end()){
					it = sumMap.find(sum);
					(it->second).push_back({i, j});
				}
				else{
					sumMap[sum] = {{i, j}};
				}
			}
		}

		for(int i = 0;i<nums.size()-1;i++){
			for(int j = i+1;j< nums.size();j++){
				int sumA = nums[i] + nums[j];
				int sumB = target - sumA;
				if(sumMap.find(sumB)!=sumMap.end()){
					it = sumMap.find(sumB);
					for(vit = (it->second).begin();vit!=(it->second).end();vit++){
						int k = (*vit)[0];
						int l = (*vit)[1];
						if(i!=k&&i!=l&&j!=k&&j!=l){
							vector<int> Temp = {nums[i], nums[j], nums[k], nums[l]};
							sort(Temp.begin(), Temp.end());
							result.push_back(Temp);
						}
					}
				}
			}
		}
		sort(result.begin(), result.end());
		result.resize( distance(result.begin(),unique(result.begin(), result.end())));
		return result;
    }
};

```


使用 multi_map
```cpp
vector<vector<int>> fourSum(vector<int>& nums, int target) {		
		vector<vector<int>> result;
		if(nums.size() < 4) return result;

		unordered_multimap<int, pair<int,int>> sumMap;


		for(int i = 0;i<nums.size()-1;i++){
			for(int j = i+1;j< nums.size();j++){
				int sum = nums[i] + nums[j];
				sumMap.insert(make_pair(sum, make_pair(i, j)));
			}
		}

		for(auto i = sumMap.begin();i!=sumMap.end();i++){
			int sumb = target - i->first;
			auto range = sumMap.equal_range(sumb);
			for(auto j = range.first;j!=range.second;j++){
				int a = i->second.first;
				int b = i->second.second;
				int c = j->second.first;
				int d = j->second.second;
				if(a!=c && a!=d && b!=c && b!=d){
					vector<int> Temp = {nums[a], nums[b], nums[c], nums[d]};
					sort(Temp.begin(), Temp.end());
					result.push_back(Temp);
				}							
			}				
		}

		sort(result.begin(), result.end());
		result.resize( distance(result.begin(),unique(result.begin(), result.end())));

		return result;
    }
```
