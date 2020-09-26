// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/submissions/
// good point: drag the first greedy match out of the way as the objective gets weaker and weaker
// error #1: think big picture (e.g. recursion here) rather than rush to implement fiddly bookkeeping,
//           do not over optimize it prematurely
// error #2: it is a very simple concept to additionally track number of swaps for each row,
//           which is a subtle complication of over a plain count of adjacent swaps to drag row j to position i
func helper(trailing_zeros []int, moved []int, objective int) int {
    // end of recursion
    if objective == 0 {
        return 0
    }
    // count swaps
    var swaps int = -1 // will stay negative if no good row is found
    for row, v := range trailing_zeros {
        // fast forward if current row was already placed to its final destination sometime before
        if moved[row] < 0 {
            continue
        }
        // push down the row if it doesn't satisfy its objective, otherwise count swaps and move it out of the way
        if v < objective {
            moved[row]++ // a more lucky row from below would have to be dragged over this one
        } else {
            swaps = row + moved[row] - (len(moved)-1 - objective) // len(moved) == N
            moved[row] = -1 // used, not needed anymore
            break
        }
    }
    // no matching row was found?
    if swaps < 0 {
        return -1
    }
    var one_less int = helper(trailing_zeros, moved, objective-1)
    if one_less < 0 {
        return -1
    }
    return one_less + swaps
}


func minSwaps(grid [][]int) int {
    // size of the initial problem
    var N int = len(grid)
    // how many trailing zeros are in the row
    var trailing_zeros = make([]int, N)
    for row, vect := range grid {
        var cnt int = 0
        for col := N-1; col>=0 && vect[col]==0; col-- {
            cnt++
        }
        trailing_zeros[row] = cnt;
    }
    // bookkeeping for the rows:
    //  = 0 - stays at the current position
    //  = m - was pushed m positions down
    //  =-1 - is already used in a parent subproblem
    var moved = make([]int,N)

    return helper(trailing_zeros, moved, N-1)
}
