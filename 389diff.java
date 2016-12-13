import java.util.*;

public class s389diff {
    public static char findTheDifference(String s, String t) {
        char [] alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

        HashMap<Character,Integer> countsS = new HashMap<Character,Integer>();
        for(int l=0; l<alphabet.length; l++) countsS.put(alphabet[l],0);
        for(int pos=0; pos<s.length(); pos++)
            countsS.put( s.charAt(pos),  countsS.get(s.charAt(pos))+1 );

        HashMap<Character,Integer> countsT = new HashMap<Character,Integer>();
        for(int l=0; l<alphabet.length; l++) countsT.put(alphabet[l],0);
        for(int pos=0; pos<t.length(); pos++)
            countsT.put( t.charAt(pos),  countsT.get(t.charAt(pos))+1 );

        for(int l=0; l<alphabet.length; l++){
            int _s = countsS.get( alphabet[l] );
            int _t = countsT.get( alphabet[l] );
            if( _s != _t ) return alphabet[l];
        }

        return '\0';
    }

    public static void main(String args[]){
        System.out.println( findTheDifference("abcd","edcba") );
    }
}
