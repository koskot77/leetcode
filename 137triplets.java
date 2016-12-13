import java.util.*;

public class s137triplets {
    public int singleNumberExtraSpace(int[] nums) {
        HashMap<Integer,Integer> lut = new HashMap<Integer,Integer>();
        for(int n : nums){
            if( lut.containsKey(n) )
                lut.put(n,lut.get(n)+1);
            else
                lut.put(n,1);
        }
        Iterator iter = lut.keySet().iterator();
        Integer result = 0;
        while( iter.hasNext() ){
            result = (Integer)iter.next();
            if( lut.get(result) != 3 )
                break;
        }
        return result;
    }

    public int singleNumber(int[] nums) {

    }

    static public void main(String [] args){
        s137triplets s = new s137triplets();
        int [] a = {1,2,3,4,5,6,7,8,9,0,0,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,0};
        System.out.println( s.singleNumber(a) );
    }
}
