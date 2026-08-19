class Solution {
public:
    bool isValid(vector<int> & nums , int days , int weight){
        int numDays = 1 ;
        int curr_weight = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]>weight)return false;
            if(curr_weight+nums[i] > weight){
                numDays++;
                curr_weight = nums[i];
            }
            else{
                curr_weight += nums[i];
            }
        }
        return numDays<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start =0;
        int end = accumulate(weights.begin() , weights.end() , 0);
        while(start<= end){
            int mid = start + (end-start)/2;
            if(isValid(weights , days , mid)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
        }
};