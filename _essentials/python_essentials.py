## Python 3 essentials for tech coding interview

## Reference
# Python: https://medium.com/@ratulsaha/preparing-for-programming-interview-as-a-phd-student-with-python-5f8af8b40d5f
# BFS/DFS: https://eddmann.com/posts/depth-first-search-and-breadth-first-search-in-python/
# Graph/BFS/Dijkstra/A*: https://www.redblobgames.com/pathfinding/a-star/implementation.html


## String
a = 'ab cbe'
len(a)
for c in a:
    print(c)
# only difference between find() and index()
a.find('b') # => -1 on failure
a.index('b') # => ValueError on failure
a.rfind('b')
a.rindex('b')
a.strip('e')
a.rstrip('e')
a.split()
a.split('c')
'/'.join(['a', 'b', 'c'])
'a = {}'.format(a)
'a'.isalnum() # alphanumeric
# isalpha, isascii, isdecimal, isdigit, islower, isnumeric, isspace, isupper
'a'.lower() # => new copy
'a'.upper()
a.replace('b', '') # 'ac'; remove certain characters

# Python string formatting good reference: [Python String Formatting Best Practices – Real Python](https://realpython.com/python-string-formatting/)
name = 'b1tank'
age = 13
'My name is {name} and my age is 0x{age:x}'.format(name=name, age=age)
f'My name is {name} and my age is {3 + 10:x}' # formatted string literal
f'My name is {name} and my age is {3 + 10:#x}' # formatted string literal
f'{{3 + 10}}' # '{3 + 10}'

# char to int, int to char
ord('a')
chr(ord('a') + 1) # 'b'


## Number
float('inf'), float('-inf')
import sys
from tkinter.messagebox import YES
int_max = sys.maxsize # 2**63-1 (64-bit computer) or 2**31-1 (32-bit computer)
int_min = -sys.maxsize - 1 # -2**63 (64-bit computer) or -2**31 (32-bit computer)
# INT_MAX or INT_MIN in C++/Java

# math
2**8
abs(-1)

# random number
import random       
random.randint(1, 5) # random int from 1-5 (both inclusive)
# >>> 2
random.random() # random float from 0-1
# >>> 0.7419323241014614
random.choice([1,2,3,4]) # return random VALUE in the list
# >>> 3


## Conditional check
a = [1, 2]
b = a
c = list(a)
a is b # True
a is c # False
a == b # True
a == c # True

a is None
a is not None

a != b
a in d
a not in d


## Loops
counter = 0
while counter <= 5:
    print(counter)
    counter += 1
else:
    print('loop exited normally')
    # Output: 0 1 2 3 4 5 loop exited normally

for i in range(5):
    print(i)
    if i > 2:
        print('break the loop')
        break
else:
    print('loop exited normally')
    # Output: 0 1 2 3 4

li = [1, 3, 6]
for i, val in enumerate(li):
    print('The value at index {} is {}'.format(i, val))


## itertools
# itertools.chain
import itertools
list2d = [[1,2,3], [4,5,6], [7], [8,9]]
merged1 = tuple(itertools.chain.from_iterable(list2d)) # (1, 2, 3, 4, 5, 6, 7, 8, 9)
merged2 = tuple(itertools.chain(*list2d)) # (1, 2, 3, 4, 5, 6, 7, 8, 9)


## Data structures

# List
# List traversal
range(start, stop, hop)
range(n) # [0,1,...,n-1]
range(1,n) # [1,...,n-1]
range(1,n,2) # [1,3,5,...,n-1] if n is even, or [1,3,5,...,n-2] if n is odd
range(n,-1,-1) # [n,n-1,n-2,...,0]
range(len(arr)) # Provides indices of an array arr
range(len(arr)-1,-1,-1) # Provides indices of arr backwards

# List slicing
arr = [1,2,3,4]
# arr[w:s] # Wait w elements, start copy (:), stop before reaching index s
arr[1:] == [2,3,4]
arr[:2] == [1,2]
arr[::2] == [1,3] # 2 is the step
arr[::-1] == [4,3,2,1] # reverse a list (or string)

# List manipulation and comprehension
arr = [1,2,3]

arr.append(4)
arr.extend([5,6])

arr.insert(0, 7) # position, value
arr.insert(len(arr), 8) # equivalent to arr.append(8)
arr.remove(3) # remove first value of 3

arr.index(3) # return index of first value 3
arr.count(3) # count the occurence of value 3

arr.pop(1) # position; return value
arr.pop() # like stack.pop(); return value

arr.sort() # in-place
arr.reverse() # in-place

a.clear() # empty the list

