// https://leetcode.com/problems/check-if-a-string-can-break-another-string/
// Main error: concisnes!
#include<string>
#include<algorithm>
#include<list>
#include<iostream>
#include<iterator>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
/*        // N log N:
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        list<int> output;
        transform(s1.begin(), s1.end(), s2.begin(), back_inserter(output), [](auto a, auto b){ return int(a<=b); }); // write a loop, it is better here!
        int qwe = accumulate(output.begin(), output.end(), 0);
        output.clear();
        transform(s2.begin(), s2.end(), s1.begin(), back_inserter(output), [](auto a, auto b){ return int(a<=b); });
        int ewq = accumulate(output.begin(), output.end(), 0); // error2: don't forget another case
        return qwe == 0 || qwe == output.size() || ewq == 0 || ewq == output.size();
*/

        // Conceptual error below: think it through well: you could have only one array with ++ and --

        // linear time algorithm:
        // sorting a long string composed out of just 24 symbols is a waste
        // it is easier to transform it into a compressed representation that records
        //  positions at which a letter is encountered, e.g.:
        // aaabbbbccccdddddxyy <- a:0, b:3, c:7, d:11, ...:11, x:16, y:18, z:18
        // aaaabbbcccddddddzzz <- a:0, b:4, c:7, d:10, ...:10, y:10, x:10, z:16
        // (here non-encountered letters share the same position) // error3: too complicated
        int content1[26] = {}, content2[26] = {}; // error4: don't use unordered_maps and the algos with lambdas, simplicity = concisenes!
        for(char a='a'; a<='z'; ++a){
            content1[a-'a'] = 0;
            content2[a-'a'] = 0;
        }
        // in the first pass just remember number of times each symbol is encountered:
        for(string::size_type pos=0; pos<s1.length(); ++pos){
            ++content1[s1[pos] - 'a'];
            ++content2[s2[pos] - 'a'];
        }
        // in the second pass arrange cumsums
        for(int a='a', pos=0; a<='z'; ++a)
            content1[a-'a'] = (pos += content1[a-'a']);
        for(int a='a', pos=0; a<='z'; ++a)
            content2[a-'a'] = (pos += content2[a-'a']);
        // in example above b_1 < b_2 -> first string is greater and should stay greater or equal for every letter

        bool hypo_s1_smaller = true, hypo_s1_bigger = true; // conceptual error: you started overcomplicated!!!
        // see if any of the hypotheses break
        for(char a='a'; a<='z'; ++a){
            hypo_s1_smaller &= content1[a-'a'] >= content2[a-'a'];
            hypo_s1_bigger  &= content1[a-'a'] <= content2[a-'a'];
        }
        return hypo_s1_smaller || hypo_s1_bigger;
    }
};

int main(void){
  Solution s;

  std::cout << s.checkIfCanBreak("abc", "xya") << std::endl;
  std::cout << s.checkIfCanBreak("abe" ,"acd") << std::endl;
  std::cout << s.checkIfCanBreak("leetcodee", "interview") << std::endl;
  std::cout << s.checkIfCanBreak(
"kzhzftlizddyqufzatteiowyiermusnthqffwkkguajuscvleecbqwevbyvdoqmbcehopqnrdgmydckjimkbbdxhbadocyybnwsfncowvqhdzdgiwvhikxaegommlvwirdpqfitiotysbtfelfknpramlkgaoelkwcjawvjpdfcozhhxyjahmbbuwoojyewwtjpizcehuclhedauabfdbstdlutcdsyhwpycbhapjqhekmwdqwhpdwgcgxdwfyie",
"ggphtnsczwwvqetdjcdfqycsdtalpunmkvluuzqqkoacqhjwimzffxdkziacxtidgrwnppwpwbtetkxibzxvymcwycrwlaukxwgfzqlnqhjunwzszmuauuipdrdyilezzmwuicjvqplhnigsolphjgwscobunccpwsilwznmorqlzrzbonlidxfhiiymrdezmvigxzucncpymbdgtookqkgoxzimcghucwruczqpnfidyyadimotttyouglbaymo"
  ) << std::endl;

  return 0;
}
