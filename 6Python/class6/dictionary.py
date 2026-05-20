# NOTE 6

# Here we create a dictionary of people
people = {
    # The key for this item is "Brian", and the value that corresponds to that key is "+1-617-495-1000"
    "Brian": "+1-617-495-1000",
    "David": "+1-949-468-2750"
}

name = input("Search for a name: ")
if name in people:
    # Prints out the value (number) correspondent to the key (name)
    print(f"Number: {people[name]}")
#-------------------------------------

x = 1
y = 2
print(f"x is {x}, y is {y}")
# we can assign values to more than one variable at a time like this, but it can get confusing quickly
x, y = y, x
print(f"x is {x}, y is {y}")
#-------------------------------------
# libabry used to interact with csv (spreadsheet) files
import csv

# this is the Python convention for opening files, the indentation acts as a warning to f.close() the
# file, and the "as" keyword acts as an assignment operator
with open("phonebook.csv", "a") as file:
    name = input("Name: ")
    number = input("Number: ")

    writer = csv.writer(file)
    writer.write([name, number])