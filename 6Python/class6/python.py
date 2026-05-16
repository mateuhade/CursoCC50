# NOTE 1

# This is how we import libraries in python and how we import functions from those libraries
#from cs50 import get_string

#answer = get_string("What is your name?")

# Here are some differences in python from C (besides command syntax): First, we don't need to specify
# what is the data type of our variable, python will automatically decide that; We don't add a semicolon
# to tell python that it is the end of our command; 
answer = input("What is your name? ")

# This is how we concatenate (join) two strings or a string and a variable in general
print("Hello, " + answer)

print("----FStrings----")
# We can also do it this way, by using a format string, basically printf("%s", x); but simpler
# Also, python automatically breaks the line after a print command
print(f"Hello, {answer}")

counter = 0
counter += 1

print("----Conditional Structure----")
# In python, when using else, for, while, etc. We don't need to add the curly braces, but in turn,
# the correct indentation is obligatory, since it will tell the interpreter where the structure
# will end
if counter > 0:
    print("counter is positive")
elif counter < 0:
    print("counter is negative")
else:
    print("counter is 0")

# Booleans need to be described witha an uppercase first letter
coolBoolean = True

print("----While loop----")
i = 0
while i < 3:
    print(i)
    i += 1

print("----Listed for loop----")
# this a way to write a for loop in python, giving the variable i in the first iteration the value
# of 0, then on the second 1, and the third 2. And after the list ends, so does the for loop
for i in [0, 1, 2]:
    print(i)

print("----Ranged for loop----")
# this pevious syntax can be used in a few contexts like when we are dealing with variable arrays, but
# usually we will use this more succinct and logic syntax which does the same thing:
for i in range(3):
    print(i)

