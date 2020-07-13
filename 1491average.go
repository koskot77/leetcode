func average(salary []int) float64 {
    var min_v, max_v, total int = 0,1000000,0
    for _,v := range salary {
        if min_v < v {
            min_v = v
        }
        if max_v > v {
            max_v = v
        }
        total += v
    }
    total -= min_v
    total -= max_v
    return float64(total)/float64(len(salary)-2)
}
