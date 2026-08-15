class Solution {
public:
    vector<int> rightMax(vector<int> heights){//O(n) time , O(n) space 
    int maximum = 0;
    vector<int> ans(heights.size());
    for(int i = heights.size()-1 ; i >=0 ; i-- ){
        ans[i] = maximum;
        maximum = max(maximum,heights[i]);
    }
    return ans;
}

    vector<int> leftMax(vector<int> heights ){//O(n) time , O(n) Space 
        int maximum = 0;
        vector<int> ans(heights.size());
        for(int i = 0 ; i<heights.size(); i++){
            ans[i] = maximum;
            maximum = max(maximum ,heights[i]);
        }
        return ans;
    }

    int trap(vector<int>& height) {
        vector<int> right  = rightMax(height);
        vector<int> left = leftMax(height);
        int sum = 0 ;
        for(int i = 0 ; i < height.size() ; i++){
            sum += max(0 , min(right[i],left[i])-height[i]);
        }
        return sum;
    }
};