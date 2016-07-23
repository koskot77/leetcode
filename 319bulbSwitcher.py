class Solution(object):
    def bulbSwitchSlow(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0 : return 0

        bulbs = [1]*n
        for i in range(2,n+1) :
            for pos in range(i,n+1,i) :
                bulbs[pos-1] = 0 if bulbs[pos-1] else 1

        return reduce( lambda x,y: x+y, bulbs )


    def bulbSwitch(self, n):
        return int(sqrt(n))

s = Solution()

print s.bulbSwitch(999999)
