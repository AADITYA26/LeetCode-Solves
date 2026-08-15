class Solution {
public:
    int area(vector<int> & height , int i , int j){
        return min(height[i] , height[j])*(j-i);
    }
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxarea = 0;
        while(left < right){
            maxarea = max(maxarea , area(height ,left , right));
            if(height[left]<height[right])left++;
            else right --;
        }
        return maxarea;
    }
};