// How many balanced trees you can build with N nodes?
//   (balanced is defined here as a difference of depths between any
//    pair of leafs <= 1, i.e. a simple linked list would also considered
//    to be a balanced tree as it has only one leaf - the end link)

// Logic:
// 1) for N!=0 one node will always be the root
// 2) the remaining N-1 nodes will be destributed
//      between left and right subtrees
// 3) count how many suntrees they form for all possible compositions
// 4) at each sublevel return up only a number of compositions
//      where left and right subtrees are different in depth by at most 1

// simple case: number of all binary trees with N nodes:
int countAllTrees(int N)
{
    if( N==1 ) return 1;
    
    int retval = 0;
    for(int i = 1; i < N-1; ++i)
    {
        int left  = countAllTrees(i);
        int right = countAllTrees(N-1-i);
        retval += left + right;
    }
    return retval;
}

// for the requirement of balancing I need to define min and max depth
//  in left and right subtrees and make sure they are off by at most 1 
int countBalancedTrees(int N, int& max_depth, int& min_depth)
{
    // end cases for the recursion
    if( N==1 )
    {
        // x
        min_depth = 0;
        max_depth = 0;
        return 1;
    }
    if( N==2 )
    {                     
        //   x  and  x
        //  /         \
        // x           x
        min_depth = 1; // even the other leaf is missing
        max_depth = 1;
        return 2;
    }

    int retval = 0;
    for(int i = 1; i < N-1; ++i)
    {
        int min_depth_l = 0, max_depth_l = 0;
        int min_depth_r = 0, max_depth_r = 0;
        // recursion
        int left  = countBalancedTrees(i,     min_depth_l, max_depth_l);
        int right = countBalancedTrees(N-1-i, min_depth_r, max_depth_r);
        // check that left and right subtrees are not too different in depth
        if( abs(min_depth_l - max_depth_r) <= 1 &&
            abs(min_depth_r - max_depth_l) <= 1)
        {
            retval += left + right;
            min_depth = min(min_depth_l, min_depth_r) + 1;
            max_depth = max(max_depth_l, max_depth_r) + 1;
        }
    }
    return retval;
}
