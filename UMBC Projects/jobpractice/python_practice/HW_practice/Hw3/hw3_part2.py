#File: hw2_part3.py
#Author: David Beadenkopf                                                      
#Date: 03/09/22                                                                
#Section: My House                                                             
#Email: david.beadenkopf@gmail.com                                             
#Description: The program is able to calculate the answer to an integer divisin
#problem without using the division, integer division, mod, or multiplication
#operators.
#The program should ask the user for two integers, and should compute the
#answer to firstNum // secondNum. The program should then output the
#full equation, including the answer, to the user


def integer_div(number1,number2):
    number3 = number1//number2
   # print(f"{number1} // {number2} = {number3}")

    if(number1 >= 200 and number1 <= 3000):
        number3 = number1//number2
        print(f"{number1} % {number2} = {number3}")
    else:
        print(f"{number1} // {number2} = {number3}")




def main():
    num1 = int(input("Please enter the first number: "))
    num2 = int(input("Please enter the second number: "))
    integer_div(num1,num2)



main()
