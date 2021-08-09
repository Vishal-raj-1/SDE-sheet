class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergeInterval;
        if(intervals.size() == 0)
            return mergeInterval;
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];
        for(auto it: intervals){
            if(it[0] <= tempInterval[1]){
                tempInterval[1] = max(tempInterval[1], it[1]);
            }
            else{
                mergeInterval.push_back(tempInterval);
                tempInterval = it;
            }
        }
        mergeInterval.push_back(tempInterval);
        return mergeInterval;
    }
};