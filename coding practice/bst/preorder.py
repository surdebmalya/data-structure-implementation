from typing import Any, Union, Optional


class Node:
    def __init__(self, value: Any):
        self.val: Any = value
        self.left: Optional["Node"] = None
        self.right: Optional["Node"] = None

def preorder_traversal(root: Node):
    # root -> left -> right
    if root is None:
        return
    print(root.val, end=" ")
    preorder_traversal(root.left)
    preorder_traversal(root.right)

if __name__ == '__main__':
    root: Node = Node(10)
    root.left = Node(5)
    root.left.left = Node(1)
    root.left.right = Node(7)
    root.right = Node(40)
    root.right.right = Node(50)

    preorder_traversal(root)
