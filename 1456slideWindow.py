#https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/submissions/
class Solution(object):
    def maxVowels(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        # sliding window of size k
        vowels = set(['a','e','i','o','u'])
        n_vow = 0
        for i in range(k):
            if s[i] in vowels:
                n_vow += 1

        max_n_vow = n_vow
        for i in range(len(s)-k):
            if s[i]   in vowels: n_vow -= 1
            if s[i+k] in vowels: n_vow += 1
            if max_n_vow < n_vow: max_n_vow = n_vow

        return max_n_vow
