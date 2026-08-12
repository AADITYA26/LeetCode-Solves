class Solution {
public:
    int quickSelect(vector<int>& nums, int left, int right, int target) {
        int pivot = nums[right];
        int i = left;

        // Put elements greater than pivot on the left
        for(int j = left; j < right; j++) {
            if(nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        // Put pivot in its correct position
        swap(nums[i], nums[right]);

        if(i == target)
            return nums[i];

        if(i > target)
            return quickSelect(nums, left, i - 1, target);

        return quickSelect(nums, i + 1, right, target);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int target = k-1;

        return quickSelect(nums, 0, nums.size() - 1, target);
    }
};