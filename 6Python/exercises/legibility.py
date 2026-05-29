def isAlpha(character):
    if (character.upper() >= "A" and character.upper() <= "Z"):
        return True
    else:
        return False


text = input("Text: ")
letters = 0
sentences = 0
words = 1
for character in text:
    if isAlpha(character):
        letters += 1
    elif character == " ":
        words += 1
    elif character == "." or character == "!" or character == "?":
        sentences += 1

averageLetters = letters / words * 100
averageSentences = sentences / words * 100
grade = 0.0588 * averageLetters - 0.296 * averageSentences - 15.8

if grade <= 0:
    print("Before Grade 1")
elif grade < 16:
    print(f"Grade {round(grade)}")
else:
    print("Grade 16+")
