class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // cheak whether all elements are negative or not
        bool allNeg = true;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>=0) {
                allNeg = false;
                break;
            }
        }
        if(allNeg==true) {
            // return the maximum negative value
            int res=INT_MIN;
            for(int i=0; i<nums.size(); i++) {
                res = max(res, nums[i]);
            }
            return res;
        }
        // checking all positive
        bool allPos = true;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]<0) {
                allPos=false;
                break;
            }
        }
        if(allPos==true) {
            int res = 0;
            for(int i=0; i<nums.size(); i++) res += nums[i];
            return res;
        }
        // applying modified kaden's algorithm
        int sum1 = INT_MIN;
        int currSum1 = 0;
        for(int i=0; i<nums.size(); i++) {
            currSum1 += nums[i];
            currSum1 = max(currSum1, nums[i]);
            sum1 = max(sum1, currSum1);
        }
        for(int i=0; i<nums.size(); i++) {
            nums[i] = -nums[i];
        }
        int sum = INT_MIN;
        int currSum = 0;
        for(int i=0; i<nums.size(); i++) {
            currSum += nums[i];
            currSum = max(currSum, nums[i]);
            sum = max(sum, currSum);
        }
        int totalSum=0;
        for(int i=0; i<nums.size(); i++) totalSum += nums[i];

        int tempRes = -totalSum - (-sum);

        return max(sum1, tempRes);
    }
};