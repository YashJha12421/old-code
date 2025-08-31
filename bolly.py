crct=str(input("Enter the name of the movie: ").upper())
print("*"*10000)


l=len(crct)
blnk=0
vals=[]

for i in range(l):
    if crct[i]==" ":
        blnk=blnk+1
        print("   ", end='')
    else:
        vals.append(crct[i])
        print("[ ]", end='')
def bol(m):
    print("\n")
    if m==9:
        print("BOLLYWOOD")
    if m==8:
        print("OLLYWOOD")
    if m==7:
        print("LLYWOOD")
    if m==6:
        print("LYWOOD")
    if m==5:
        print("YWOOD")
    if m==4:
        print("WOOD")
    if m==3:
        print("OOD")
    if m==2:
        print("OD")
    if m==1:
        print("D")
    if m==0:
        print("You ran out of moves")

l1=len(crct)
print("\n")
m=9
d=0
attempt='k'
guesses=[]
while True:
    while True:
        guess1=str(input("Guess the letters of the Movie, or type 'NAME' to print movie name : ").upper())
        if guess1=="NAME":
            attempt=str(input("Give name: ").upper())
            if attempt==crct:
                print("Nice! You won")
                break
            else:
                print("nope")
                m=m-1
                bol(m)
                continue
        else:
            guess=guess1
    
        if len(guess)==1:
            if guess in guesses:
                continue
            break
        
        elif guess==" ":
            print("-_- enter a letter/no./symbol")
        else:
            print("Try Again. Too Many letters")
        if m==0:
            break
    if attempt==crct:
        break
    guesses.append(guess)
    k=len(guesses)
    o=0
    for i in range(l):
        
        for j in range(k) :
            if crct[i]==guesses[j]:
                print(guesses[j], end="")
                d=1
                o=o+1
        
        
        if crct[i]==" ":
            print("  ", end='')      

        elif d==0:
            print("[ ]", end='')
        d=0
    l1=l1-o
    if l1==0:
        print("nice, you just won")
        break
    bol(m)
    if m==0:
        break
    







