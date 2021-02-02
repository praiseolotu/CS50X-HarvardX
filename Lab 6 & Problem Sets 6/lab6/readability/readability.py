'''
Coleman-Liau index = 0.0599 * L - 0.296 * S - 15.8
   Note that L = letter / word * 100
   Note that S = sentence / word * 100
   Letter can be uppercase or lowercase. Letters should not include digits, punctuation and other symbols.
   A word is sequence of characters separated by space.
   A sentence ends with poriod, exclamation mark, question mark
   The Grade X should be rounded up.
'''
text = input("Text: ")

letters = sentences = 0
words = 1

for index in text:
    if index.isalpha():
        letters += 1
    if index.isspace():
        words += 1
    if index in ['?', '.', '!']:  # if current position is ?, ! or .
        sentences += 1
L = (letters/words) * 100.00
S = (sentences/words) * 100.00
grade = ((0.0588 * L) - (0.296 * S) - 15.8)
level = round(grade)
if level < 1:
    print("Before Grade 1")
elif level >= 16:
    print("Grade 16+")
else:
    print(f"Grade {level}")

