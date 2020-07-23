// https://leetcode.com/problems/number-of-substrings-with-only-1s/
// conceptual warning: sometimes it is easy than you think
func numSub(s string) int {
    // sum_l^n (n-l+1) = (n+1)*n - n*(n+1)/2 = n*(n+1)/2
    // the idea is to find all longest continuous substrings
    var sum int = 0
    for i,j := 0,0; j<len(s)+1; j++ {
        if s[i] == '1' && (j == len(s) || s[j] == '0') { // warn #1: n+1 edge case
            sum += ((j-i)*(j-i+1))/2 % 1000000007
            i=j
            continue
        }
        if s[i] == '0' && (j == len(s) || s[j] == '1') {
            i=j
        }
    }
    return sum % 1000000007
}
