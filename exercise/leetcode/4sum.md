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
