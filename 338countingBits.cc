#include<stdio.h>
#include<math.h>
#include<map>
#include<vector>
using namespace std;

map<int,unsigned int> known;

unsigned int countBitsSingle(unsigned int n){
    // base cases of the recursion
    if( n==0 ) return 0;
    if( n==1 ) return 1;

    // chop-off the most significant bit
    unsigned int msPos = log2(n);
    unsigned int m = n%(1<<msPos);

    // see if the number without this bit was already calculated
    if(  known.find(m) != known.end() ){
         // yes-> return the known number plus 1 for the extra bit set
         known[n] = known[m] + 1;
         return known[m] + 1;
    }

    // no -> count bits in the shorter number first
    unsigned int bits = countBitsSingle(m) + 1;
    known[n] = bits;

    return bits;

}

int main(void){
    const unsigned int num = 100000;
    vector<int> retval;
    for(unsigned int n=0; n<=num; n++){
        unsigned int bits = countBitsSingle(n);
        retval.push_back( bits );
        printf("%d,",bits);
    }

    return 0;
}
