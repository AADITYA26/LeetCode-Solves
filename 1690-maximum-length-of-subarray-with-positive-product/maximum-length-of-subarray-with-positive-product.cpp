class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        int ans = 0;
        for(int x : nums){
            int oldpos = pos;
            int oldneg = neg;
            if(x > 0){
                pos = oldpos+1;
                neg = oldneg > 0 ? oldneg +1 : 0;
            }
            else if(x < 0){
                pos = oldneg > 0 ? oldneg +1 : 0;
                neg = oldpos + 1;
            }
            else{
                pos = 0;
                neg = 0;
            }
            ans = max(ans , pos);
        }
        return ans;
    }
};