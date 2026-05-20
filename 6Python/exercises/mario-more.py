def main():
    height = int(input("Height: "))
    pyramid(height)

def pyramid(height):
    for i in range(height):
        print(((height-i-1) * " ") + ((i+1) * "#"), ((i+1) * "#"))

main()