"""
Question:
https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#

Medium
"""
#User function Template for python3
'''
class Node:
    def __init__(self, d):
        self.data=d
        self.next=None
        self.bottom=None
'''

def flatten(root):
    #Your code here
    if root is None or root.next is None:
        return root
    N = 0
    head = root
    while head.next is not None:
        N += 1
        head = head.next
    N+=1
    
    # 5 7 8 10 19 20 22 28 30 35 40 45 50
    starting_of_head2 = root.next
    for i in range(1, N):
        head2_next = starting_of_head2
        if root.data<=head2_next.data:
            current = root
            head = root
            head1_next = root.bottom
        else:
            current = head2_next
            head = head2_next
            head1_next = root
            head2_next = head2_next.bottom
        while ((head1_next is not None) and (head2_next is not None)):
            if head1_next.data<=head2_next.data:
                current.bottom=head1_next
                current=current.bottom
                head1_next=head1_next.bottom
            else:
                current.bottom=head2_next
                current=current.bottom
                head2_next=head2_next.bottom
        if head1_next is not None:
            current.bottom = head1_next
        else:
            current.bottom = head2_next
        starting_of_head2 = starting_of_head2.next
        root = head
        
    return root

#{ 
#  Driver Code Starts
#Initial Template for Python 3

class Node:
    def __init__(self, d):
        self.data=d
        self.next=None
        self.bottom=None
        
        

def printList(node):
    while(node is not None):
        print(node.data,end=" ")
        node=node.bottom
        
    print()


if __name__=="__main__":
    t=int(input())
    while(t>0):
        head=None
        N=int(input())
        arr=[]
        
        arr=[int(x) for x in input().strip().split()]
        temp=None
        tempB=None
        pre=None
        preB=None
        
        flag=1
        flag1=1
        listo=[int(x) for x in input().strip().split()]
        it=0
        for i in range(N):
            m=arr[i]
            m-=1
            a1=listo[it]
            it+=1
            temp=Node(a1)
            if flag is 1:
                head=temp
                pre=temp
                flag=0
                flag1=1
            else:
                pre.next=temp
                pre=temp
                flag1=1
                
            for j in range(m):
                a=listo[it]
                it+=1
                tempB=Node(a)
                if flag1 is 1:
                    temp.bottom=tempB
                    preB=tempB
                    flag1=0
                else:
                    preB.bottom=tempB
                    preB=tempB
        root=flatten(head)
        printList(root)
        
        t-=1
            
# } Driver Code Ends