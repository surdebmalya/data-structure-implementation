""" 
Question: 
https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

Easy
"""

def partition(arr):
    if len(arr)==0 or len(arr)==1:
        return
    next_positive_change_index = -1
    for index in range(len(arr)):
        if arr[index] >= 0 and next_positive_change_index == -1: # zero considered as positive
            next_positive_change_index = index 
        elif arr[index] < 0:
            if next_positive_change_index != -1:
                #swap
                temp = arr[next_positive_change_index]
                arr[next_positive_change_index] = arr[index]
                arr[index] = temp
                next_positive_change_index += 1

def main():
    arr = list(map(int, input().rstrip().split()))
    partition(arr)
    print(arr)

if __name__=="__main__":
    main()