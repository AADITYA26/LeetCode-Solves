class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>  pos;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]==c)pos.push_back(i);
        }
        vector<int> ans;
        ans.push_back(pos[0]);
        for(int i = 1; i < s.size() ; i++ ){
            int mini = 1e9;
            for(int j = 0 ; j < pos.size() ; j++){
                mini = min(mini , abs(pos[j]-i));
            }
            ans.push_back(mini);
        }
        return ans;
    }
};