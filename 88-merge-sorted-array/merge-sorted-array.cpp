class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        //Using concept of shell sort
        int gap = (n+m)/2 + (n+m)%2;

        while(gap)
        {
            int lo = 0;
            int hi = gap;

            while(hi < m+n)
            {
                if(lo<m && hi>=m && nums1[lo]>nums2[hi-m])
                {
                    swap(nums1[lo],nums2[hi-m]);
                }
                else if(hi<m && nums1[lo]>nums1[hi])
                {
                    swap(nums1[lo],nums1[hi]);
                }
                else if(lo>=m && nums2[lo-m]>nums2[hi-m])
                {
                    swap(nums2[lo-m],nums2[hi-m]);
                }
                lo++;   hi++;
            }

            if(gap==1)break;
            gap = (gap/2)+(gap%2);
        }    

         for(int i=m;i<n+m;i++)
        {
            nums1[i]=nums2[i-m];
        }
    }
};