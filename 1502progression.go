func canMakeArithmeticProgression(arr []int) bool {
    sort.Ints(arr)
    prev, diff := 0, arr[0] - arr[1]
    for i, val := range arr {
        if i!=0 && prev - val != diff {
            return false
        }
        prev = val
    }
    return true
}
