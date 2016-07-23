class Solution(object):
    seq = []

    def recure(self,pos):

        if pos+2 >= len(self.seq):
            return -1

        if self.seq[pos] == '#':
            return -1

        if self.seq[pos+1] == '#' and self.seq[pos+2] == '#':
            return pos+3

        if self.seq[pos+1] == '#' and self.seq[pos+2] != '#':
            return self.recure(pos+2)

        child2 = self.recure(pos+1)
        if child2 < 0 or child2 >= len(self.seq):
            return -1
        if self.seq[child2] == '#':
            return child2 + 1

        return self.recure(child2)

    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """

        if len(preorder) == 1 and preorder[0] == '#':
            return True

        self.seq = preorder.split(",")
        return True if self.recure(0) >= len(self.seq) else False

s = Solution() 

print s.isValidSerialization("#,#,#")
