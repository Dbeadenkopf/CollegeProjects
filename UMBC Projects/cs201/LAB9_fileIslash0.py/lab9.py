
    
#possibley a function that takes the list given from the math function and goes through that list and gets each value of the list and displays the data with each persons name seperate ex: alice : 74.6 - C 


def splitFile(splittedFile):
    fileSplit = splittedFile.split()
    return fileSplit


def doMathStuff(configuredList):# this function should multiply each corresponding decimal and integer(weight and Grade) and countinously do this until the end of the list and append each value to an empty list and where the list can be passed to another function
    doMath = splitFile(configuredList)
    for i in range (1, len(doMath)):
        mathCount = doMath[1]*doMath[2] #need to fix this fucntion but I think it needs another for loop or while loop method may be more understandible, or maybe just do the algorithm for this program
        return mathCount

#possibley another function could go here and where it takes the list of integers made by the math function
#and goes through that list and sums up each value in the list and divides by the length of the list and returns the results to the screan
        



def main():
    mutableFile = "grades.txt"
    imutable =open(mutableFile, 'r')
    
    for line in imutable:
        print(line)
   #readInFile("grades.txt")
        print(splitFile(line))
        print(doMathStuff(line))
    #prob a print stament would go down here in which displays the "class average is" and then under or on top would be the called function averageis




main()
