while True:
    cent = float(input("Change owned: "))
    if cent > 0.00:
        break

cent = round(int(cent * 100))
count = 0
while cent > 0:
    if cent >= 25:
        cent -= 25
        count += 1
    elif cent >= 10:
        cent -= 10
        count += 1
    elif cent >= 5:
        cent -= 5
        count += 1
    else:
        cent -= 1
        count += 1
print(count)