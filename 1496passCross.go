func isPathCrossing(path string) bool {
    var visited = make(map[[2]int]bool)
    var x,y int = 0,0
    visited[[2]int{x,y}] = true
//    var r = strings.NewReader(path)
//    var b = make([]byte,1)
//    for {
//		_, err := r.Read(b)
//        if err == io.EOF {
//          break
//        }
//    }
    for i:=0; i<len(path); i++ {
        b := path[i]
        switch b {
	      case 'N': y+=1
          case 'S': y-=1
          case 'W': x-=1
          case 'E': x+=1
          default:
            fmt.Printf("%c\n", b)
        }
        _, ok := visited[[2]int{x,y}]
        if ok {
            return true
        }
        visited[[2]int{x,y}] = true
    }
    return false
}
