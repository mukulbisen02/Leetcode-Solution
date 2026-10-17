class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        // Step 1 & 2: Insert newInterval into Intervals and Sort it by start
        
        vector<vector<int>> insertArr;
        int m = intervals.size();
        bool insert = false;

        for (int i = 0; i < m; i++){
            int isStart = intervals[i][0];
            if (insert == false && isStart >= newInterval[0]){
                insertArr.push_back(newInterval);
                insert = true;
            }
            insertArr.push_back(intervals[i]);
        }
        if(insert == false){
            insertArr.push_back(newInterval);
        }


        vector<vector<int>> result;

        int n = insertArr.size();
        int st1 = insertArr[0][0];
        int end1 = insertArr[0][1];
        
        // Step 3: Merge Overlapping
        for (int i = 1; i < n; i++) {
            int st2 = insertArr[i][0];
            int end2 = insertArr[i][1];

            if (end1 >= st2) {
                end1 = max(end1, end2);
            } else {
                result.push_back({st1, end1});
                st1 = st2;
                end1 = end2;
            }
        }

        result.push_back({st1, end1});

        //Return final Intervals
        return result;
    }
};