class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # treat matrix like one giant 1d array to binary search
        height, width = len(matrix), len(matrix[0]) 
        left, right = 0, (len(matrix) * len(matrix[0])) - 1
        while left <= right:
            mid = left + (right - left) // 2
            row = mid // width
            col = mid % width
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] < target:
                left = mid + 1
            else:
                right = mid - 1
        return False