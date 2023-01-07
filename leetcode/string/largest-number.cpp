class Solution {
public:
    static bool cmp(string a, string b) {
        if(a+b>b+a) return true;
        else return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int i=0; i<nums.size(); i++) {
            arr.push_back(to_string(nums[i]));
        }
        sort(arr.begin(), arr.end(), cmp);
        string res;
        for(int i=0; i<arr.size(); i++) {
            res += arr[i];
        }
        while(res.size()!=0 and res[0]=='0') {
            res.erase(res.begin());
        }
        if(res.size()==0) res = "0";
        return res;
    }
};