class Solution:
    def isValid(self, s: str) -> bool:
        stack = ""
        for char in s:
            if char in ["(", "{", "["]:
                stack = stack + char
                continue
            if char == ")":
                if len(stack) == 0 or stack[-1] != "(":
                    return False
                stack = stack[:-1]
            if char == "}":
                if len(stack) == 0 or stack[-1] != "{":
                    return False
                stack = stack[:-1]
            if char == "]":
                if len(stack) == 0 or stack[-1] != "[":
                    return False
                stack = stack[:-1]
        return len(stack) == 0