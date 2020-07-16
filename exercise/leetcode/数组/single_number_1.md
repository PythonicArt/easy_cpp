一组数， 只有一个数出现一次， 其余出现两次， 请找出这个数来

思路
    所有的数执行异或运算， 剩下的就是那个数

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        result ^= nums[i];
    }
    return result;
}

一组数， 只有一个数出现一次， 其余出现三次， 请找出这个数来

思路1
    辅助数组count, 记录每一位出现的次数。 最后模3取余, 最后得到的数就是那个数

    ```cpp
     int singleNumber(vector<int>& nums) {
         int size = sizeof(int);
         std::vector<int> count(size);
         int p, q;
         int r;
         for (int i = 0; i < size; i++) {
             p = 1<<i;
             for(auto num:nums){
                 q = num&p;
                 if (q == 1) {
                     count[i] = (++count[i]) % 3;
                     r |= conut[i] << i;
                 }
             }
         }
         return r;
    }

    ```
从右往左 第0位到第 sizeof(int)*8 位计算该位置1出现的数量

考虑一个位置i, 唯一的数在该位置的 位标记为 m， 而其他数在该位置的位标记 的数量都是以 3的倍数出现， 即 3*a1, 3*a0, a1代表出现1， a0代表出现0

所以，m = amountOfOne % 3 

int singleNumber(vector<int>& nums) {
    int result = 0; 

    for (int i = 0; i < sizeof(int)*8; ++i) // error1: 上限写成 sizeof(int) 想当然了
    {
        int amountOfOne = 0;
        for (int j = 0; j < nums.size(); ++j)
        {
            int r = 1 & (nums[j]>>i);
            if(r==1) amountOfOne++;
        }
        int m = amountOfOne % 3;
        result |= (m<<i);
    }
    return result;
}

思路2
    使用三个辅助整数
        one 二进制表示时， 某位为1，则代表1在 当前位出现1次
        two 二进制表示时， 某位为1，则代表1在 当前位出现2次

        three 同理， 记录出现三次的位。 当出现三次, 则在one, two中将该位清除掉，即重新计数。

        对于一个数num


        ```cpp
        int singleNumber(vector<int>& nums) {
            int one=0, two=0, three=0;
            int remove = 0;

            for(auto num:nums){
                three = num & two; // 先考虑出现三次的位
                two |= (one & num); // 在计算出现两次的位 
                one ^= num; // 最后剩下第一位
                remove = ^three;
                one = (one & remove)
                two = (two & remove)
            }

            return one;
        }

        ```

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
```cpp
Example:
Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
```
参考资料
https://www.cnblogs.com/grandyang/p/4741122.html

思路
考虑到除了两个元素A, B只出现一次， 其他元素都是成对出现的。 成对的元素异或的结果是0， 所以想办法将 A， B区分开再和成对的结果异或最后得到就就是 A, B。

一个区分的方法

先将全部元素异或得到 diff, 通过 diff2 = diff&(-diff), 该数字的只有一个位为1， 该位的意义为 diff从右往左第一个不为0的位
理论依据是， 负数是用补码的形式存储的， 而补码的计算为 反码+1，假设原码是这样的形式， xxxxx10000， 则补码就是 0000010000

diff从右往左第一个为1的位， 该位置对于A, B来说必定不相同， 以为diff是A, B异或的结果。所以得到区分

diff2&A != diff2&B, 而且结果不是1 就是0。

同时, 其他元素也可以做这样的区分, 即一部分的数字与diff相与的结果 是0, 一部分相与的结果是1. 
这样就分成了两个部分
A xx xx xx xx
B xx xx xx xx

集合中元素除了A， 都是成对出现的, 异或起来就剩下A, B

于是代码可以这样写

```cpp
 vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
		for(auto num:nums){
			diff ^= num;
		}
		diff &= -diff;
		vector<int> result(2);
		for(auto num:nums){
			if((num&diff) == 0){
				result[0]^=num;
			}
			else{
				result[1]^=num;
			}
		}
		return result;
    }
```
