import math
import bisect

class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        stream = [0]*len(primes)

        result = [100000000000000]*n
        result[0] = 1

        for i in range(1,n) :
            minVal  = 1000000000000000
            minNext = -1
            for k in range(len(primes)) :
                candidate = result[ stream[k] ] * primes[k]
                if  minVal  > candidate :
                    minVal  = candidate
                    minNext = k

            for k in range(len(primes)) :
                if result[ stream[k] ] * primes[k] == minVal :
                    stream[k]  = stream[k] + 1

            result[ i ] = minVal

        return result[n-1]

s = Solution()

print s.nthSuperUglyNumber(100000,[7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251])
#print s.nthSuperUglyNumber(12,[2, 7, 13, 19])
#print s.nthSuperUglyNumber(2,[2, 3, 5])
