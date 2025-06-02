while True:
    crct=str(input("Enter the correct 4 digit code: ").upper())
    if len(crct)==4:
        break
for i in range(10):
    guess=input(f"Guess the correct 4 digit code(ABCDEFG){10-i} attempts left : ")
