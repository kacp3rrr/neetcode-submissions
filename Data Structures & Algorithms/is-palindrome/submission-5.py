class Solution:
    def isPalindrome(self, s: str) -> bool:
        clean = [char.lower() for char in s if char.isalnum()]
        return clean == clean[::-1]