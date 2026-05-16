# NOTE 4
# Although, because python is such a "simple" language, it needs to implement various multicase
# solutions, like if we want to close a file we can jsut close it in C, but in python, the method
# close will check if there are more than a single file, if the file exists, what type of file it
# is, etc. So that it won't generate any bugs. but doing that across many functions will cause a
# slower output than if we jsut implemented the best solution for our specific case.

# Another thing we might have noticed while running our python codes is that we don't need to
# compile our code, that is because Python uses an interpreter instead of a compiler, that means,
# every time we run a Python program it reads a line of code, translates it to machine code,
# executes it (if it does not depend on subsequent lines, like functions) and then it goes to the
# next line doing it all over again. That causes another loss on speed of execution, at the end
# of the day, meaning that a program can at most be as fast as its interpreter.
# Unlike the compiler, that compiles everything first and then generates an executable program
# skipping the whole read, translate, next line algorithm.

# -----------------------
# The input function naturally gets strings, so to do math with that later we cast it into an int
x = int(input("x: "))
y = int(input("y: "))
print(x + y)
# Since Python is a dynamic language it automatically casts the result of an operation into the
# actual type it should be if done on paper, so instead of truncating the result and getting 0,
# it casts those ints into floats and we get 0.5
print(x / y)
print("---------------")
#------------------------
s = input("Do you agree?(y/n) ")
# in Python we don't have to use single quotes for single characters since the type char doesn't
# exist, it is all treated as a string.
if s.lower == "y" or s.lower == "yes":
    print("Agreed")
# Also, we can compare easily two strings because here we baiscally don't use pointers at all since
# all of that is automatically managed by the language
elif s.lower in ["n", "no"]:
    print("Not agreed")
