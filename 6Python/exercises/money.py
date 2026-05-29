def main ():
    changeOwed = ask_for_change()

    coinAmount = get_coin_amount(changeOwed)

    print(coinAmount)

def is_float(value):
    try:
        float(value)
        return True
    except ValueError:
        return False

def ask_for_change():

    changeOwed = input("Change owed: ")
    isValid = False

    while not isValid:
        if not is_float(changeOwed):
            while not is_float(changeOwed):
                print("Invalid amount, try again.")
                changeOwed = input("Change owed: ")
        elif float(changeOwed) <= 0:
            print("Invalid amount, try again.")
            changeOwed = input("Change owed: ")
        else:
            isValid = True
    return float(changeOwed)


def get_coin_amount(currentChangeOwed):
    coinAmount = 0

    while currentChangeOwed > 0:
        if round(currentChangeOwed, 2) >= 0.25:
            currentChangeOwed = round(currentChangeOwed, 2) - 0.25
        elif round(currentChangeOwed, 2) >= 0.10:
            currentChangeOwed = round(currentChangeOwed, 2) - 0.10
        elif round(currentChangeOwed, 2) >= 0.05:
            currentChangeOwed = round(currentChangeOwed, 2) - 0.05
        elif round(currentChangeOwed, 2) >= 0.01:
            currentChangeOwed = round(currentChangeOwed, 2) - 0.01

        coinAmount += 1
    return coinAmount

main()