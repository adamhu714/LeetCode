class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return int(0.5 * (high - low + high % 2 + low % 2))