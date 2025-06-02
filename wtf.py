while True:
    crct=str(input("Enter the correct 4 digit code(ABCDEFG): ").upper())
    if len(crct)==4:
        break
for i in range(10):
    while True:
        guess=str(input(f"Guess the correct 4 digit code(ABCDEFG) {10-i} attempts left : ").upper())
        if len(guess)==4:
            break
    
    val=0
    for a in range(4):
        if guess[a]==crct[a]:
            val+=1
    print(f"{val} true letters")
    if val==4:
        break
    
if val==4:
    print("Nice! You won!")
if val!=4:
    print("Better luck next time!")