# 快速排序的思想

一轮操作
    找一个哨兵值, 把小于哨兵值得元素都移动到左边， 大于哨兵值得元素都移动到右边去
    一轮结束后， 哨兵可以放到正确的位置上。

    哨兵将列表分割成两部分， 对每一部分重复上述步骤
    重复多轮， 直到遇到单元素的列表即可停止

需要多少轮
    轮次决定了运行效率

    最理想的
        每一次都放到中间的位置， 即形成一棵二叉树的形式
        那么二叉树的高度就是轮次 logn
        此时效率为 n*logn

    最不理想的
        每一次都放到第一个或是第二个位置， 即形成一个列表的形式
        列表的长度就是轮次， n
        n*n

# topK的思想

需要快速地找到列表中前k个元素
快速找到序列中 第k小的 元素

题目没有讲一个前提, 那就是前k个元素是否要有序

1. 可以先排序，然后取前k个元素. 效率为排序的效率, 最好为 n*logn
2. 参考快排的思想， 找一个哨兵值, 进行多轮的筛选
    可以看到， 每一轮都会有几个元素被找出来, 假如第一轮就找到, 那就ok
    如果没有找到，那就是缩小了范围， 继续找, 直到找到
    最理想的 O(n)

```cpp

    void quickSelect(vector<E>&S, int a, int b, int k, const C& less){
        if(a>=b) return
        //  取最后一个值， 也可以随机取  
        E piovt = S[b]
        int low = a
        int high = b-1
        while(low <= high){
            // 往右找到大于pivot的元素的下标low
            while(low <= high && !less(pivot, S[low]) ) low++;
            // 往右找到小于pivot的元素的下标high
            while(low <= high && !less(S[high], pivot)) high--;
            if(low < high)
                swap(S[low], s[high])
        }
        swap(S[low], s[b])
        int idx = low - a + 1;
        if (idx == k) {
            // 刚好是第k个
            return S[low]
        }
        else if(idx > k){
            // 个数大于k， 在前半部分找第k个
            return quickSelect(S, a, low - 1, k, less)
        }
        else{
            // 个数小于k， 在后半部分找第k - idx个
            newK = k - idx
            return quickSelect(S, low + 1, b, newK, less)
        }
    }

```


# 删减-选择模式
    根据一定的判断， 减少问题的规模
    比如 二分查找, 每次问题规模缩小一半
    寻找topk, 每次都可以去掉一部分不满足条件的元素
