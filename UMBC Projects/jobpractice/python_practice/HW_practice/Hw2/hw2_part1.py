#File: hw2_part2.py
#Author: David Beadenkopf
#Date: 02/06/22
#Section: My House
#Email: david.beadenkopf@gmail.com
#Description:
# This file will contain python code that will simulate a small alchecmist
# The alchemist will be creating potions and through the use of strings
# and if and else statements we can simulate our alchemist



#this function will handle the combined elements








def Alchemy(User_Element1, counter1,counter2,counter3):
    print(f"Here are your counters {counter1} {counter2} {counter3}")
    Count_fire = counter1
    Count_earth = counter2
    Count_water = counter3
    User_Element2 = input("Enter your second choice (earth, fire, water)? ")
    while(True):
        if(User_Element1 == "fire" and User_Element2 == "fire"):
            Count_fire +=1
        if(User_Element1 == "earth" and User_Element2 == "earth"):
            Count_earth +=1
        if(User_Element1 == "water" and User_Element2 == "water"):
            Count_water +=1
       # User_input = input("What element do you want? ")
        if (Count_fire == 2 or Count_earth == 2 or Count_water == 2):
            print(f"That just makes more {User_Element2} than you need!\n")
            break
    #while(True):
        if(User_Element1 == "fire" and User_Element2 == "water"):
            print(f"{User_Element1} and {User_Element2} creates Steam")
            break
        if(User_Element1 == "fire" and User_Element2 == "earth"):
            print(f"{User_Element1} and {User_Element2} creates lava")
            break
        if(User_Element1 == "water" and User_Element2 == "earth"):
            print(f"{User_Element1} and {User_Element2} creates mud")
            break





def main():
  #Elements = ["Earth", "Fire", "Water"]
  Choice_element1 = input("Enter your first choice (earth, fire, water)? ")
  #Choice_element2 = input("Enter your second choice (earth, fire, water)? ")
  count_w = 0
  count_f = 0
  count_e = 0
  if(Choice_element1 == "earth"):
      count_e +=1
  if(Choice_element1 == "fire"):
      count_f +=1
  if(Choice_element1 == "water"):
      count_w +=1
  Alchemy(Choice_element1, count_f, count_e, count_w)
  


      

main()




