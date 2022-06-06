// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

// Medium

class Solution {
private:
    int findLength(ListNode *root) {
        int count = 0;
        while (root != NULL) {
            count++;
            root = root->next;
        }
        return count;
    }

public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        vector<int> result;
        int length = findLength(head);
        int flag = 1;
        int prev = head->val;
        while (head != NULL) {
            if (flag == 1 or flag == length) {
                prev = head->val;
                head = head->next;
                flag++;
            } else {
                int curr = head->val;
                if ((curr > prev and curr > head->next->val) or (curr < prev and curr < head->next->val)) {
                    result.push_back(flag); // we have to note the index or the position
                }
                prev = head->val;
                head = head->next;
                flag++;
            }
        }
        if (result.size() == 0 or result.size() == 1)
            return {-1, -1};
        else {
            sort(result.begin(), result.end());
            int maxi = result[result.size() - 1] - result[0];
            int mini = result[1] - result[0];
            for (int i = 2; i < result.size(); i++) {
                int curr = result[i] - result[i - 1];
                if (curr < mini)
                    mini = curr;
            }
            return {mini, maxi};
        }
    }
};