"""
Question:
https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

Medium
"""

#User function Template for python3
import random

class Solution:
    def partition(self, arr, l, r, k_index):
        # randomized povt selection
        pivot_index = random.randint(l,r)
        # swap l and pivot_index
        temp = arr[pivot_index]
        arr[pivot_index] = arr[l]
        arr[l] = temp
        pivot_index = l
        pivot = arr[pivot_index]
        smaller_found = False
        swap_index = -1
        for index in range(l+1, r+1):
            if (arr[index] > pivot) and (swap_index == -1):
                swap_index = index
            elif (arr[index]<=pivot):
                smaller_found = True
                if (swap_index != -1):
                    # swap arr[index] with swap_index element and incr swap_index
                    temp = arr[index]
                    arr[index] = arr[swap_index]
                    arr[swap_index] = temp
                    swap_index += 1
        if smaller_found:
            if swap_index==-1:
                temp = arr[r]
                arr[r] = pivot
                arr[pivot_index] = temp
                pivot_index = r
            else:
                swap_index -= 1
                temp = arr[swap_index]
                arr[swap_index] = pivot
                arr[pivot_index] = temp
                pivot_index = swap_index
        if pivot_index == k_index:
            return arr[pivot_index]
        elif (pivot_index < k_index):
            return self.partition(arr, pivot_index+1, r, k_index)
        else:
            return self.partition(arr, l, pivot_index, k_index)
                
    def kthSmallest(self, arr, l, r, k):
        '''
        arr : given array
        l : starting index of the array i.e 0
        r : ending index of the array i.e size-1
        k : find kth smallest element and return using this function
        '''
        length = len(arr)
        if length == 1:
            return arr[0]
        k_index = k - 1
        result = self.partition(arr, l, r, k_index)
        return result

#{ 
#  Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__': 
    import random 
    t=int(input())
    for tcs in range(t):
        n=int(input())
        arr=list(map(int,input().strip().split()))
        k=int(input())
        ob=Solution()
        print(ob.kthSmallest(arr, 0, n-1, k))
        
# } Driver Code Ends