class Solution {
public:
    void helper(int n , int open , string &curr , vector<string>& ans){
        if(open > n)return ;
        if(curr.size() == 2*n){
            if(open == 0)ans.push_back(curr);
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
        vector<string> ans;
        string curr = "";
        helper(n , 0 , curr , ans);
        return ans;
    }
};