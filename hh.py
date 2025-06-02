def f(n):     return n*f(n-1) if n>1 else n  
print(f(56))
