class Solution:
    def search(self, nums: List[int], target: int) -> int:
        """
        find an element in a rotated sorted array
        cases at any point:
        - left < right: normal binary search
        - left > right: 
            - one of the halves divided by mid is sorted
            - determine where target lives based on that
        """
        l, r = 0, len(nums) - 1
        while l <= r:
            m = l + (r - l) // 2
            left, mid, right = nums[l], nums[m], nums[r]

            # binary search boundary checks
            if mid == target:
                return m
            if left <= mid: # left half sorted
                if left <= target < mid:
                    r = m - 1
                else:
                    l = m + 1
            else: # right half sorted
                if mid < target <= right:
                    l = m + 1
                else:
                    r = m
        return -1