while True:
    n = int(input("Height: "))
    if n > 0 and n < 9:
        break
for x in range(1, n+1):  # rows
    print(" " * (n - x), end="")  # spacing
    print("#" * x)  # columns
