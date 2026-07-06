class Solution:
    def maxDepth(self, s: str) -> int:
        cnt = 0
        max_cnt = 0

        for char in s:
            if char == '(':
                cnt += 1
                max_cnt = max(cnt, max_cnt)
            elif char == ')':
                cnt -= 1

        return max_cnt