#User function Template for python3

def rotate(arr, n):
    if n==0 or n==1:
        return
    temp = arr[0]
    arr[0] = arr[-1]
    for i in range(1, n):
        current = arr[i]
        arr[i] = temp
        temp = current


#{ 
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        rotate(a, n)
        print(*a)

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
