// https://leetcode.com/problems/kth-largest-element-in-an-array/

// Medium

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        if (nums.size() == 1)
            return nums[0];
        int askingIndex = nums.size() - k;
        int start = 0, end = nums.size() - 1;
        int pivot;
        while (start <= end) {
            int mid = (start + end) / 2;
            swap(nums[mid], nums[start]);
            int pivot = nums[start];
            int ptr = start + 1;
            for (int i = start + 1; i <= end; i++) {
                if (nums[i] <= pivot) {
                    swap(nums[i], nums[ptr]);
                    ptr++;
                }
            }
            ptr--;
            int index = ptr;
            swap(nums[start], nums[index]);
            if (index == askingIndex)
                return nums[index];
            else if (index < askingIndex)
                start = index + 1;
            else
                end = index - 1;
        }
        return 0;
    }
};