class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        if(k==0){
            unordered_map<int , int> mp;
            for(int i = 0 ; i < nums.size() ; i++){
                if(mp.count(nums[i])==0)mp[nums[i]] = 1;
                else mp[nums[i]]++;
            }
            for(auto [x, y] : mp)if(y > 1)count++;
            return count;
        }
        unordered_set<int> st;
        for(int i = 0 ; i < nums.size() ; i++)st.insert(nums[i]);
        for(auto x  : st){
        if (st.count(x+k)>0)count ++;
        }
        return count;
    }
};