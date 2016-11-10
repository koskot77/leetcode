# https://discuss.leetcode.com/topic/47200/dumb-and-fast-python-solution

class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        # Since there are only log(N) numbers that are powers of 4, and here we are limited by the 32(64) bits of basic integral type, just check them all:
        if num <0 :
            return False
        if num==0:
            return False
        if num==1:
            return True

        powers4 = set([1,4,16,64,256,1024,4096,16384,65536,0x40000,0x100000,0x400000,0x1000000,0x4000000,0x10000000,0x40000000])

        return num in powers4
