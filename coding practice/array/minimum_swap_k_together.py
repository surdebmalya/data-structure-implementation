"""
Question:
https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1#

Medium
"""
#User function Template for python3

def minSwap (arr, n, k) : 
    #Complete the function
    window_size = 0
    for i in arr:
        if i<=k:
            window_size+=1
    if window_size==0:
        return 0
    init_count = 0
    for i in range(window_size):
        if arr[i]<=k:
            init_count+=1
    number_of_swaps = window_size-init_count
    answer = number_of_swaps
    if n==window_size:
        return answer
    for i in range(window_size, n):
        if arr[i-window_size]<=k:
            init_count-=1
        if arr[i]<=k:
            init_count+=1
        number_of_swaps = window_size-init_count
        if number_of_swaps<answer:
            answer = number_of_swaps
    return answer
            
#{ 
#  Driver Code Starts
#Initial Template for Python 3

for _ in range(0,int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    k = int(input())
    ans = minSwap(arr, n, k)
    print(ans)
    





# } Driver Code Ends