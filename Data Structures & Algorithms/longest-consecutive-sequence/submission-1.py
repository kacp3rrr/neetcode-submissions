class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)
        res = 0
        for i in range(len(nums)):
            curr = nums[i]
            currSeqSize = 1
            if curr - 1 not in numSet:
                while curr + 1 in numSet:
                    curr += 1
                    currSeqSize += 1
            res = max(res, currSeqSize)
        return res