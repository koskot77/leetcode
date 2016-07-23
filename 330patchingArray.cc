int minPatches(vector<int>& nums, int n) {
        // This solution is taken from https://leetcode.com/discuss/102653/c-8ms-greedy-solution-with-explanation
        // here the important concept is so called maximum number that we can achieve adding all numbers up to current
        //  1. empty nums means maxNumber = 0
        //  2. we can achieve maxNumber = 1 only if nums[0] is 1
        //     if it is not 1 we have to add it and move on to nums[1]
        //  3. we want to achieve maxNumber = 2, if nums[1] > 2 we insert again
        //     otherwise _we can achieve every number from nums[1] + maxNumber_
        long long maxNumber = 0, curPos = 0, numInserts = 0;
        while( maxNumber < n ){
            if( curPos < nums.size() && nums[curPos] <= maxNumber+1 ){
                maxNumber += nums[curPos];
                curPos++;
            } else {
                maxNumber += maxNumber + 1;
                numInserts++;
            }
        }
        return numInserts;
    }


