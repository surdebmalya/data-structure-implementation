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

def main():
    # taking input
    arr = list(map(int, input().rstrip().split()))
    # assuming the array is sorted in ascending order
    key = int(input())
    start = 0
    end = len(arr) - 1
    result = binary_search(arr, key, start, end)
    if result == -1:
        print(f"The Key Isn't Present")
    else:
        print(f"The Key Is Present On The Index {result}")

if __name__=="__main__":
    main()