# list comprehension
[str(x) for x in arr] # Output: ['1','2','3']
[str(x) for x in arr if x%2] # Output: ['1','3']
list(map(lambda x: str(x), arr)) # Output: ['1','2','3']; have to manually convert to list in python3. map() is iterable without explicit list conversion

# List as queue
arr = [1,2,3]   
arr.append(x) # queue.push(x)
arr.pop(0) # queue.pop()
arr[0] # queue.peek()

# List as stack
arr = [1,2,3]
arr.append(x) #stack.push(x)
arr.pop() # stack.pop()
arr[-1] # stack.peek()

# Set
s = set()
s = {0, 1, 2}
s.add(4)
ss = {2, 3, 4}
s - ss # {0, 1}
# >= > < <= | & ^
s ^ ss # {0, 1, 3, 4}
s.discard(100) # no error
s.remove(100)  # Error: 100 not in s

# Dict 
d = {}
d = {2:3, 3:4}
d[3] = 'ha'
if 3 in d:
    print('yes')

del d[3]
d.clear() # empty the dict

d.copy() # shallow copy

d.get(k) # d[k] will return Nothing if k not in d

d.pop(k) # return KeyError if k not in d
d.pop(k, default) #  default value is returned if k not in d
d.popitem() # return (2, 3); removes the item that was last inserted into the dictionary

d.keys()
d.values()
for key, val in d.items():
    print('key {} : value {}'.format(key, val))
d.fromkeys()


## Collections

# deque()
from collections import deque

queue = deque([1,2,3])

queue.append(4)
queue.appendleft(0)
queue.popleft()
queue.pop()
queue.extend([3,4])
queue.extendleft([1,2]) # [X,Y,Z] => [2,1,X,Y,Z], NOTE: the series of left appends results in reversing the order of elements in the iterable argument

queue.clear()
queue.count(3)
queue.remove(2) # remove (by value) first number 2; return ValueError if non found
queue.reverse()
queue.rotate(2) # positive => right
queue.rotate(-1)

# Counter()
from collections import Counter
c = Counter('ha') # Counter({'h': 1, 'a': 1})
c = Counter({'red': 4, 'blue': 2})      # a new counter from a mapping
c = Counter(cats=4, dogs=8)             # a new counter from keyword args
c = Counter(['eggs', 'ham'])
c['bacon']                              # count of a missing element is zero
c['sausage'] = 0                        # counter entry with a zero count
del c['sausage']                        # del actually removes the entry

# defaultdict()
# https://docs.python.org/3/library/collections.html#defaultdict-examples
from collections import defaultdict
s = [('yellow', 1), ('blue', 2), ('yellow', 3), ('blue', 4), ('red', 1)]
d = defaultdict(list) # default value for a missing key is an empty 'list' [] (a callable)
for k, v in s:
    d[k].append(v)
d.items() # [('blue', [2, 4]), ('red', [1]), ('yellow', [1, 3])]
ice_cream = defaultdict(lambda: 'Vanilla') # default value for a missing key is 'lambda function' (a callable)
ice_cream['Sarah'] = 'Chunky Monkey'
ice_cream['Abdul'] = 'Butter Pecan'
print(ice_cream['Sarah']) # Chunky Monkey
print(ice_cream['Joe']) # Vanilla (default value)

## LinkedList

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


## Tree

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


## Priority Queue (by default is MIN heap; max-heap for C++)
import heapq

def heapsort(iterable):
    h = []
    for value in iterable:
        heappush(h, value)
    return [heappop(h) for i in range(len(h))]

heapsort([1, 3, 5, 7, 9, 2, 4, 6, 8, 0])
# >>> [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
pq = [(4, 'e'), (8, 'e'), (9, 'e'), (3, 't'), (6, 'y')]
heapsort(pq)
# >>> [(3, 't'), (4, 'e'), (6, 'y'), (8, 'e'), (9, 'e')]

pq = [(0, src)]
heapq.heapify(pq) # if skip this heapify, the subsequent pop will return first value and heapify it some time down the road (it's wrong !!!)

heapq.heappop(pq) # return IndexError if heap is empty
heapq.heappush(pq, (cost, cur_node))
heapq.heappushpop(pq, (cost, cur_node)) # faster than a push + pop
heapq.heapreplace # 'heapq.heappoppush'

heapq.nsmallest(n, li) # li can be vanilla list; for small n, it’s efficient; for large n, use sorted
heapq.nlargest(n, li)

# maintain a fixed-size heap
if len(h) < capacity:
    heapq.heappush(h, thing)
else:
    # Equivalent to a push, then a pop, but faster
    spilled_value = heapq.heappushpop(h, thing)
    do_whatever_with(spilled_value)


## Algorithms

# Sort

