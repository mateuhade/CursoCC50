# NOTE 2
import csv

def main():
    VALID_WORDS = ["this", "one", "comma"]

    word = input("Word: ")
    if word not in VALID_WORDS:
        print("Valid words: ", VALID_WORDS)
        return 1
    
    with open("small_data_set.csv", "r") as file:
        reader = csv.DictReader(file)
        counter = 0
        for row in reader:
            if row["small"] == word:
                counter += 1
    
    print(word + ":", counter)

main()