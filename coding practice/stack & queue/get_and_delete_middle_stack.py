class Node:
    def __init__(self, value):
        self.data = value
        self.prev = None
        self.next = None

class Stack:
    def __init__(self):
        self.top = None
        self.mid = None
        self.count = 0

    def push(self, value):
        temp_node = Node(value)
        if self.count == 0:
            # new node created
            self.top=temp_node
            self.mid=temp_node
            self.count+=1
        else:
            if self.count%2==0:
                self.top.next=temp_node
                temp_node.prev=self.top
                self.top = self.top.next
                self.mid=self.mid.next
                self.count+=1
            else:
                self.top.next=temp_node
                temp_node.prev=self.top
                self.top = self.top.next
                self.count+=1

    def isEmpty(self):
        return self.count==0

    def pop(self):
        if self.isEmpty():
            return -1
        if self.count==1:
            ele=self.top.data
            self.top = None
            self.mid = None
            self.count = 0
            return ele
        elif self.count%2!=0:
            # decrement mid pointer also
            ele=self.top.data
            self.top=self.top.prev
            self.top.next=None
            self.mid=self.mid.prev
            self.count-=1
            return ele
        else:
            ele=self.top.data
            self.top=self.top.prev
            self.top.next=None
            self.count-=1
            return ele

    def showStack(self):
        # top to bottom
        topPtr = self.top
        print("Top to Bottom | TOP =>", end=" ")
        while topPtr:
            print(topPtr.data, end=" ")
            topPtr = topPtr.prev

    def getMiddle(self):
        if self.count == 0:
            return -1
        return self.mid.data

    def deleteMiddle(self):
        if self.count == 0:
            return

        elif self.count == 1:
            self.top = None
            self.mid = None
            self.count = 0

        elif self.count%2!=0:
            prev_node_of_middle = self.mid.prev
            next_node_of_middle = self.mid.next
            self.mid = self.mid.prev
            prev_node_of_middle.next=next_node_of_middle
            next_node_of_middle.prev=prev_node_of_middle
            self.count -= 1

        else:
            prev_node_of_middle = self.mid.prev
            next_node_of_middle = self.mid.next
            self.mid = self.mid.next
            prev_node_of_middle.next=next_node_of_middle
            next_node_of_middle.prev=prev_node_of_middle
            self.count -= 1

if __name__=="__main__":
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.showStack()
    print(f"\nMiddle element of the stack: {stack.getMiddle()}")
    print(f"\nPopped element: {stack.pop()}")
    print(f"\nMiddle element of the stack: {stack.getMiddle()}")
    stack.push(4)
    stack.push(5)
    stack.push(6)
    stack.push(7)
    stack.showStack()
    print(f"\nMiddle element of the stack after consecutive pushes: {stack.getMiddle()}")
    stack.deleteMiddle()
    stack.showStack()
    print(f"\nNew middle element of the stack: {stack.getMiddle()}")