class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , int> mp;
        if(t.empty())return "";
        int left = 0 ;
        int right = 0 ;
        int missing = t.size();
        int bestLen = INT_MAX;
        int bestStart = 0;
        string ans;
        while(left < t.size()){
            mp[t[left]]++;
            left++;
        }
        left = 0;
        while(right<s.size()){
            if(mp.count(s[right])>0){
                if(mp[s[right]]>0)missing--;
                mp[s[right]]--;
            }
            while(missing == 0 ){
                int len = right - left + 1;
                if(len < bestLen) {
                    bestLen = len;
                    bestStart = left;
                }
                if(mp.count(s[left])&&mp[s[left]]==0)missing++;
                if(mp.count(s[left])>0)mp[s[left]]++;
                left++;
            }
            right++;
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};