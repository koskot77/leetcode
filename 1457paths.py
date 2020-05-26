# https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/submissions/
# good: 1) broke it down to subproblems
#       2) figured bottom-up pattern
# errors: 1) python syntax
#         2) attention to details
#         3) over-complicated return argument
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def check(self, path):
        counts = {}
        for i in path:
            if i in counts:
                counts[i] += 1
            else:
                counts[i] = 1 # error #1: 1 not 0
                
        odd = 0
        for i,j in counts.iteritems():
            if (j%2)==1: odd += 1

        if (len(path)%2)==1 and odd == 1: return True
        if (len(path)%2)==0 and odd == 0: return True

        return False
                
    def helper(self, node, path):
        path += [node.val] # error #2: do it before not after anything

        if node.left==None and node.right==None:
            if self.check(path): return 1

        path_new = copy.deepcopy(path)

        count = 0 # error #3: no need to make it an argument

        if node.left != None:
            count = self.helper(node.left, path_new)

        path_new = path

        if node.right != None:
            count += self.helper(node.right, path_new)

        return count

    def pseudoPalindromicPaths (self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        path  = []
        return self.helper(root,path)
