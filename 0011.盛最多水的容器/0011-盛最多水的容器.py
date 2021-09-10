https://leetcode-cn.com/problems/container-with-most-water/
class Solution:
    def maxArea(self, height: List[int]) -> int:
        if len(height) < 2:
            return 0
        i = 0
        j = len(height) - 1
        max = 0

        while i < j:
            product = (height[j] if height[i] > height[j] else height[i] ) * (j - i)

            if product > max:
                max = product
            if height[i] > height[j]:
                j = j - 1
            else:
                i = i + 1
        return max
