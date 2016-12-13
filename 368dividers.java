//https://leetcode.com/problems/largest-divisible-subset/
//https://discuss.leetcode.com/topic/71680/annotated-java-solution
import java.util.*;

class s368 {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        // Two key observations:
        //  1) A % B == 0 iff A >= B
        //  2) when A is divisible by B, it is also divisible by all of the B's dividers
        // Therefore, we sort the input first and for each element from smallest to largest
        //   remember position of its divider that had largest number of dividers itself
        //   also remember the number of dividers (number of dividers of the divider + 1)

        // guard against usual nonsence in the test cases
        if( nums.length == 0 ) return new LinkedList<Integer>();

        // first sort the input
        Arrays.sort(nums);

        // the two auxiliary arrays
        int[] dividerPos = new int[nums.length];
        int[] nDividers  = new int[nums.length];

        // position of the number that has largest set of dividers among the *nums*
        int winnerPos=0, winnerSize=0;

        // iterate over the sorted input
        for(int pos=0; pos<nums.length; pos++){
            // look back at every smaller element
            for(int rpos=pos; rpos>=0; rpos--){
                // and see if it is a divider
                if( nums[pos] % nums[rpos] == 0 ){
                    // check if this element  has largest set of dividers
                    if( nDividers[pos] < nDividers[rpos]+1 ){
                        // and update number of dividers for the current number
                        nDividers[pos] = nDividers[rpos]+1;
                        dividerPos[pos] = rpos; // and position of the current winner
                    }
                }
            }
            // look for the global winner
            if( winnerSize < nDividers[pos] ){
                winnerSize = nDividers[pos];
                winnerPos = pos;
            }
        }
        // now build the largest set
        LinkedList<Integer> retval = new LinkedList<Integer>();
        int lastDividerPos = winnerPos;
        while( true ){
            retval.addFirst( nums[lastDividerPos] );
            // number is only divisible by itself -> end of story
            if( lastDividerPos == dividerPos[lastDividerPos] ) break;
            lastDividerPos = dividerPos[lastDividerPos];
        }
        return retval;
    }

    static public void main(String[] argv){
        s368 s = new s368();
        int[] input = {1,2,4,8};
        List<Integer> output = s.largestDivisibleSubset(input);
        for(Integer i:output) System.out.print(i.toString()+",");
        System.out.println("");
    }
}
