queue=[]
heap=[1,2,3,4,5,6,7]
def levelorder(heap, i, n):
    parent =i
    left = 2*i+1
    right= 2*i+2
    print(queue.pop(0))
    if right>=n:
        return queue
    if heap[left]:
        queue.append(heap[left])
        levelorder(heap, left, n)
    if heap[right]:
        queue.append(heap[right])
        levelorder(heap, right, n)
    return queue
queue.append(heap[0])
levelorder(heap, 0, 7)