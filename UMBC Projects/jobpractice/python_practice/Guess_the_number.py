# this file will contain the contents to the famouse guessing game called
# guess the number

# random number Module
import random

# Number of variables
attempts = 0;

#lets start with chosing a random number
number = random.randint(1,20)
print("I am thinking of a number between 1 and 20.")

while attempts < 6:
    guess = int(input("Take a guess: "))
    attempts  = attempts + 1

    #if players guess is to low
    if guess < number:
        print("Go Higher")

    if guess > number:
        print("Go Lower")

    if guess == number:
        break

#if the player won
if guess == number:
    ## going to type_cast and turn it into a string
    ## this way we can explain to the user how many
    ## attempts we would get
    attempts = str(attempts)
    print(f"Good job! you guessed my number in {attempts} guesses!")


#if the player lost
if guess != number:
    number = str(number)
    print(f"Nope. The number I was thinking of was {number}")
