from cs50 import get_string
import math

letter = 0
word = 1
sentence = 0
text = get_string("Text: ")

for x in text:
    if x == " ":
        word += 1
    elif x == "." or x == "!" or x == "?":
        sentence += 1
    else:
        letter += 1

cole_L = letter / word * 100
cole_S = sentence / word * 100
cole_answer = 0.0588 * cole_L - 0.296 * cole_S - 15.8

if cole_answer > 16:
    print("Grade 16+")
elif 1 <= cole_answer <= 16:
    print(f"Grade {math.floor(cole_answer+.03)}")
else:
    print("Before Grade 1")
