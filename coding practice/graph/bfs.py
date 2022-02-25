class Queue:
    def __init__(self):
        self.queue = []
    def enqueue(self, value):
        self.queue.append(value)
    def isEmpty(self):
        if len(self.queue)==0:
            return True
        return False
    def dequeue(self):
        if self.isEmpty():
            return -1
        ele = self.queue[0]
        self.queue = self.queue[1:]
        return ele
    def size(self):
        return len(self.queue)

def bfs(graph, starting_vertex):
    q = Queue()
    visited = set()
    q.enqueue(starting_vertex)
    print(starting_vertex, end=" ")
    visited.add(starting_vertex)
    while q.size()!=0:
        current_vertex = q.dequeue()
        adjacency_list = graph[current_vertex]
        for vertex in adjacency_list:
            if vertex not in visited: # O(1) because of set lookup
                q.enqueue(vertex)
                print(vertex, end=" ")
                visited.add(vertex)

if __name__ == "__main__":
    adjacency_list = {
        '5': ['3', '7'],
        '3': ['2', '4'],
        '7': ['8'],
        '2': [],
        '4': ['8'],
        '8': []
    }
    bfs(adjacency_list, '5') 
