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

https://www.cnblogs.com/grandyang/p/4741122.html
