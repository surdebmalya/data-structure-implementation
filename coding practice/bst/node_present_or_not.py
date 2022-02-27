class Node:
    def __init__(self, value):
        self.lptr = None
        self.value = value
        self.rptr = None

class Solution:
    def node_present_or_not(self, root, value):
        if root is None:
            return False
        elif root.value == value:
            return True
        elif root.value < value:
            return self.node_present_or_not(root.rptr, value)
        else:
            return self.node_present_or_not(root.lptr, value)
    
if __name__ =="__main__":
    # creating a BST
    root = Node(8)
    root.lptr = Node(3)
    root.lptr.lptr = Node(1)
    root.lptr.rptr = Node(6)
    root.lptr.rptr.lptr = Node(4)
    root.lptr.rptr.rptr = Node(7)
    root.rptr = Node(10)
    root.rptr.rptr = Node(14)
    root.rptr.rptr.lptr = Node(13)

    sln = Solution()
    # value = 14
    value = 15
    if sln.node_present_or_not(root, value):
        print(f"{value} present in the given tree.")
    else:
        print(f"{value} not present in the given tree")