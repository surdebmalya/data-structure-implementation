"""
Question:
https://practice.geeksforgeeks.org/problems/lru-cache/1#

Medium
"""
import sys

class LRUCache:
      
    #Constructor for initializing the cache capacity with the given value.  
    def __init__(self,cap):
        self.cache = {} # <key, value, time> => key: [value, time]
        self.capacity = cap
        self.time = 0 # measuring global timing
    def get(self, key):
        try:
            result = self.cache[key][0]
            self.time += 1
            self.cache[key][1] = self.time
        except:
            result = -1
        return result
    def set(self, key, value):
        try:
            actual_value = self.cache[key][0]
            # key already present
            """
            Updated its value and time
            """
            self.cache[key][0] = value
            self.time += 1
            self.cache[key][1] = self.time
        except:
            # key doesn't present # key: [value, time]
            if self.capacity > 0:
                # cache has more free spaces
                self.cache[key] = [-1, -1]
                self.cache[key][0] = value
                self.time += 1
                self.cache[key][1] = self.time
                self.capacity -= 1
            else:
                # cache doesn't have any more free spaces
                """
                LRU cache
                - see the timings, and replace that block which has minimum timing
                """
                MIN = sys.maxsize
                key_to_be_replaced = -1
                for key_current in self.cache.keys():
                    if self.cache[key_current][1] < MIN:
                        MIN = self.cache[key_current][1]
                        key_to_be_replaced = key_current
                del self.cache[key_to_be_replaced]
                self.cache[key] = [-1, -1]
                self.cache[key][0] = value
                self.time += 1
                self.cache[key][1] = self.time
        
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        cap = int(input())  # capacity of the cache
        qry=int(input())  #number of queries
        a = list(map(str, input().strip().split()))  # parent child info in list
        
        lru=LRUCache(cap)
        
       
        i=0
        q=1
        while q<=qry:
            qtyp=a[i]
            
            if qtyp=='SET':
                lru.set(int(a[i+1]),int(a[i+2]))
                i+=3
            elif qtyp=='GET':
                print(lru.get(int(a[i+1])),end=' ')
                i+=2
            q+=1
        print()
# } Driver Code Ends