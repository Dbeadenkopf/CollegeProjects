#File: hw2_part2.py  
#Author: David Beadenkopf                                                      
#Date: 02/06/22                                                                
#Section: My House                                                             
#Email: david.beadenkopf@gmail.com                                            
#Description: This program will simulate a dvd rental store that will gather information from the user and display that information to the user



def disp_cust_info(Aw,As,G):
    print(f"You are selling a {G} movie that has been wacthed {Aw} times for {As} dollars.")



    

    


def main():
    Amount_w = int(input("Please enter the amount of times watched: "))
    #Amount_s = float(input("Please enter the price you want to sell for: "))
    #Genre = input("Enter the genre of movie (romance, comedy)")
    while(Amount_w < 0):
        print("You cant watch a movie a negative amount of times.")
        Amount_w = int(input("Please enter the amount of times watched: "))
        while(Amount_w > 10):
            print(f"We dont accept movies watched {Amount_w} times")
            Amount_w = int(input("Please enter the amount of times watched: "))
    while(Amount_s < 0):
        print("We cant accept a negative amount")
        Amount_s = float(input("Please enter the price you want to sell for: "))


main()
