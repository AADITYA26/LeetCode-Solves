class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int> mp;
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right < s.size()){
            if(mp.count(s[right])!=0){
                char l = s[left];
                while(left<=right&&mp.count(l)>0){
                    left++;
                    mp[l]--;
                    if(mp[l]==0)mp.erase(l);
                }
            }
            else{
                mp[s[right]]++;
                ans = max(ans , right-left+1);
                right++;
            }
        }
        return ans;
    }
};