def insertion_sort(arr):
    length = len(arr)
    if length == 0 or length == 1:
        return
    for index in range(1, length):
        current = arr[index]
        for sub_index in range(index-1, -1, -1):
            if arr[sub_index] <= current:
                arr[sub_index] = current
                break
            arr[sub_index + 1] = arr[sub_index]
        else:
            arr[0] = current
    return

if __name__=="__main__":
    arr = [9, 5, 0, -1, 5]
    insertion_sort(arr)
    print(f"Sorted Array: {arr}")