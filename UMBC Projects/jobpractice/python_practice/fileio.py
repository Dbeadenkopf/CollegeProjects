# now we are going to work with a context manager which is using 'with' it
# allows for us to have a loop and when that loop ends it closes the file
# this way we  dont have to keep writing file.close()
with open('test.txt' , 'r') as f:

    size_to_read = 100
    f_contents = f.read()
    print(f_contents, end = '')


    
