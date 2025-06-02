arr=[2,1,3,-2,69]
for i in range(5):
    for j in range(4-i):
        if arr[j]>arr[j+1]:
            arr[j], arr[j+1]=arr[j+1], arr[j]

print(arr)
arr=[2,1,3,-2,69]
for i in range(5):
    m=i
    for j in range(i, 5):
        if arr[j]<arr[m]:
            m=j
    arr[m], arr[i]=arr[i], arr[m]
print(arr)
arr=[2,1,3,-2,69]
for i in range(1, 5):
    m=i-1
    while arr[m]>arr[m+1] and m>-1:
        arr[m], arr[m+1]=arr[m+1], arr[m]
        m-=1

print(arr)