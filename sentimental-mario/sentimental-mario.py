# TODO
from cs50 import get_int
height = 0
pyramid = 1

while  True:
    height = get_int("Height: ")
    if  0 < height < 9:
        break

blank = height - 1
for i in range(height):
    for t in range(blank):
        print(" ", end="")
    for h in range(pyramid):
        print("#", end="")
    pyramid +=1
    blank -=1
    print()