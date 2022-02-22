"""
Question:
https://practice.geeksforgeeks.org/problems/reverse-a-string/1

Easy
"""

def reverseWord(s):
    #your code here
    l=[]
    for i in s:
        l.append(i)
    l.reverse()
    s=''
    for i in l:
        s+=i
    return s

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while(t>0):
        s = input()
        print(reverseWord(s))
        t = t-1

# } Driver Code Ends
