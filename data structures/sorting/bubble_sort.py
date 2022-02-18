def bubble_sort(arr):
    length = len(arr)
    if length == 0 or length == 1:
        return
    for outer_index in range(0, length):
        minimum = arr[outer_index]
        index = outer_index
        for inner_index in range(outer_index, length):
            if arr[inner_index] < minimum:
                minimum = arr[inner_index]
                index = inner_index
        arr[index] = arr[outer_index]
        arr[outer_index] = minimum

if __name__=="__main__":
    arr = [9, 5, 0, -1, 5]
    # arr = [8, -52, 0, 56, 1, 2, 2, 88, 4, 6]
    bubble_sort(arr)
    print(f"Sorted Array: {arr}")