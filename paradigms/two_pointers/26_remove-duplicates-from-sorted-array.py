# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
26_remove_duplicates_from_sorted_array on LeetCode

Solution: 
    - Two pointers 
'''


class Solution():
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # e.g. 00122

        if not nums:
            return 0

        slow = 0
        for fast in range(1, len(nums)):
            if nums[slow] != nums[fast]:
                slow += 1
                nums[slow] = nums[fast]

        return slow+1 # edge case
        

def main():

    s = Solution()

    inputs = [[],
              [2],
              [0,0,1,2,2],
              [0,4,4,4,5],
              [0,4,5,5,5],
              [0,4,5,6,7]]
                
    answers = [0, 1, 3, 3, 3, 5]
    for inp, ans in zip(inputs, answers):
        oup = s.removeDuplicates(inp)
        print(oup)
        print(ans)
        print(oup == ans)

if __name__ == '__main__':
    main()
