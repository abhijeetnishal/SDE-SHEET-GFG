/*
Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

Input:
Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}
Explanation: Given intervals: [1,3],[2,4][6,8],[9,10], we have only two overlapping
intervals here,[1,3] and [2,4]. 
Therefore we will merge these two and return [1,4],[6,8], [9,10].

TC: O(N*Log(N))  SC: O(N)
*/

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    
    //to find overlapping interval we want minimum start value
    sort(intervals.begin(),intervals.end());
    
    //push the start value as it is minimum
    ans.push_back(intervals[0]);
    
    //now compare with end value of previous to current start value.
    for(int i=1;i<intervals.size();i++){
        //update the previous ans second value
        if(intervals[i][0]<=ans.back()[1])
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        else
            ans.push_back(intervals[i]);
    }
    
    return ans;
}
