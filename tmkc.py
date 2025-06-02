def check_prime(k):
    for i in range(2,k):
        if k%i==0:
            return False
            break
        elif i==k-1:
            return True
            
print(" enter n")
n=int(input("Enter n: "))
def n_primes(n):
    r=6
    i=3
    count=1
    while r==6:
        if check_prime(i)==True:
            count+=1
        if count==n:
            return i
            break
        i+=1

print (n_primes(n) )





