class Solution(object):
    def maxSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        MOD = 10**9 + 7
        cnt = [0] * 31
        
        # Count the frequency of set bits at each position
        for x in nums:
            for i in range(31):
                if (x >> i) & 1:
                    cnt[i] += 1
                    
        ans = 0
        # Greedily construct k numbers from highest to lowest bits
        for _ in range(k):
            x = 0
            for i in range(30, -1, -1):
                if cnt[i] > 0:
                    x |= (1 << i)
                    cnt[i] -= 1
            ans = (ans + x * x) % MOD
            
        return ans
//Author:Lishanth
