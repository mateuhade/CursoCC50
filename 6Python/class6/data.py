# NOTE 2
# We can import whole libraries like this:
#import cs50
# But there is no reason to import a whole library and consume a lot of memory when we are
# just going to use a few functions, so we can do this:
#from cs50 import get_string, get_int, get_float 

# ------------ Primary Data Types ------------
# differently than C, which is a strongly typed language, Python is a loosely typed language,
# which means, python is a language that you don't need to specify what is the data type of
# the variable you are working with, unlike in C.
# But it also has a more limited data set to work with, in Python the primary data types are
# only Booleans (bool) strings, (str), integers (int), and floats (float), there is no long
# int, no double, etc. Python automatically decides the sizes of memory that each variable
# will take;.

# ------------ Secondary Data Types ------------
# First we have *Lists*. Lists are similar to arrays, but not the same, lists can grow and
# shrink without the need of malloc(), they can store different types of data, like
# [False, "item 1", 2, 3.141592]
# Then, we have *Tuples*. Tuples are more similar to arrays since they cannot be modified
# after creation, usually used for constant values. They consume less memmory than lists
# and are more quickly accessed by indices
# We also have *Dicts*. Short for dictionaries, dicts lets ????????????????????????
# ????????????????????????????????????????????????????????????????????????????????
# ????????????????????????????????????????????????????????????????????????????????
# And lastly we have *sets*. Which are lists of items that cannot have duplicates, for
# example {1, 2, 3, 4, "test"}, an example of an invalid set is {1, 1, 3, "test", "test"}
# ---------------------------------------------

# Here we make a for loop count to 11 starting from 1, this is a hint to the interpreter that
# it needs to iterate 2 numbers at a time, so: 1, 3, 5, 7, 9, etc.
# Something that is important to note is that range is exclusive, so we need to put 1 value
# higher than the last one we want, like when we check i < 10, the last number we get is 9
for i in range(1, 12, 2):
    print(i)