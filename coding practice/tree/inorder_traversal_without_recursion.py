class Node:
    def __init__(self, value):
        self.left = None
        self.data = value
        self.right = None

class Stack:
    def __init__(self):
        self.stack = []
    def push(self, value):
        self.stack.append(value)
    def isEmpty(self):
        if len(self.stack) == 0:
            return True
        return False
    def pop(self):
        if self.isEmpty():
            return -1
        return self.stack.pop()

class Solution:
    def inorder_traversal_without_recursion(self, root):
        res = []
        call_stack = Stack()
        call_stack.push(root)
        while not(call_stack.isEmpty()):
            current_node = call_stack.pop()
            res.append(current_node.data)
            if current_node.right is not None:
                call_stack.push(current_node.right)
            if current_node.left is not None:
                call_stack.push(current_node.left)
        return res

if __name__ == '__main__':
    root = Node(1)
    root.left = Node(2)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right = Node(3)

    s = Solution()
    res = s.inorder_traversal_without_recursion(root)
    for i in res:
        print(i, end=" ")