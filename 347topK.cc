class Solution {
private:
    int newPivot(int *array, int size){
        return 0;
    }

    void swap(int &i, int &j){ int tmp = i; i = j; j = tmp; }

    void partition(int pivot, int *array, int *payload, int size, int orderStatistics){
        if( pivot >= size ) return; // error case
        if( size == 0 || size == 1 ) return; // nothing left to do
        if( size == 2 ){
             if( array[0] > array[1] ){
                 swap(array  [0],array  [1]);   
                 swap(payload[0],payload[1]);   
             }
             return;
        }

        swap(array  [0],array  [pivot]);
        swap(payload[0],payload[pivot]);

        int i = 1, j = 1;
        while( i < size && j < size ){
            if( array[0] <= array[i] ){
                i++;
            } else {
                swap(array  [i],array  [j]);
                swap(payload[i],payload[j]);
                i++;
                j++;
            }
        }

        swap(array  [0], array  [j-1]);
        swap(payload[0], payload[j-1]);

        // 0th order statistics is the first element
        if( orderStatistics == j-1 ) return;

        if( orderStatistics  < j-1 )
            partition( newPivot(array,j-1),    array,   payload,   j-1,    orderStatistics );
        else
            partition( newPivot(array,size-j), array+j, payload+j, size-j, orderStatistics-j );
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int i = 0;
        // first, count frequencies in linear time
        map<int,int> count;
        for(i = 0; i < nums.size(); i++) count[ nums[i] ]++;
        int size = count.size();
        // decompose it into two arrays for later use in quickselect
        int *freq = new int[size], *vals = new int[size];
        i = 0;
        for(auto &c : count){
            freq[i] = c.second;
            vals[i] = c.first;
            i++;
        }

        // run quickselect 1 time to find k-th order statistics
        partition( newPivot(freq,size), freq, vals, size, size-k);

        vector<int> retval(k);
        for(int i=size-1,j=0; i>size-k-1; i--,j++)
           retval[j] = vals[i];

        return retval;
    }

};
