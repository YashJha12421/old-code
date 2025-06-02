import numpy as np
import matplotlib.pyplot as plt
x1=np.zeros(100)
x2=np.zeros(100)
y=np.zeros(100)
y1=np.zeros(100)

for i in range (100):
  x1[i]=i
  x2[i]=i**2
for k in range (100):
  y[k]=0.001*k + 0.001*(k**2)+3

def compute(x1, x2, y, y1):
    a=0.000001
    w1=0.1
    w2=0.1
    b=1
    n=1000
    j=np.zeros(n)
    for i in range(n):
        dj_dw1=0
        dj_dw2=0
        dj_db=0
        j[i]=0
        for u in range(100):
            j[i]=j[i]+((w1*x1[u]+w2*x2[u]+b-y[u])**2)/(2*n)
            dj_dw1 += ((w1*x1[u] +w2*x2[u]+b-y[u])*x1[u])/n
            dj_dw2 += ((w1*x1[u] +w2*x2[u]+b-y[u])*x2[u])/n

            dj_db+= ((w1*x1[u]+ w2*x2[u]+b-y[u]))/n
        w1=w1-a*dj_dw1
        w2=w2-a*dj_dw2
        b=b-a*dj_db
        print(w1, w2, b, j[i])
    m=np.zeros(n)
    for i in range(n):
        m[i]=i
    plt.plot(m,j)
    plt.legend()
    plt.show()
    for v in range (100):
        y1[v]=x1[v]*w1+x2[v]*w2+b

    # Plot our model prediction
    plt.plot(x2, y1,c='b', label='Our Prediction')

    # Plot the data points
    plt.scatter(x2, y, marker='x', c='r',label='Actual Values')

    # Set the title
    plt.title("Housing Prices")
    # Set the y-axis label
    plt.ylabel('Price (in 1000s of dollars)')
    # Set the x-axis label
    plt.xlabel('Size (1000 sqft)')
    plt.legend()
    plt.show()
compute(x1,x2, y, y1)