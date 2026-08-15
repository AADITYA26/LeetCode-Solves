class Solution {
public:
    void combinationSum(vector<int> & nums , int i ,int target ,  vector<int> & curr , vector<vector<int>> & ans){
        if(target == 0){
            ans.push_back(curr);
            return ;
        }
        if(i==nums.size()||target<0){
            return ;
        }
        curr.push_back(nums[i]);
        combinationSum(nums ,i , target-nums[i] , curr , ans);
        curr.pop_back();
        combinationSum(nums ,i+1 , target , curr , ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        combinationSum(candidates , 0 ,target , curr , ans);
        return ans;
    }
};