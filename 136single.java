import java.util.*;

public class s136single {
    public int singleNumber(int [] nums){
        Set q = new HashSet();
        for(int e : nums){
            if( q.contains(e) ) q.remove(e);
            else q.add(e);
        }
        if( q.iterator().hasNext() )
            return (int)q.iterator().next();
        else
            return 0;
    }

    public static void main(String [] args){
        s136single s = new s136single();
        int [] a = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};
        System.out.println( s.singleNumber(a) );
    }
}
