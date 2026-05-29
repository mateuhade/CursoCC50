from math import trunc

cardNumber = int(input("Number: "))

isCardValid = True
cardLength = len(str(cardNumber))
firstTwoDigits = trunc(cardNumber / (10 ** cardLength) * 100)
firstDigit = trunc(firstTwoDigits / 10)

if (cardLength == 13 or cardLength == 16) and firstDigit == 4:
    cardType = "VISA"
elif cardLength == 15 and (firstTwoDigits == 34 or firstTwoDigits == 37):
    cardType = "AMEX"
elif cardLength == 16 and (firstTwoDigits >= 51 and firstTwoDigits <= 55):
    cardType = "MASTERCARD"
else:
    isCardValid = False

summedNumbers = 0
multipliedNumbers = 0
currentMultipliedNumber = 0
for i in range(cardLength):
    if i % 2 != 0:
        currentMultipliedNumber = trunc(cardNumber / 10 ** i) % 10 * 2

        if currentMultipliedNumber > 9:
            multipliedNumbers += (currentMultipliedNumber % 10) + (trunc(currentMultipliedNumber / 10))
        else:
            multipliedNumbers += currentMultipliedNumber

    else:
        summedNumbers += trunc(cardNumber / 10 ** i) % 10
finalCardVerify = multipliedNumbers + summedNumbers

if isCardValid and finalCardVerify % 10 == 0:
    print(cardType)
else:
    print("INVALID")