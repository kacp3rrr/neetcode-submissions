class Solution {
public:
    int findMin(vector<int> &nums) {
        // two pointer approach. if the left pointer is less than the right, move right to mid
        // else, move left to mid. continue in this way until we approach the middle, which will
        // be the minimum element
        int left = 0; int right = nums.size() - 1;
        while (left != right) {
            // store old left and rights. there is a chance we skip over our window in the division of our array
            // if we detect this, then we know our minimum is somewhere between the old pointer and the new one
            int old_left = left;
            int old_right = right;
            // initial division of array
            if (left + 1 == right) {
                return min(nums[left], nums[right]);
            } else if (nums[left] < nums[right]) {
                right = left + (right - left) / 2;
            } else {
                left = left + (right - left) / 2;
            }
            // narrow window down in case we skipped over where the mid is
            if (nums[left] < nums[old_left]) {
                right = left;
                left = old_left;
            } else if (nums[right] > nums[old_right]) {
                left = right;
                right = old_right;
            }
        }
        return nums[left];
    }
};
