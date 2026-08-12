class Solution {
public:
    void backtrack(string &digits , vector<string> &mapping , int index  , string &curr , vector<string>& ans){
        if(index == digits.size()){
            ans.push_back(curr);
            return;
        }
        for(char c : mapping[digits[index]-'0']){
            curr.push_back(c);
            backtrack(digits,mapping,index+1,curr,ans);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string curr = "";
        backtrack(digits,mapping,0,curr,ans);
        return ans;

    }
};