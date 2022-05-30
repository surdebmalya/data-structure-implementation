// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

// Hard

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1; 
        while(l<r) {
            int mid=(l+r)/2;
            if(nums[mid]>nums[r]) l=mid+1;
            else {
                if(nums[mid]!=nums[r]) r=mid;
                else r=r-1;
            }
        }
        return nums[l];
    }
};