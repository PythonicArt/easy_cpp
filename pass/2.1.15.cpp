#include <iostream>
#include <vector>
// 这里要用std::min方法,需要引入
#include <algorithm>

using namespace std;

int count(int low, int high, vector<int> a){
    int height = min(a[low], a[high]);
    int width = high - low - 1;
    int all = height * width;
    for (int i = low + 1; i < high; i++) {
        all -= a[i];
    }
    return all;
}

int fun(std::vector<int> nums){
    int l, h;
    int index = 0, i, j;
    int sum = 0;
    int size = nums.size();
    while (index < size - 1) {
        if (nums[index] > nums[index+1]){
            i = index;
            // 当nums[i+1] > nums[i] 凹槽左边形成
            j = i + 1;
            while(j < size && nums[j] < nums[i]) j++;
            if(j >= size) return sum;
            // 当nums[j] >= nums[i] 凹槽右边形成
            l = i;
            h = j;
            int a1=count(l, h, nums);
            sum += a1;
        }
        index++;
    }
    return sum;
}
