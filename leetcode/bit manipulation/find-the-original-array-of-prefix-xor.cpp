class Solution {
public:
    vector<int> findArray(vector<int>& arr) {
        vector<int> res(arr.size(), 0);
        res[0] = arr[0];
        int curr = res[0];
        for(int i=1; i<res.size(); i++) {
            res[i] = curr ^ arr[i];
            curr = arr[i];
        }
        return res;
    }
};