class Solution {
public:
/*
    bool isCyclic(unordered_map<int, int>& pre, vector<bool>& exp, vector<bool>& cyclic, int point){
        if( cyclic[point] || exp[point] ) return true;
        exp[point] = true;
        auto it = pre.find(point);
        // reached the end of the current path?
        if( it == pre.end() ) return false;
        return cyclic[point] = isCyclic(pre, exp, cyclic, it->second);
    }

    bool dfs(int &n, unordered_map<int, int>& pre, vector<bool>& explored, vector<bool>& cyclic, int point){
        if( cyclic[point] ) return true;
        if( explored[point] ) return false;
        explored[point] = true;
        --n;
        auto it = pre.find(point);
        if( it == pre.end() ) return false;
        return dfs(n,pre,explored,cyclic,it->second);
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int,int> pre;
        int nCourses = 0;
        for(int start=0; start<prerequisites.size(); ++start){
            if(prerequisites[start].first > nCourses )
                nCourses = prerequisites[start].first;
            if(prerequisites[start].second > nCourses )
                nCourses = prerequisites[start].second;
                pre[ prerequisites[start].first ] = 
                     prerequisites[start].second;
        }

        // mark all cycles first
        vector<bool> cyclic  (nCourses);
        for(auto &link: prerequisites){
            vector<bool> exp(nCourses);
            isCyclic(pre,exp,cyclic,link.first);
        }
        
        vector<bool> explored(nCourses);
        for(auto &link: prerequisites){
            int n = numCourses;
            // dfs returns wether there is a cycle is encountered
            if( dfs(n,pre,explored,cyclic,link.first) )
                continue;
            numCourses = n;
            if( numCourses <= 0 ) return true;
        }
        return false;
    }
*/
    bool isCyclic(multimap<int, int>& pre, unordered_map<int,int>& exp, int point){
        auto seen = exp.find(point);
        if( seen != exp.end() ){
            if( seen->second == 0 ) return true;
            return false;
        }
        exp[point] = 0;
        auto start = pre.lower_bound(point);
        auto end   = pre.upper_bound(point);
        for(auto val = start; val != end; ++val)
            if( isCyclic(pre, exp, val->second) ) return true;
        exp[point] = 1;
        return false;
    }

    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        multimap<int,int> pre;
        for(int start=0; start<prerequisites.size(); ++start)
            pre.insert(make_pair(prerequisites[start].first,
                 prerequisites[start].second));

        for(auto &link: prerequisites){
            unordered_map<int,int> exp;
            if( isCyclic(pre,exp,link.first) ) return false;
        }
        return true;
    }
};
