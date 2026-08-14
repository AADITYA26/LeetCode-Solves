class Solution {
public:
    void helper(int n , int open , string &curr , unordered_set<string>& ans){
        if(open > n)return ;
        if(curr.size() == 2*n){
            if(open == 0)ans.insert(curr);
            return;
        }
        if(open > 0){
            curr.push_back(')');
            helper( n , open-1 , curr , ans );
            curr.pop_back();
        }
        if(open < n){
            curr.push_back('(');
            helper(n , open +1 , curr , ans);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        unordered_set<string> ans;
        string curr = "";
        helper(n , 0 , curr , ans);
        vector<string> v(ans.begin() , ans.end());
        return v;
    }
};