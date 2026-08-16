class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        for(int num : nums)mp[num]++;
        priority_queue<pair<int,int>> pq;
        for(auto [e , f] : mp){
            pq.push({f , e});
        }
        vector<int> ans;
        for(int i = 0 ;i < k ; i++ ){
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};