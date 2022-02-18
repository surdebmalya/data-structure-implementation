def linear_search(arr, key):
    for index in range(len(arr)):
        if key == arr[index]:
            return index
    return -1

if __name__=="__main__":
    arr = [9, 5, 0, -1, 5]
    key = 5
    result = linear_search(arr, key)
    print(f"The Key Is Present On The Index {result}")