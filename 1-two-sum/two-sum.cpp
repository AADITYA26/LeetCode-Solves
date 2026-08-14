class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mp;
        vector<int> ans(2,0);
        for(int i = 0 ; i < nums.size() ; i++){
            if(mp.count(target - nums[i])==0){
                mp[nums[i]] = i;
            }
            else {
                ans[0] = mp[target - nums[i]];
                ans[1] = i;
            }
        }
        return ans;
    }
};