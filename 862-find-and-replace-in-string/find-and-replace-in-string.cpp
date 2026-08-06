class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string ans;
        unordered_map<int,vector<int>> map;
        for(int i = 0 ; i < indices.size() ; i++){
            map[indices[i]].push_back(i);
        }
        for(int i =0 ; i < s.size() ; i++){
            bool replaced = false;
            if(map.count(i)){
                for(int ind : map[i]){
                    if(s.substr(i,sources[ind].size())==sources[ind]){
                        ans+=targets[ind];
                        i+=sources[ind].size()-1;
                        replaced = true;
                        break;
                    }
                }
            }
            if(!replaced){
                ans+=s[i];
            }
        }
        return ans;
    }
};