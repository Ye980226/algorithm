class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashTable={}
        for i in range(len(nums)):
            hashTable[nums[i]]=i
        for i in range(len(nums)):
            target_j=target-nums[i]
            if target_j in hashTable and i!=hashTable[target_j]:
                return [i,hashTable[target_j]]
s=Solution()
print(s.twoSum([3,2,4],6))