s = [2, 3, 1, 5, 0]
sorted(s) # s will NOT change !!!
sorted([3,2,1])
sorted('This is a test string from Andrew'.split(), key=str.lower, reverse=False)
# ['a', 'Andrew', 'from', 'is', 'string', 'test', 'This']

l = [(3, 4), (2, 5), (6, 1)]
l.sort(key=lambda x : x[1], reverse=True)
l # [(2, 5), (3, 4), (6, 1)]

# Binary search

arr, target = [1,2,3,4,5], 4
start, end = 0, len(arr)-1
while start <= end: # or start < end
    mid = start + (end-start)/2 # (end+start)/2 might cause overflow (in JAVA/C++)!
    if arr[mid] == target:
        return mid # The value is found
    else:
        if arr[mid] < target:
            start = mid+1
        else:
            end = mid-1 # or end = mid
return -1 # The value is not found


## Graph

# Adjacency lists
# Unweighted graph
graph = {'A': {'B', 'C'},
         'B': {'A', 'D', 'E'},
         'C': {'A', 'F'},
         'D': {'B'},
         'E': {'B', 'F'},
         'F': {'C', 'E'}}

# Weighted graph
graph = {'A': {('B', 1), ('C', 3)},
         'B': {('A', 9), ('D', 4), ('E', 2)},
         'C': {('A', 21), ('F', 6)},
         'D': {('B', 10)},
         'E': {('B', 6), ('F', 8)},
         'F': {('C', 2), ('E', 5)}}

# Depth first search

# iterative approach (stack)
def dfs(graph, start):
    stack = [start]
    visited = {start}
    while stack:
        cur_node = stack.pop()
        for nei in graph[cur_node]:
            if nei not in visited:
                visited.add(nei)
                stack.append(nei)
    return visited

# recursion approach
def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    for nei in graph[start] - visited:
        dfs(graph, nei, visited)
    return visited

# Breadth first search

from collections import deque

queue = deque([(start, 0)])
visited = {start}
while queue:
    cur_node, depth = queue.popleft()
    if cur_node == target_node: return depth
    for nei in graph[cur_node]: # NOTE: non-existing node can bring KeyError! May need to check 'if node in graph'
        if nei not in visited:
            visited.add(nei)
            queue.append((nei, depth+1))

# Dijkstra algorithm

import heapq

pq = [(0, start)]
heap.heapify(pq)
while pq:
    cur_cost, cur_node = heapq.heappop(pq)
    if cur_node == target_node:
        return cur_cost
    for nei, weight in cur_node.neighbors():
        nei_cost = cur_cost + weight
        heapq.heappush(pq, (nei_cost, nei))

# A* algorithm

import heapq

def heuristic(a, b):
    (x1, y1) = a
    (x2, y2) = b
    return abs(x1 - x2) + abs(y1 - y2)

def a_star_search(graph, start, target_node):
    pq = [(0, start)]
    
    came_from = {}
    cost = {}
			
    came_from[start] = None
    cost[start] = 0
    
    while pq:
        priority, cur_node = heapq.heappop(pq)
        
        if cur_node == target_node:
            break
        
        for nei, weight in graph[cur_node]:
            new_cost = cost[cur_node] + weight
            if nei not in cost or new_cost < cost[nei]:
                cost[nei] = new_cost
                priority = new_cost + heuristic(nei, target_node)
                heapq.heappush(pq, (priority, nei))
                came_from[nei] = cur_node
    
    return came_from, cost


## Other useful tips

# object attr check
l = TreeNode(3)
hasattr(l, 'val') # a built-in binary function that checks whether object x has an attribute x.foo

# Python list will be modified (in place) inside the function, but values won’t 
a = [1,2,3]
def modify(li):
    li[0] = 100
modify(a)
a # [100, 2, 3]

# lambda function
f = lambda x, y : x + 2 * y
f(3, 4) # 3 + 2 * 4 = 11
l = list(map(lambda x:int(x), '1234')) # [1, 2, 3, 4]

# exception handling
try:
    print(x)
except NameError:
    print('Variable x is not defined')
except:
    print('Something else went wrong')
else:
    print('No error occurred')
finally:
    print('Final output')

try:
  f = open('demofile.txt')
  f.write('Lorum Ipsum')
except:
    print('Something went wrong when writing to the file')
finally:
    f.close() # finally close the file

x = -1
if x < 0:
    raise Exception('Sorry, no numbers below zero')
x = 'hello'
if type(x) is not int:
    raise TypeError('Only integers are allowed')

# swap two objects
x = [1,3]
y = [2,4]
x, y = y, x

a = [[1,3],[2,4]]
a[0], a[1] = a[1], a[0]