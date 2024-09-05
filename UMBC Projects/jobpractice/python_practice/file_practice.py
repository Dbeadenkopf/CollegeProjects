## this file we are going to use what we learned for file io and extract data
## from a file

with open('test.txt' ,'r') as f:
    f_contents = f.read()
    print(f_contents, end = '')
