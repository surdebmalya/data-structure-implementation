// https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

// Medium

int mod = (int)1e9+7;
int f(vector<int>&arr, int index, int sum, vector<vector<int>>& dp) {
    if(index==0) {
        if(sum==0 and arr[0]==0) return 2;
        if(sum==0 or arr[0]==sum) return 1;
        else return 0;
    }
    if(dp[index][sum]!=-1) return dp[index][sum];
    int take=0, skip=0;
    if(arr[index]<=sum) 
        take = f(arr, index-1, sum-arr[index], dp);
    skip = f(arr, index-1, sum, dp);
    return dp[index][sum]=(take+skip)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int total=0;
    for(int i=0; i<n; i++) total+=arr[i];
    
    if(((total-d)%2) or (total-d)<0) return 0;
    int k = (total-d)/2;
    vector<vector<int>>dp(n, vector<int>(k+1, -1));
    return f(arr, n-1, k, dp)%mod;
}


