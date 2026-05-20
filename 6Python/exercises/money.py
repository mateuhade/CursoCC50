def main ():
    changeOwed = 0
    while (changeOwed <= 0) or (type(changeOwed) != float):
        changeOwed = input("Change owed: ")
        if (changeOwed <= 0) or (type(changeOwed) != float):
            print("Invalid amount, try again.")

    coinAmount = get_coin_amount(changeOwed)

    print(coinAmount)

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