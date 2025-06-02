

class Node:
    def __init__(self, data):
        self.data=data
        self.left=None
        self.right=None
def buildtree():
    val=int(input("val? "))
    if val==-1:
        return None
    node=Node(val)
    
    node.left=buildtree()
    node.right=buildtree()
    return node

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end=' ')
        inorder(root.right)
node=buildtree()
inorder(node)



queue=[1]
def pushq(data):
    queue.append(data)
def deque():
    queue.pop(0)
pushq(1)
pushq(2)
pushq(3)
deque()
print(queue)

stack=[]

def level_order(root):
    if root is None:
        return
    queue=[root]
   
    while queue:
        current=queue.pop(0)
        
        print(current.data, end=' ')
        if current.left:
            queue.append(current.left)
        if current.right:
            queue.append(current.right)














def depth(root, target, current_depth=0):
    if root is None:
        return -1
    if root.data == target:
        return current_depth

    left = depth(root.left, target, current_depth + 1)
    if left != -1:
        return left

    return depth(root.right, target, current_depth + 1)
def insert(heap, data):
    heap.append(data)
    n=len(heap)-1
    while n>0:
        parent=(n-1)//2
        if heap[parent]<heap[n]:
            heap[parent], heap[n]=heap[n], heap[parent]
            n=parent
        else:
            break
def maxheapify(heap, n, i):
    largest=i
    if n<2*i+3:
        return heap
    left=2*i+1
    right=2*i+2
    
    if heap[largest]<heap[right]:
        largest=right
    if heap[largest]<heap[left]:
        largest=left
    if i!=largest:
        heap[largest], heap[i]=heap[i], heap[largest]
    maxheapify(heap, n, largest)
    return heap

    