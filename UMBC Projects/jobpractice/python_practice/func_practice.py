


def my_function():
    return_val = "The Contents of this File are now read"
    return return_val


def read_file():
    with open('test.txt' , 'r') as f:
        f_contents = f.read();
        print(f_contents)
    





def main():
    holder = my_function()
    print(holder)



main()
