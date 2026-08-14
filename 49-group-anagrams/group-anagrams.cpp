class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , int> ans_index;
        vector<vector<string>> ans;
        for(int i = 0 ; i < strs.size() ; i++){
            string temp(strs[i]);
            sort(temp.begin() , temp.end());
            if(ans_index.count(temp)==0){
                ans.push_back({strs[i]});
                ans_index[temp] = ans.size()-1;
            }
            else{
                ans[ans_index[temp]].push_back(strs[i]);
            }
        }
        return ans;
    }
};