//https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
// general error : no grasp on details
func rangeSum(nums []int, n int, left int, right int) int {
    var sums [][]int = make([][]int, n);
    for i,_ := range sums {
        sums[i] = make([]int, n)
    }
    sums[0][0] = nums[0]
    for i:=1; i<n; i++ {
        sums[0][i] = sums[0][i-1] + nums[i]
    }
    for i:=0; i<n; i++ {
        for j:=1; j<n; j++ {
            if j <= i {
                sums[j][i] = sums[j-1][i] - nums[j-1]
            }
        }
    }
    var flat = make([]int, n*(n+1)/2)
    k := 0
    for i:=0; i<n; i++ {
        for j:=0; j<n; j++ {
            if j <= i {
                flat[k] = sums[j][i]
                k++
            }
        }
    }
    sort.Ints(flat)
    var retval int = 0
    for i:=left-1; i<right; i++ {
        retval += flat[i] % 1000000007
    }
    return retval % 1000000007
}
