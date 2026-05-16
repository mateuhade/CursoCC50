# NOTE 3
# In python, we can solve bigger problems more simply by using opensource libraries and functions to
# solve the smaller problems that we have so that we can focus on the bigger picture
from PIL import Image, ImageFilter

# Here is the filter exercise from week 4 that took me way too long to finish in just 3 lines
before = Image.open("stadium.bmp")
# In python, we dont use the dot operator just to access variables in structs, they can also be used
# to access functions inside of structs
after = before.filter(ImageFilter.BoxBlur(3))
# Functions inside of structs in python are named methods
after.save("out.bmp")

# -------------------------------------

# Here we create a set, which is a list that has no repeating items
words = set()
# Here is how we create functions in Python
def load(dictionary):
    file = open(dictionary, "r")
    # This essentially iterates through everything that is inside the file dictionary, the word line is
    # just used to make the code more readable
    for line in file:
        # Here we add to our set of words everything that is read in the dictionary, bur every time we
        # see a line break we delete it and create a new item in that set   
        words.add(line.rstrip())
    file.close()
    return True

def check(word):
    # This commentary is unnecessary, I'm just mad at the simplicity of the code
    if word.lower() in words:
        return True
    else:
        return False
    
# Cool function bro
def size():
    return len(words)

# In python the memory management is automatically made, so we don't need to bother with freeing it
def unload():
    return True