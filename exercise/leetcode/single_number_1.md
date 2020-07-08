一组数， 只有一个数出现一次， 其余出现两次， 请找出这个数来

思路
    所有的数执行异或运算， 剩下的就是那个数

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

思路2
    使用三个辅助整数
        one 记录出现1次的那些位
        two 记录出现2次的那些位
        three 记录出现3次的那些位, 当出现三次以此清除掉该位的数据


        对于一个数num


        ```cpp
        int singleNumber(vector<int>& nums) {
            int one=0, two=0, three=0;
            int remove = 0;

            for(auto num:nums){
                two |= (one & num);
                one ^= num;
                three = (one & two);
                remove = ^three;
                one = (one & remove)
                two = (two & remove)
            }
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

diff从右往左第一个为1的位， 该位置对于A，B来说必定不相同， 以为diff是A，B异或的结果。所以得到区分

diff2&A != diff2&B, 而且结果不是1 就是0。

同时， 其他元素也可以做这样的区分， 即一部分的数字与diff相与的结果 是0， 一部分相与的结果是1. 于是代码可以这样写

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
