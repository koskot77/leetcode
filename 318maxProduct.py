class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """

        d = {'a':0x1, 'b':0x2, 'c':0x4, 'd':0x8, 'e':0x10, 'f':0x20, 'g':0x40, 'h':0x80, 'i':0x100, 'j':0x200, 'k':0x400, 'l':0x800, 'm':0x1000, 'n':0x2000, 'o':0x4000, 'p':0x8000, 'q':0x10000, 'r':0x20000, 's':0x40000, 't':0x80000, 'u':0x100000, 'v':0x200000, 'w':0x400000, 'x':0x800000, 'y':0x1000000, 'z':0x2000000 }

        summary = [ reduce( lambda x,y: x | y, map( lambda x: d[x], list(word) ) ) for word in words if len(word) > 0 ]

        length  = [ len(word) for word in words ]

        maxProduct = 0
        for i in range(0,len(summary)) : 
            for j in range(i+1, len(summary)) :
                if summary[i] & summary[j] == 0 and length[i] * length[j] > maxProduct :
                    maxProduct = length[i] * length[j]

        return maxProduct

s = Solution()

print s.maxProduct(["a", "aa", ""])
