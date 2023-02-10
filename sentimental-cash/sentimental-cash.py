from cs50 import get_float

while True:
    money = get_float("Change owed: ")
    if money > 0.0:
        money = money * 100
        break
coins = 0
while money > 0:
    if money >= 25:
        money -= 25
        coins += 1
    elif money >= 10:
        money -= 10
        coins += 1
    elif money >= 5:
        money -= 5
        coins += 1
    elif money >= 1:
        money -= 1
        coins += 1

print(coins)