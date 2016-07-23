#include<iostream>
using namespace std;

int main(void){
    int a[] = {4,5,5,6}; //{1,2,2,1,2,1,1,1,1,2,2,2};
    int len = sizeof(a)/sizeof(int);
    for(int i=0; i<len-1; i++){
        if( i%2 ){
            int j = i+1;
            while( a[j] == a[i] && j<len ) j++;
            if( j == len ) return 0;
            if( j != i+1 ){
                int t  = a[i+1];
                a[i+1] = a[j];
                a[j]   = t;
            }
            if( a[i+1]  > a[i] ){
                int t = a[i];
                a[i]  = a[i+1];
                a[i+1]  = t;
            }
       } else {
            int j = i+1;
            while( a[j] == a[i] && j<len ) j++;
            if( j == len ) return 0;
            if( j != i+1 ){
                int t  = a[i+1];
                a[i+1] = a[j];
                a[j]   = t;
            }
            if( a[i+1]  < a[i] ){
                int t = a[i];
                a[i]  = a[i+1];
                a[i+1]  = t;
            }
       }
    }

    for(int i=0; i<len; i++) cout<<a[i]<<",";
    cout<<endl;


    return 0;
}
