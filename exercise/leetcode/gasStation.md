gas数组表示 每个站点 能够加的油量

cost 标书 每个站点到下一个站点需要消耗的油量


计算left  表示以0油量从每个站点出发， 在该站点加油后 到下一个站点所剩余的油量


```cpp

int start = 0
int sum = 0
int total = 0
for (size_t i = 0; i < left.size(); i++) {
        total += left[i];
        sum += left[i];
        if(sum < 0 ){
            start = i
            sum = 0
        }
}

if(total < 0) return - 1
return i+1

```
