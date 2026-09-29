class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        length = len(nums)
        for i, n in enumerate(nums):
            x = length - i
            if n >= x and (i is 0 or nums[i-1] < x):
                return x
        return -1