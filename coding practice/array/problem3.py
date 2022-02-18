"""
Question:
https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1/
"""

def getMinMax(a, n):
    minimum = a[0]
    maximum = a[0]
    if n==1:
        return [minimum, maximum]
    else:
        for i in range(1, n):
            current = a[i]
            if current < minimum:
                minimum = current
            elif current > maximum:
                maximum = current
        return [minimum, maximum]
    

#{ 
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        
        product = getMinMax(a, n)
        print(product[0], end=" ")
        print(product[1])

        T -= 1


if __name__ == "__main__":
    main()



# } Driver Code Ends
