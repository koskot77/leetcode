#https://leetcode.com/problems/reverse-vowels-of-a-string/
#https://discuss.leetcode.com/topic/68637/a-python-3-liners-solution
def reverseVowels( s):
        """
        :type s: str
        :rtype: str
        """
        vowels = set(['a','e','i','o','u','y','A','E','I','O','U','Y'])
        pool = [ i for i in s if i in vowels ]
        return "".join( [ i if i not in vowels else pool.pop() for i in s ] )

print reverseVowels("leetcode")
