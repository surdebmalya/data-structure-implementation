def merge(arr, start, mid, end):
    L = []
    R = []
    for i in range(start, mid + 1):
        L.append(arr[i])
    for i in range(mid + 1, end + 1):
        R.append(arr[i])
    # print(L)
    # print(R)
    ptr_L = 0
    ptr_R = 0
    index_starting = start
    flag = True
    while flag:
        if L[ptr_L]<R[ptr_R]:
            arr[index_starting] = L[ptr_L]
            index_starting += 1
            ptr_L += 1
            if len(L) == ptr_L:
                # put all right array value as it is
                for j in range(ptr_R, len(R)):
                    arr[index_starting] = R[ptr_R]
                    ptr_R += 1
                    index_starting += 1
                flag = False
        else:
            arr[index_starting] = R[ptr_R]
            index_starting += 1
            ptr_R += 1
            if len(R) == ptr_R:
                # put all left array value as it is
                for j in range(ptr_L, len(L)):
                    arr[index_starting] = L[ptr_L]
                    ptr_L += 1
                    index_starting += 1
                flag = False
    return

def merge_sort(arr, start, end):
    # divide
    if start < end:
        mid = (start + end)//2
        merge_sort(arr, start, mid)
        merge_sort(arr, mid + 1, end)
        
        # merging
        merge(arr, start, mid, end)

if __name__=="__main__":
    # arr = [9, 5, 0, -1, 5]
    arr = [8, -52, 0, 56, 1, 2, 2, 88, 4, 6]
    start = 0
    end = len(arr) - 1
    merge_sort(arr, start, end)
    print(f"Sorted Array: {arr}")