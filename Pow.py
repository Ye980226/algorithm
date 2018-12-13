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
                return self.myPow(x, n // 2) ** 2
            else:
                return self.myPow(x, n//2)**2*x**(-signal)


print(Solution().myPow(0.00001, 2147483647))
