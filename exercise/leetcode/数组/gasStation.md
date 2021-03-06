# [Gas Station](https://leetcode.com/problems/gas-station/)

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

Note:

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.

```cpp
Example 1:

Input:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input:
gas  = [2,3,4]
cost = [3,4,3]

Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

```

# 思路
gas数组表示 每个站点 能够加的油量
cost 标书 每个站点到下一个站点需要消耗的油量
计算left  表示以0油量从每个站点出发， 在该站点加油后 到下一个站点所剩余的油量

```cpp
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = 0
    int sum = 0
    int total = 0
    for (int i = 0; i < left.size(); i++) {
        total += gas[i] - cost[i];
        sum += gas[i] - cost[i];
        if(sum < 0 ){
            start = i
            sum = 0
        }
    }
    if(total < 0) return - 1
    return i+1
}
```


变量 start 作为备选的起始点
left 作为当前点剩下的油量
使用 accLeft  代表 以备选起始点出发， 到当前点剩下的油量

使用sum 代表以0点出发到当前点剩下的油量

accLeft < 0 当前点以及之前的所有点都不能做起始点， 下一个备选的起始点为 i+1

每次更新一次备选的起始点，accLeft置0


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    if(n<0) return -1;

    int accLeft = 0;
    int start = 0;

    for (int i = 0; i < n; ++i)
    {
        int left = gas[i] - cost[i];
        accLeft += left;

        if(accLeft < 0){
            start++; // error1: start = i+1;
            //error2: 每次更新一次备选的起始点， 累积剩余值需要重新计算 accLeft=0;
        }
    }

    return accLeft >= 0?start:-1; // error3: 不能通过某个起始点的累积剩余值来判断， 而应该是数组全部的累积剩余值之和。
        
}

ac的版本

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    if(n<0) return -1;

    int accLeft = 0;
    int start = 0;
    int sum = 0;

    for (int i = 0; i < n; ++i)
    {
        int left = gas[i] - cost[i];
        sum += left;
        accLeft += left;

        if(accLeft < 0){
            start = i+1;
            accLeft = 0;
        }
    }

    return sum >= 0?start:-1;
        
}