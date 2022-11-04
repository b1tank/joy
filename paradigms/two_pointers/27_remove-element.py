# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
27_remove_element on LeetCode

Solution: 
    - __
'''


class Solution():
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """

        # e.g. 514134, 4 => 5113

        if not nums:
            return 0
        
        slow = 0
        for fast in range(len(nums)):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
        return slow
        

def main():

    s = Solution()

    inputs = [[[], 1],
              [[0], 2],
              [[2], 2],
              [[0,1,2,3,4,4,4,5], 4],
              [[0,0,5,3,4,5], 3],
              [[7,2,9,9,7,2,9,9], 2],
              [[3,4,9,2,2,4,8,3,2], 4]]
                
    answers = [0, 1, 0, 5, 5, 6, 7]
    test_res = []
    for inp, ans in zip(inputs, answers):
        oup = s.removeElement(inp[0], inp[1])
        print(oup)
        print(ans)
        print(oup == ans)
        test_res.append(oup == ans)
    if all(tr for tr in test_res):
        print('All tests passed!')
    else:
        print('Some tests failed!')

if __name__ == '__main__':
    main()
