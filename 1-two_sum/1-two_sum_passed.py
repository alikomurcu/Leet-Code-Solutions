"""
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
"""
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = dict()
        ind1 =  ind2 = 0
        flag = False
        size = len(nums)
        for el in nums:
            d[el] = target-el
        for i in range(len(nums)/2):
            if(nums[i] == nums[size-i-1] and size-i-1 != i):
                if target == 2*nums[i]:
                    flag = True
                    break
        for i in range(len(nums)):
            if target-nums[i] in d.keys() and target != 2*nums[i]:
                ind1 = i
                break
            elif target-nums[i] in d.keys() and flag:
                ind1 = i
                break
        for i in range(ind1+1, len(nums)):
            if target-nums[ind1] == nums[i]:
                ind2 = i
                break
        res = [ind1, ind2]
        return res