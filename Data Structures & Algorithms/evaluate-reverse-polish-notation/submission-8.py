class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for entry in tokens:
            if entry in "+*/-":
                second = stack.pop()
                first = stack.pop()
                if entry == "+":
                    stack.append(first + second)
                elif entry == "-":
                    stack.append(first - second)
                elif entry == "*":
                    stack.append(first * second)
                else:
                    stack.append(int(first / second))
            else:
                stack.append(int(entry)) 
        return stack[-1]