# https://leetcode.com/problems/count-good-nodes-in-binary-tree/submissions/
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def helper(self, node, maximum):
        n_good = 0 # error #1: think what you are going to return upfront

        if node.val >= maximum:
            n_good = 1
            maximum = node.val

        # error #2 don't make it more complicated with checking for leaf
        if node.left != None:
            n_good += self.helper(node.left,maximum)

        if node.right != None:
            n_good += self.helper(node.right,maximum)
            
        return n_good

    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.helper(root,-1000000)
