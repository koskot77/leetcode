// https://leetcode.com/problems/path-with-maximum-probability/
// General problem: had to build the priority queue first
type Node struct {
    v int     // node name
    w float64 // cumulative path to reach this node
}
type NodeHeap []Node

func (h NodeHeap) Len() int           { return len(h) }
func (h NodeHeap) Less(i, j int) bool { return h[i].w < h[j].w }
func (h NodeHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *NodeHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(Node))
}

func (h *NodeHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// error #1: there must be an elegant Dijkstra's implementation, this code is an experimantation
func maxProbability(n int, edges [][]int, succProb []float64, start int, end int) float64 {
    // need to reshuffle edges to be quickly searchable
    explored := make(map[int]float64)
    adjacency_list := make([][]Node, n)
    for v,e := range edges {
        adjacency_list[e[0]] = append(adjacency_list[e[0]], Node{e[1],succProb[v]})
        adjacency_list[e[1]] = append(adjacency_list[e[1]], Node{e[0],succProb[v]})
    }

    frontier := &NodeHeap{} // all the nodes to immenently consider to be explored
    heap.Init(frontier)

// error #2: cannot get away without exlored nodes:
    explored[start] = 10
    var retval float64 = -10

    // initialize the frontier
    for _,node := range adjacency_list[start] {
        var nn = Node{node.v, -math.Log(node.w+0.000000001)}
        heap.Push(frontier, nn)
// error #3: didn't consider reaching the destination in the beginning:
        if nn.v == end && retval < math.Exp(-nn.w) {
            retval = math.Exp(-nn.w)
        }
    }

    // explore the graph
    for frontier.Len() > 0 {
        var node Node = heap.Pop(frontier).(Node)
        explored[node.v] = node.w + 10
//        fmt.Printf("just poped: %v, edges: %v\n",node.v,adjacency_list[node.v]  )
        for _,nn := range adjacency_list[node.v] {
//            fmt.Printf("frontier: %v nn.v:%v explored:%v\n",frontier,nn.v,explored[nn.v])
            x := Node{nn.v, -math.Log(nn.w+0.000000001) +node.w}
            if x.v == end && retval < math.Exp(-x.w) {
                retval = math.Exp(-x.w)
            }
// error #4: edges != nodes -> it is ok to have several copies of the same node in the frontier
            if explored[nn.v] > 1 {
                continue
            }
            heap.Push(frontier, x)
        }
    }
//    fmt.Printf("%v", explored)
    if retval < 0 {
        return 0
    }
    return retval
}
