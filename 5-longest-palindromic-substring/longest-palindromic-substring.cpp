class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans;
        for(int i = 0 ; i < n ; i++){
            int left = i ;
            int right = i ;
            string t;
            while(left >= 0 && right < n &&s[left] == s[right]){
                left--;
                right++;
            }
            t = s.substr(left +1, right-left-1);
            if(ans.size() < t.size())ans=t;
        }
        for(int i = 0 ; i < n ; i++){
            int left = i ;
            int right = i+1 ;
            string t;
            while(left >= 0 && right < n &&s[left] == s[right]){
                left--;
                right++;
            }
            t = s.substr(left +1, right-left-1);
            if(ans.size() < t.size())ans=t;
        }
        return ans;
    }
};