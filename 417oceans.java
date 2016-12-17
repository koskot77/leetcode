//https://leetcode.com/problems/pacific-atlantic-water-flow/
import java.util.*;

public class s417oceans {
    public static class Tuple<X, Y> { 
        public final X x; 
        public final Y y; 
        public Tuple(X x, Y y) { this.x = x; this.y = y; }
        public String toString(){ return "(" + x + "," + y + ")"; }
        public boolean equals(Object other) {
            if (other == this) return true;
            if (!(other instanceof Tuple)) return false;
            Tuple<X,Y> other_ = (Tuple<X,Y>) other;
            return other_.x.equals(this.x) && other_.y.equals(this.y);
        }
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + ((x == null) ? 0 : x.hashCode());
            result = prime * result + ((y == null) ? 0 : y.hashCode());
            return result;
        }
    }

    private static void dfs(Tuple<Integer,Integer> node, Set<Tuple<Integer,Integer>> explored, int[][] matrix){
        System.out.println(node);
        explored.add(node);
        int x = node.x;
        int y = node.y;
        // move right:
        if( node.x<matrix[0].length-1 && !explored.contains(new Tuple<Integer,Integer>(x+1,y)) && matrix[y][x+1]>=matrix[y][x] )
            dfs(new Tuple<Integer,Integer>(x+1,y),explored,matrix);
        // move left:
        if( node.x>0               && !explored.contains(new Tuple<Integer,Integer>(x-1,y)) && matrix[y][x-1]>=matrix[y][x] )
            dfs(new Tuple<Integer,Integer>(x-1,y),explored,matrix);
        // move up:
        if( node.y>0               && !explored.contains(new Tuple<Integer,Integer>(x,y-1)) && matrix[y-1][x]>=matrix[y][x] )
            dfs(new Tuple<Integer,Integer>(x,y-1),explored,matrix);
        // move down:
        if( node.y<matrix.length-1 && !explored.contains(new Tuple<Integer,Integer>(x,y+1)) && matrix[y+1][x]>=matrix[y][x] )
            dfs(new Tuple<Integer,Integer>(x,y+1),explored,matrix);

    }

    public List<int[]> pacificAtlantic(int[][] matrix) {
        if( matrix.length < 1 ) return new LinkedList<int[]>();
        if( matrix[0].length < 1 ) return new LinkedList<int[]>();
        // DFS from the borders
        Set<Tuple<Integer,Integer>> exploredPacific = new HashSet<Tuple<Integer,Integer>>();
        for(int x=0; x<matrix[0].length; x++)
            dfs(new Tuple<Integer,Integer>(x,0),exploredPacific,matrix);
        for(int y=0; y<matrix.length; y++)
            dfs(new Tuple<Integer,Integer>(0,y),exploredPacific,matrix);

        Set<Tuple<Integer,Integer>> exploredAtlantic = new HashSet<Tuple<Integer,Integer>>();
        for(int x=0; x<matrix[0].length; x++)
            dfs(new Tuple<Integer,Integer>(x,matrix.length-1),exploredAtlantic,matrix);
        for(int y=0; y<matrix.length; y++)
            dfs(new Tuple<Integer,Integer>(matrix[0].length-1,y),exploredAtlantic,matrix);

        // find overlap of two explored sets
        LinkedList<int[]> retval = new LinkedList<int[]>();
        for(Tuple<Integer,Integer> point : exploredPacific)
            if( exploredAtlantic.contains(point) )
                retval.addFirst(new int[]{point.x,point.y});
        return retval;
    }

    public static void main(String[] argv){
        // The solution is trivial: using dfs explore all nodes reacheable
        //  from the left/top and bottom/right borders
        // Then find the overlap between two sets
        s417oceans s = new s417oceans();
        int [][] matrix = {
                {1, 2, 2, 3, 5,},
                {3, 2, 3, 4, 4,},
                {2, 4, 5, 3, 1,},
                {6, 7, 1, 4, 5,},
                {5, 1, 1, 2, 4,},
        };

        List<int[]> l = s.pacificAtlantic(matrix);
        for(int[] p : l){
            System.out.println("["+p[0]+","+p[1]+"],");
        }
    }
}
