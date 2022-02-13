def linear_search(arr, key):
    for index in range(len(arr)):
        if key == arr[index]:
            return index
    return -1

def main():
    # taking input
    arr = list(map(int, input().rstrip().split()))
    key = int(input())
    result = linear_search(arr, key)
    if result == -1:
        print(f"The Key Isn't Present")
    else:
        print(f"The Key Is Present On The Index {result}")

if __name__=="__main__":
    main()