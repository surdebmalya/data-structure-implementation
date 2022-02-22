"""
Making a stack from scratch
"""
class Stack:
    """
    If the stack is empty and if pop() is called then,
    it will return -1
    """
    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)

    def isEmpty(self):
        if len(self.stack) == 0:
            return True
        else:
            return False

    def peak(self):
        if not(self.isEmpty()):
            print(f"Top of the stack value is: {self.stack[-1]}")
        else:
            print(f"The stack is empty")

    def pop(self):
        if not(self.isEmpty()):
            return self.stack.pop()
        else:
            return -1

    def showStack(self):
        print(self.stack)

if __name__=="__main__":
    s = Stack()
    s.push(5)
    s.push(1)
    s.push(3)
    s.showStack()
    s.peak()
    print(f"Popped value is: {s.pop()}")
    s.showStack()