# NOTE 5
# When we have a code that has multiple functions that call each other, it can become a problem to
# organize them and make the program actually work since we don't have prototypes
# So to solve that problem we can actually create a main function like in C, even though it is not
# strictly necessary

def main():
    meow(3)
    # The Python convention for naming functions is snake_case (word_word_word_1())
    #get_positive_int()
    #stairs(3)
    #wall(3)

def meow(times):
    for i in range(times):
        print("meow")

# And to run this code, we just call the main function at the end
#main()
# When creating libraries it is common to use the following command that basically does the same
# thing but it checks to see if the whole library is being called
#if __name__ == "__main__":
#   main()
# -----------------------

# In python the dowhile structure doesn't exist, so we'll do it like this:
def get_positive_int():
    while True:
        n = int(input("Positive integer: "))
        if n > 0:
            break
    # Also, variables that are initialized in structures aren't scoped to those structures, but
    # instead its respective function, so we can return n even when outside of the while loop
    return n
# -------------------------

def stairs(size):
    for i in range(size):
        # Python accepts operations with strings (4 * "#" = "####"; "a" + "b" = "ab")
        print(((size-i-1) * " ") + (i+1) * "#")

def wall(size):
    for i in range(size):
        for i in range(size):
            print("#", end="")
        print()

main()