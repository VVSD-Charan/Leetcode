class Solution(object):
    def continuousSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        hash_map = defaultdict(int)
        low = 0
        high = 0
        total = 0

        while high < len(nums):
            hash_map[nums[high]]+=1
            while(max(hash_map.keys()) - min(hash_map.keys()) > 2):
                hash_map[nums[low]] -= 1
                if hash_map[nums[low]]==0:
                    del hash_map[nums[low]]
                low += 1
            total += (high-low+1)
            high += 1
        return total
        