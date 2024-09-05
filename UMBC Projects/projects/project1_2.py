# File: project1_2.py
# Author: David Beadenkopf
# Date: 4/30/15
# Section: 4
#E-mail: beadenk1@umbc.edu
#Description: this python coding and with the combined function, will piece together and implement connect four

#this function takes in an empty list and where is turns that empty list into a 2D list with dashes in which represents the empy spaces in the board
def makeBoard(List1 ,row, col):
    for i in range (row):
        Temp = []
        for j in range (col):
            Temp.append("_")
        List1.append(Temp)
    return List1





def VerticalCheckWin(winnerBoard):
    #Vertical Check
    for i in range (len(winnerBoard)-3):
        for j in range (len(winnerBoard)):
            if winnerBoard[i][j]!= "_" and winnerBoard[i][j] ==  winnerBoard[i+1][j] and winnerBoard[i+1][j] == winnerBoard[i+2][j] and winnerBoard[i+2][j] == winnerBoard[i+3][j] :
               return True
    return False



def DiagnolCheck(winnerBoard):
    for i in range (len(winnerBoard)-3):
        for j in range (len(winnerBoard)-3):
            if winnerBoard[i][j]!= "_" and winnerBoard[i][j] ==  winnerBoard[i+1][j+1] and winnerBoard[i+1][j+1] == winnerBoard[i+2][j+2] and winnerBoard[i+2][j+2] == winnerBoard[i+3][j+3] :
               return True
    return False
    
    #Checks diagnol again but right to left
    for i in range (len(winnerBoard)-3):
        for j in range (len(winnerBoard)-3):
            if winnerBoard[i][j+3]!= "_" and winnerBoard[i][j+3] ==  winnerBoard[i+1][j+2] and winnerBoard[i+1][j+2] == winnerBoard[i+2][j+1] and winnerBoard[i+2][j+1] == winnerBoard[i+3][j] :
               return True
    return False 
    
#this function takes in the updated information from the user and prints it out, basically the updated version of the already made board
def printBoard(LastBoard):
    LastBoard = LastBoard[::-1]
    for i in range (len(LastBoard)):
 
        print(''.join(LastBoard[i]))
    
        

#this function takes in the already made board and alters it but now with the peices of Xs and Os in which are entered by player 1 and player 2        
def PlayersTurn(Grid, player, choice, row):
    P1_piece = "X"
    P2_piece = "O"
   # print(List1)
   
    if player == 1:
        counter = 0
        counter2 = 0
        while counter == 0:
            if  Grid[counter2][choice-1] == "_":# this checks for all the spaces in the column choosen by that player for enemy pieces
                Grid[counter2][choice-1] = P1_piece
                return Grid
            else:
                if counter2 > row-1:#counter is the starting pount and row-1 is checking
                    return False
                else:
                    counter2 +=1
                    

    if player == 2:
        counter3 = 0
        counter4 = 0
        while counter3 == 0:
            if  Grid[counter4][choice-1] == "_":# this checks for all the spaces in the column choosen by that player for enemy pieces
                Grid[counter4][choice-1] = P2_piece
                return Grid
            else:
                if counter4 > row-1:#counter is the starting pount and row-1 is checking
                    return False
                else:
                    counter4 +=1
    
            


#this fucntion checks for the winner in all possible cases, that being vertical, diagnol, horizontal, checks for a connect 4 
def HorizonWin(winnerBoard):
    #HorizontalCheck, i think i had to minus 3 becuase I needed to keep the col i was looping through in range so minus 3 is being implemented
    for i in range(len(winnerBoard)):
        for j in range (len(winnerBoard)-3):
            if winnerBoard[i][j]!= "_" and winnerBoard[i][j] ==  winnerBoard[i][j+1] and winnerBoard[i][j+1] == winnerBoard[i][j+2] and winnerBoard[i][j+2] == winnerBoard[i][j+3] :
                return True
    return False
 

    


    
   


#this fucntion checks for when the board is filled then the logical conclusion is a tie
def checkDraw(tieBoard):
    print()
    Space = False
    for row in tieBoard:
        if "_" in row:
            Space = True
    return not Space and not HorizonWin(tieBoard) and not VerticalCheckWin(tieBoard) and not DiagnolCheck(tieBoard)

        
        
                
            




#this function saves the board at any time during the iterations of the board and also loads a already saved board from a text file anytime
def saveandload():
    print()
#// need to finish this python program
    
       



def main():
    Starter = []
    Gameend = 0
    p1 = 1
    p2 = 2
    Row = 0
    Col = 0
    PlayerTurn = 0
    print("Welome To Connect Four! ")
    loadGame = input("would you like to load game (y/n)? ")
    print()
    while Gameend == 0:
         while Row < 5:
             Row = int(input("please enter a row: "))
         while Col < 5:
             Col = int(input("please enter a column: "))
         board = makeBoard(Starter, Row, Col)
         for i in (board):
             print(''.join(i))

         while PlayerTurn == 0:
             player1 = int(input("player 1 Observe and choose or s to save: ")) 
             while player1 < 1 or player1 > Col or type(player1)!= int:
                 print("please enter a valid choice ")
                 pLayer1 = int(input("player 1 Observe and choose or s to save: "))
             updatedBoard = PlayersTurn(board,p1,player1, Row)
             printBoard(updatedBoard)
             if checkDraw(updatedBoard):
                 print("its a draw >:( ")
             if HorizonWin(updatedBoard):
                 print("player 1 has won ")
                 Restart = input("would you like to play again (y/n)? ")
                 if Restart == "y":
                     main()
                 else:
                     exit()
             elif VerticalCheckWin(updatedBoard):
                 print("player 1 has won")
                 Restart = input("would you like to play again (y/n)? ")
                 if Restart == "y":
                     main()
                 else:
                     exit()
             elif DiagnolCheck(updatedBoard):
                 print("player 1 has won")
                 Restart = input("would you like to play again (y/n)? ")
                 if Restart == "y":
                     main()
                 else:
                     exit()
             
             
             player2 = int(input("player 2 Observe and choose or s to save: "))

             while player2 < 1 or player2 > Col or type(player2)!= int:
                 print("please enter a valid choice ")
                 pLayer2 = int(input("player 2 Observe and choose or s to save: "))
             updatedBoard = PlayersTurn(board,p2,player2, Row)
             printBoard(updatedBoard)
             if checkDraw(updatedBoard):
                 print("its a draw >:( ")
             if HorizonWin(updatedBoard):
                 print("player 2 has won")
                 Restart = input("would you like to play again (y/n)? ")
                 if Restart == "y":
                     main()
                 else:
                     exit()
             elif VerticalCheckWin(updatedBoard):
                 print("player 2 has won")
                 Restart = input("would you like to play again (y/n)? ")
                 if Restart == "y":
                     main()
                 else:
                     exit()
             elif DiagnolCheck(updatedBoard):
                 print("player 2 has won")
                 Restart = input("would you like to play again (y/n)? ")
                 if Restart == "y":
                     main()
                 else:
                     exit()
             
         
    
         
        

    

main()
