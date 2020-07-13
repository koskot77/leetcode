# https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/submissions/
class Solution(object):
    def isPrefixOfWord(self, sentence, searchWord):
        """
        :type sentence: str
        :type searchWord: str
        :rtype: int
        """
        if sentence[0:len(searchWord)] == searchWord: return 1
        match = sentence.find(' ' + searchWord)
        if match < 0: return -1
        cnt = 1
        for i in range(match+1):
            if sentence[i] == ' ':
                cnt += 1
        return cnt
