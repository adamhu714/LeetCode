class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1
        while l < r:
            mid = (l+r)//2
            if nums[mid] == target:
                return mid
            
            if nums[mid] > nums[-1]:
                #left of pivot
                if nums[mid] < target or target <= nums[-1]:
                    l = mid + 1
                else:
                    r = mid - 1
                    
            else:
                if nums[mid] > target or target > nums[-1]:
                    r = mid - 1
                else:
                    l = mid + 1
                    
        if nums[l] == target:
            return l
        return -1