# NOTE 1
import csv

#create a set to store data making sure that there are no repeated values
data = []

#opens the csv file and reads it as a dictionary
with open("small_data_set.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        data.append(row)


# if we want to sort the data alphabetically, we can just do this
#dataSetList = sorted(dataSet)

# --------- READ 22-24, THEN COME BACK -----------
# when passing aguments to a function (like sort()) sometimes we can pass in fuctions, in the following case we can pass in
# the dictionary key in which we want to do the sorting
# def f(row):
#     return row["value"]

# but sometimes when we want to sort a file, we actually want to use some key as a sorting rule, like on a data set we
# might have names of people and a number of people with that name, and we want to sort it by the most common name to the least
for row in sorted(data, key=lambda row: row["value"]):
# in this last line we creater a lambda function, that is, a temporary very short function which sole purpose is just
# to return a value to serve as an argument, this is the same thing as line 19 and 20
    print(row["small"], row["value"])