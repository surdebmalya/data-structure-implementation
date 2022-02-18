def binary_search(arr, key, start, end):
    mid = (start + end) // 2
    if start>end:
        return -1
    if arr[mid] == key:
        return mid
    elif arr[mid] < key:
        start = mid + 1
        return binary_search(arr, key, start, end)
    else:
        end = mid - 1
        return binary_search(arr, key, start, end)

if __name__=="__main__":
    arr = [-1, 1, 9, 10, 55, 101]
    key = 55
    start = 0
    end = len(arr) - 1
    result = binary_search(arr, key, start, end)
    print(f"The Key Is Present On The Index {result}")