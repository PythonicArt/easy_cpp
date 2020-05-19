4sum
给定 target 和 sum
从一个列表中， 找到4个数字组合， 这四个数字的和为 target

1. 夹逼的方式
2. 根据两个数的和 构建 map， key 为 sum, value 为 和为 key的两个数的元组集合
	依次选取两个数 nums[a], nums[b] ， 其和为 s1, s2 = target - s1, 用 s2查表
		如果不存在， 则跳过
		如果存在， 则判断  a b c d 是否是否重叠， map可以存储下标. 保证 a < b < c < d

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
			k--;
	}
}





```
