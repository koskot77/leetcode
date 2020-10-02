// 1. transform prerequisites into a dictionary for quick lookups
// 2. use a list for sequence of courses and a set for qucik lookups of taken courses
// 3. use a recursive helper updating the list and set when queried for a specific course
// 4. loop over the courses
class Solution {
public:
    bool helper(int c, list<int> &seq, unordered_set<int> &explored, unordered_set<int> &pending, unordered_map<int,list<int>>& dict){
        if( explored.find(c) != explored.end() ) // error #1: forgot
            return true;
        if( !pending.insert(c).second )
            return false;
        auto pre = dict.find(c);
        if( pre != dict.end() )
            for(auto cp:pre->second){            
                if( explored.find(cp) == explored.end() &&
                    !helper(cp,seq,explored,pending,dict))
                    return false;
            }

        pending.erase(c);
        seq.push_back(c);
        explored.insert(c);
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> dict;
        for(int i=0; i<prerequisites.size(); ++i)
            dict[prerequisites[i][0]].push_back(prerequisites[i][1]);

        list<int> seq;
        vector<int> retval;
        unordered_set<int> explored, pending;
        for(int c=0; c<numCourses; ++c){
            if( !helper(c,seq,explored,pending,dict) ) return retval;
        }
        for(auto c:seq) retval.push_back(c);
        return retval;
    }
};

// A little simpler solution with topological sorting:
// 1. for each entry maintain "inDegree" count of other entries it depends on
// 2. create a queue of entries with no dependencies
// 3. loop popping entry form the queue and decrement "inDegree" of depending entries
// 4. push entry to the queue when it becomes free

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> dict;
        for(int i=0; i<prerequisites.size(); ++i){
            dict[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> inDegree(numCourses);
        for(int i=0; i<prerequisites.size(); ++i){
            inDegree[prerequisites[i][0]]++;
        }

        queue<int> free;
        for(int i=0; i<numCourses; ++i)
            if( inDegree[i] == 0 ){
                free.push(i);
            }
        
        vector<int> retval;
        while( !free.empty() ){
            int f = free.front();
            free.pop();
            retval.push_back(f);
            for(auto c:dict[f]){
                inDegree[c]--;
                if( inDegree[c] == 0 ){
                    free.push(c);
                }
            }
        }
        if( retval.size() != numCourses ) return vector<int>();
        return retval;
    }
};
