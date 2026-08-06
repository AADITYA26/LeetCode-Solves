class Solution {
public:
    bool comp(vector<int> vals){
        return vals[0]<vals[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        for(int i = 0 ; i < n ; i++){
            int start = intervals[i][0];
            int end  = intervals[i][1];
            if(!ans.empty()&&end<=ans.back()[1]){
                continue;
            }
                if(ans.empty()||start>ans.back()[1]){
                    ans.push_back({start,end});
                }
                else{
                    ans.back()[1] = end;
                }
        }
        return  ans;
    }
};