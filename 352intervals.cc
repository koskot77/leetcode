#include<set>
#include<vector>
#include<iostream>
using namespace std;

struct Interval {
 int start;
 int end;
 Interval() : start(0), end(0) {}
 Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
private:
    set<Interval,bool(*)(Interval,Interval)> array;

    static bool comp(Interval a, Interval b){
        return a.end < b.start;
    }

public:
    /** Initialize your data structure here. */
    SummaryRanges() : array(comp) {}

    void addNum(int val) {
        set<Interval>::iterator succ = array.upper_bound( Interval(val,val) );
        set<Interval>::iterator pred = array.lower_bound( Interval(val,val) );

        if( pred != array.begin() && array.size() ) pred--;
        else pred = array.end();

        if( pred != array.end() && pred->end == val-1 && succ != array.end() && succ->start == val+1 ){
            Interval newpred = *pred;
            newpred.end = succ->end;

            array.erase(succ);
            array.erase(pred);
            array.insert(newpred);

            return;
        }

        if( pred != array.end() && pred->end == val-1 ){
            Interval newpred = *pred;
            newpred.end = val;

            array.erase(pred);
            array.insert(newpred);

            return;
        }

        if( succ != array.end() && succ->start == val+1 ){
            Interval newsucc = *succ;
            newsucc.start = val;

            array.erase(succ);
            array.insert(newsucc);

            return;
        }

        array.insert(pred,Interval(val,val));
    }

    

    vector<Interval> getIntervals() {
        vector<Interval> retval(array.size());
        set<Interval>::const_iterator e = array.begin();
        for(int i=0; e!=array.end(); i++,e++) retval[i] = *e;
        return retval;
    }

};

int main(void){
SummaryRanges q;
q.addNum(9);
q.addNum(1);
q.addNum(3);
q.addNum(7);
q.addNum(2);
q.addNum(6);
q.addNum(8);
vector<Interval> qwe = q.getIntervals();
for(auto &i : qwe){
cout<<"["<<i.start<<","<<i.end<<"]"<<endl;
}
return 0;
}

/*
// Test :
#include<set>
#include<iostream>
using namespace std;
struct Interval{
int start;
int end;
Interval(int a, int b):start(a),end(b){}
};
bool comp(Interval a, Interval b){ return a.end < b.start; }


int main(void){
    set<Interval,bool(*)(Interval,Interval)> array(comp);
    array.insert(Interval(1,2));
    set<Interval>::iterator succ = array.lower_bound( Interval(3,3) );
    cout<<(succ==array.end())<<endl;
    set<Interval>::iterator elem = array.find( Interval(2,2) );
    cout<<(elem==array.end())<<endl;

    return 0;
}

// Result:
// 1
// 0
*/
