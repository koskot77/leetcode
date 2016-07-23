#include<stdio.h>
#include<map>
#include<set>
#include<vector>

using namespace std;

class Solution {
private:
multimap<int, pair<int,int> > verticals;
multimap<int, pair<int,int> > horisontals;
set< pair<int,int> > points;

public:
    bool isSelfCrossing(vector<int>& x) {
    multimap<int, pair<int,int> >::const_iterator prev = verticals.end();
    int posX = 0, posY = 0;
    points.clear();
    points.insert( pair<int,int>(posX,posY) );
    for(int i=0; i<x.size(); i++){
        switch( i%4 ){
            case 0: {
                multimap<int, pair<int,int> >::const_iterator cur  = verticals.insert(pair<int,pair<int,int> >(posX ,pair<int,int>(posY,posY-x[i])));
                multimap<int, pair<int,int> >::const_iterator from = horisontals.lower_bound(posY-x[i]);
                multimap<int, pair<int,int> >::const_iterator to   = horisontals.upper_bound(posY);
                for(multimap<int, pair<int,int> >::const_iterator j=from; j!=to; j++)
                    if( prev != verticals.end() && *prev != *j && j->second.first >= posX && j->second.second <= posX )
                        return true;
                posY -= x[i];
                prev = cur;
                } break;
            case 1: {
                multimap<int, pair<int,int> >::const_iterator cur  = horisontals.insert(pair<int,pair<int,int> >(posY ,pair<int,int>(posX,posX-x[i])));
                multimap<int, pair<int,int> >::const_iterator from = verticals.lower_bound(posX-x[i]);
                multimap<int, pair<int,int> >::const_iterator to   = verticals.upper_bound(posX);
                for(multimap<int, pair<int,int> >::const_iterator j=from; j!=to; j++)
                    if( prev != verticals.end() && *prev != *j && j->second.first >= posY && j->second.second <= posY )
                        return true;
                posX -= x[i];
                prev = cur;
                } break;
            case 2: {
                multimap<int, pair<int,int> >::const_iterator cur  = verticals.insert(pair<int,pair<int,int> >(posX ,pair<int,int>(posY,posY+x[i])));
                multimap<int, pair<int,int> >::const_iterator from = horisontals.lower_bound(posY);
                multimap<int, pair<int,int> >::const_iterator to   = horisontals.upper_bound(posY+x[i]);
                for(multimap<int, pair<int,int> >::const_iterator j=from; j!=to; j++)
                    if( prev != verticals.end() && *prev != *j && j->second.first >= posX && j->second.second <= posX )
                        return true;
                posY += x[i];
                prev = cur;
                } break;
            case 3: {
                multimap<int, pair<int,int> >::const_iterator cur  = horisontals.insert(pair<int,pair<int,int> >(posY ,pair<int,int>(posX,posX+x[i])));
                multimap<int, pair<int,int> >::const_iterator from = verticals.lower_bound(posX);
                multimap<int, pair<int,int> >::const_iterator to   = verticals.upper_bound(posX+x[i]);
                for(multimap<int, pair<int,int> >::const_iterator j=from; j!=to; j++)
                    if( prev != verticals.end() && *prev != *j && j->second.first >= posY && j->second.second <= posY )
                        return true;
                posX += x[i];
                prev = cur;
                } break;
            default: break; //exit(1);
         };
         printf("inserting: %d %d\n",posX,posY);
         if( !points.insert( pair<int,int>(posX,posY) ).second ) return true;
    }
    return false;
    }
    };

int main(void){
    const int x[] = {1, 2, 3, 4};

vector<int> y;
y.push_back(1);
y.push_back(1);
y.push_back(2);
y.push_back(1);
y.push_back(1);

Solution qwe;
printf("sc: %d\n",int(qwe.isSelfCrossing(y)));
    return 0;
}
