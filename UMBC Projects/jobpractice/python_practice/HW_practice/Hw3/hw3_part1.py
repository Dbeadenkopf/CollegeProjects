
#File: hw2_part2.py                                                            #Author: David Beadenkopf  
#Date: 02/06/22                                                               
#Section: My House                                                             
#Email: david.beadenkopf@gmail.com                                             
#Description: This file contains the simulation of a piece of hailstone
#falling from a starting height specified by the user. The program will start at a user defined starting height and from there decrease in height or increase in height depending if the number given or trailing is even or odd.




from sys import exit


def check_number(number):
    print(f"Hailstone is currently at height {number}")
    if number % 2 ==0:
        #print(number // 2)
        return(number // 2)
    else:
       # print(number*3+1)
        return number*3+1

def user_call(number):
    count = 0
    while number != 1:
        count += 1
        number = check_number(number)
        if(number == 1 or number == 0):
            print(f"Hailstone stopped at height {number}")
            break
    return count


def main():
    

    number = int(input('Please enter the starting height of the hailstone: '))
    count = user_call(number)
   # print('count ',count)

    
main()
