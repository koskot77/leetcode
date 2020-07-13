// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
// conceptual error: do not overcomplicate by stiching simple, but untailered steps
func minSumOfLengths(arr []int, target int) int {
    // find all subarrays matching the target
    var shortest = make([]int, len(arr)+1)
    shortest[0] = len(arr)+1 // error #1: no need in array, two numbers would be fine
    var retval = shortest[0]
    for i, j, sum := 0, 0, 0; j != len(arr) || sum >= target; { // error #2: forgot sum=target
        if sum < target {
            sum += arr[j]
            j++ // error #3: be consistent about position of j = next to current
            shortest[j] = shortest[j-1] // error #4: it is always previous!
            continue
        }
        if sum > target {
            sum -= arr[i]
            i++
            continue
        }
        if sum == target {
            if j-i < shortest[j-1] { // error #4: it is always previous!
                shortest[j] = j-i
            } else {
                shortest[j] = shortest[j-1] // error #4: it is always previous!
            }
            if retval > j-i + shortest[i] {
                retval = j-i + shortest[i]
            }
            sum -= arr[i]
            i++
        }
    }

    if retval == len(arr)+1 {
        return -1
    }
    return retval
}
