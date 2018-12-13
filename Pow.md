#### Problem
Implement pow(x, n), which calculates x raised to the power n (xn).
#### answer

```python
import sys
sys.setrecursionlimit(2**31-1)


class Solution:

    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """

        if(n == 0):
            return 1
        elif(n == -1):
            return 1/x
        elif (n == 1):
            return x
        else:
            signal=n/abs(n)
            
            if (n % 2 == 0):
                result=self.myPow(x, n // 2)
                return  result*result
            else:
                result=self.myPow(x, (n-signal)//2)
                return result*result*x**(signal)
```

递归不断的压栈，不出栈，直到最终到了结束条件才返回，会占用很多内存空间，所以递归虽好，大型项目里也需要好好揣摩能不能使用。
一开始没有赋值给result，而是用self.myPow(x,n//2)*self.myPow(x,n-n//2)，当n很大时运行速度奇慢。
计算一下就可以发现这个算法的复杂度依然是O(n),而赋值之后算法复杂度变成了O(lgn),当n等于2的32次时，运行速度理论上，会减小到原来的 7.450580596923828e-09，就很快很快很快。
