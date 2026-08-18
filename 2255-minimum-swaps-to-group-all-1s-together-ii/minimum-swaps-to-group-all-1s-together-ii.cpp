class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> temp(nums.begin() , nums.end());
        temp.insert(temp.end() , nums.begin() , nums.end());
        int left = 0 ;
        int right = 0 ;
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++)if(nums[i]==1)count++;
        int zeroes = 0;
        for( ; right < count ; right++)if(temp[right]==0)zeroes++;
        int minflip = INT_MAX;
        while(right < temp.size()){
            if(temp[right]==0)zeroes++;
            if(temp[left]==0)zeroes--;
            left++;
            right++;
            minflip = min(minflip , zeroes);
        }
        return minflip;
    }
};