import java.util.*;

public class s463island {

    public static int islandPerimeter(int[][] grid) {
        int retval = 0;
        for(int i=0; i<grid.length; i++)
            for(int j=0; j<grid[i].length; j++){
                int neighbours = 0;
                if( j!=0 && grid[i][j-1] == 1 ) neighbours += 1;
                if( j<grid[i].length-1 && grid[i][j+1] == 1 ) neighbours += 1;
                if( i!=0 && grid[i-1][j] == 1 ) neighbours += 1;
                if( i<grid.length-1 && grid[i+1][j] == 1 ) neighbours += 1;
                if( grid[i][j] == 1 ) retval += 4 - neighbours;;
            }

        return retval;
    }

    public static void main(String[] args){
        int grid[][] =
             { {1,0,0,0,0,0,0},
               {1,1,0,0,0,0,0},
               {0,1,1,0,0,0,0},
               {0,0,1,0,1,0,0},
               {0,0,1,1,1,0,0},
               {0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0}};
        int border = islandPerimeter(grid);
        System.out.println("Border: "+border);
    }
}
