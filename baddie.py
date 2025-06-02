def check_prime(k):
    for i in range(2,k):
        if k%i==0:
            return False
            break
        else:
            return True

def n_primes(n):
    r=6
    i=3
    count=1
    while r==6:
        if check_prime(i)==True:
            count+=1
            if count==n:
                break
            
        
