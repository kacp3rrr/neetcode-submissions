class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        c = Counter(nums)
        freq = list(c.items())
        freq.sort(key = lambda x: (x[1], x[0]), reverse=True)
        res = []
        for i in range(k):
            res.append(freq[i][0])
        return res
        