class Solution(object):
    def maxTwoEvents(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """

        # Sorting events based on starting times 
        events.sort()

        # Creating a list for suffix_maximum
        n = len(events)
        suffix_maximum = [0]*n
        suffix_maximum[n-1] = events[n-1][2]
        for i in range(n-2,-1,-1):
            suffix_maximum[i] = max(events[i][2],suffix_maximum[i+1])

        #Iterating intervals
        maximum_sum = suffix_maximum[0]
        for i in range(n-1):
            low = i+1
            high = n-1
            target = events[i][1]+1

            while high-low > 1:
                mid = (low + high)//2
                if events[mid][0] >= target:
                    high = mid
                else:
                    low = mid

            if events[low][0] >= target:
                maximum_sum = max(maximum_sum,events[i][2]+suffix_maximum[low])
            elif events[high][0] >= target:
                maximum_sum = max(maximum_sum,events[i][2] + suffix_maximum[high])

        return maximum_sum

        
        