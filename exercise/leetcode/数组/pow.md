求 pow(x, n)

```cpp
class Solution{
    public:
        double pow(double x, int n){
            // if(n<0) return 1.0 / pow(x, -n); // 注意这里不能直接取负号,
            if(n==0) return 1;
            if(n==-1) return 1/x;
            double a = pow(x, n/2);
            double b = pow(x, n%2);
            return a*a*b;
        }
};
```


c++ int 型是有符号的， 即最高位是符号位。 其能够表达的数据范围是
-2^31 -> 2^32-1。 上述如果直接取负号， 最小的负整数取负号后会造成越界
