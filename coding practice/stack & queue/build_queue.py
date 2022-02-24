class Queue:
    def __init__(self):
        self.queue = []

    def isEmpty(self):
        if len(self.queue)==0:
            return True
        return False

    def enqueue(self, value):
        self.queue.append(value)

    def dequeue(self):
        if self.isEmpty():
            return -1
        else:
            ele = self.queue[0]
            self.queue = self.queue[1:]
            return ele
    
    def showQueue(self):
        print(self.queue)

if __name__=="__main__":
    q = Queue()
    q.enqueue(5)
    q.enqueue(7)
    q.enqueue(9)
    q.showQueue()
    print(f"Dequeued Element: {q.dequeue()}")
    q.showQueue()