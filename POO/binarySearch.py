#Nome: Leonardo Tomasela Leal RA:170291

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        firstIndex = 0
        lastIndex = len(nums) - 1
        while(firstIndex <= lastIndex):
            midIndex = (firstIndex + (lastIndex - firstIndex)//2)
            if(nums[midIndex] == target):
                return midIndex
            elif(nums[midIndex] > target):
                lastIndex = midIndex - 1
            else:
                firstIndex = midIndex + 1
        return -1   