class Solution:
    def isValid(self, s: str) -> bool:
        bracket_map = {")": "(", "}": "{", "]": "["}
        stack = []
        for c in s:
            if c in bracket_map:
                top_el = stack.pop() if stack else 'x'
                if (bracket_map[c] != top_el):
                    return False
            else:
                stack.append(c)
        return len(stack) == 0
        