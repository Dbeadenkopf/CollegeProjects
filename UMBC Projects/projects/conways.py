def makeBoard(row, col, Cell):
    for i in range(row):
        temp = []
        for j in range (col):
             temp.append("0") # adding a zero at the end of the list
           # for i in range (len(temp)):
        Cell.append(temp)
    return Cell
                



def checkRange(row, col, Grid):
    flag = False
    if row in range(len(Grid)):
        flag = True
    if flag == True:
        if col in range (len(Grid[row])):
             return True
    return False

    
    
    
    #this function makes the entire 2darry basically, takes in the row and column in which the user wants the board to be, checks thorugh both and puts them into a lsit and returns the list with the additions added by the user







def LiveCell(LiveCheck):#find the cordinates on this specific board and try and work around that or each iteration needs its own for loop before ideration and counter so the counter that was indicated in the begging is not going to generally increase for all it will increase for the specified iteration of counter, thats why when looking at the past conways iteration, a marker was always set after the double for loop 
    

   
     for i in range (len((LiveCheck)-2)
        for j in range (len(LiveCheck[i])-2)
            counter = 0:
            if LiveCheck[i+1][j+1] == "0" and LiveCheck[i+1][j+1] == LiveCheck[i+2][j+1] and LiveCheck[i+2][j+1] == "X":
                counter = counter + 1
                print(counter)
            elif LiveCheck[i+1][j+1] == "0" and LiveCheck[i+1][j+1] == LiveCheck[i+2][j+2] and LiveCheck[i+2][j+2] == "X":
                counter = coutner + 1
                print(counter)
            elif LiveCheck[i+1][j+1] == "0" and LiveCheck[i+1][j+1] == LiveCheck[i+1][j+2] and LiveCheck[i+1][j+2] == "X":
                counter = counter + 1
                print(counter)
            elif LiveCheck[i+1][j+1] == "0" and LiveCheck[i+1][j+1] ==  LiveCheck[i][j+2] and LiveCheck[i][j+2] == "X":
                counter = counter + 1
                print(counter)
            elif LiveCheck[i+1][j+1] == "0" and LiveCheck[i+1][j+1] == LiveCheck[i][j+1] and LiveCheck[i][j+1] == "X":
                counter = counter + 1
                print(counter)
            elif LiveCheck[i+1][j+1] == "0" and LiveCheck[i+1][j+1] == LiveCheck[i][j] and LiveCheck[i][j] == "X":
                counter = counter + 1
                print(counter)
            elif LiveCheck[i+1][j+1] == "0" and LiveCheck[i+1][j+1] == LiveCheck[i+1][j] and LiveCheck[i+1][j] == "X":
                counter = counter + 1
                print(counter)
            elif LiveCheck[i+1][j+1] == "0" and LiveCheck[i+1][j+1] == LiveCheck[i+2][j] and LiveCheck[i+2][j] == "X":
                counter = counter + 1
                print(counter)
                if counter > 2 and counter <= 3:
                    LiveCheck[i+1][j+1] = "X"
    for i in range (len(LiveCheck)-3):
        for j in range (len(LiveCheck[i])-3):
            counter = 0
            if LiveCheck[i+2][j+1] == "0" and LiveCheck[i+2][j+1] == LiveCheck[i+1][j+1] and LiveCheck[i+1][j+1] == "X":
                counter = counter + 1
            elif LiveCheck[i+2][j+1] == "0" and LiveCheck[i+2][j+1] == LiveCheck[i+3][j] and LiveCheck[i+3][j] == "X":
                counter = coutner + 1
            elif LiveCheck[i+2][j+1] == "0" and LiveCheck[i+2][j+1] == LiveCheck[i+3][j+1] and LiveCheck[i+3][j+1] == "X":
                counter = counter+1
            elif LiveCheck[i+2][j+1] == "0" and LiveCheck[i+2][j+1] == LiveCheck[i+3][j+2]  and LiveCheck[i+3][j+2] == "X":
                coutner = counter +1
                if coutner > 2 and counter <= 3:
                    LiveCheck[i+1][j+1] = "X"
    for i in range (len(LiveCheck)-4):
        for j in range (len(LiveCheck[i])-3):# configure range, this may work when range is confirgured 
            counter = 0
            if LiveCheck[i+3][j+1] == "0" and LiveCheck[i+3][j+1] == LiveCheck[i+2][j+1] and LiveCheck[i+2][j+1] == "X":
                counter = coutner +1
            elif LiveCheck[i+3][j+1] == "0" and LiveCheck[i+3][j+1] == LiveCheck[i+4][j] and LiveCheck[i+4][j] == "X":
                counter = counter + 1
            elif LiveCheck[i+3][j+1] == "0" and LiveCheck[i+3][j+1] == LiveCheck[i+4][j+1] and LiveCheck[i+4][j+1] == "X":
                counter = counter + 1
            elif LiveCheck[i+3][j+1] == "0" and LiveCheck[i+3][j+1] == LiveCheck[i+4][j+2] and LiveCheck[i+4][j+2] == "X":
                counter = counter +1
                if counter > 2 and counter <= 3:
                    LiveCheck[i+3][j+1] = "X"
    for i in range (len(LiveCheck)-2):
        for j in range (len(LiveCheck[i])-2):
            counter = 0
            if LiveCheck[i+1][j+2] == "0" or LiveCheck[i+1][j+2] == LiveCheck[i+1][j+1] and LiveCheck[i+1][j+1] == "X":
                counter = counter + 1
            elif LiveCheck[i+1][j+2] == "0" and LiveCheck[i+1][j+2] == LiveCheck[i+2][j+1] and LiveCheck[i+2][j+1] ==  "X":
                counter = counter + 1
            elif LiveCheck[i+1][j+2] == "0" and LiveCheck[i+1][j+2] == LiveCheck[i+2][j+2] and LiveCheck[i+2][j+2] == "X":
                counter = counter + 1
            elif LiveCheck[i+1][j+2] == "0" and LiveCheck[i+1][j+2] == LiveCheck[i][j+3] and LiveCheck[i][j+3] == "X":
                counter = counter + 1
            elif LiveCheck[i+1][j+2] == "0" and LiveCheck[i+1][j+2] == LiveCheck[i+1][j+3] and LiveCheck[i+1][j+3] == "X":
                counter = counter + 1
            elif LiveCheck[i+1][j+2] == "0" and LiveCheck[i+1][j+2] == LiveCheck[i+2][j+3] and LiveCheck[i+2][j+3] == "X":
                counter = counter + 1
                if counter > 2 and counter <= 3:
                    LiveCheck[i+1][j+2] = "X"
    for i in range (len(LiveCheck)-3):
        for j in range (len(LiveCheck[i])-3):
            counter = 0
            if LiveCheck[i+2][j+2] == "0" and LiveCheck[i+2][j+2] == LiveCheck[i+1][j+2] and LiveCheck[i+1][j+2] == "X":
                counter = counter + 1
            elif LiveCheck[i+2][j+2] == "0" and LiveCheck[i+2][j+2] == LiveCheck[i+1][j+1] and LiveCheck[i+1][j+1] == "X":
                counter = counter + 1
            elif LiveCheck[i+2][j+2] == "0" and LiveCheck[i+2][j+2] == LiveCheck[i+2][j+1] and LiveCheck[i+2][j+1] == "X":
                counter = counter + 1
            elif LiveCheck[i+2][j+2] == "0" and LiveCheck[i+2][j+2] == LiveCheck[i+3][j+1] and LiveCheck[i+3][j+1] == "X":
                counter = counter + 1
            elif LiveCheck[i+2][j+2] == "0" and LiveCheck[i+2][j+2] == LiveCheck[i+3][j+2] and LiveCheck[i+3][j+2] ==  "X":
                counter = counter + 1
            elif LiveCheck[i+2][j+2] == "0" and LiveCheck[i+2][j+2] == LiveCheck[i+3][j+3] and LiveCheck[i+3][j+3] ==  "X":
                counter = counter + 1
            elif LiveCheck[i+2][j+2] == "0" and LiveCheck[i+2][j+2] == LiveCheck[i+2][j+3] and LiveCheck[i+2][j+3] == "X":
                counter = counter + 1
            elif LiveCheck[i+2][j+2] == "0" and LiveCheck[i+2][j+2] == LiveCheck[i+1][j+3] and LiveCheck[i+1][j+3] == "X":
                counter = counter + 1
                if counter > 2 and counter <= 3:
                    LiveCheck[i+2][j+2] = "X"
    for i in range (len(LiveCheck)-4):
        for j in range (len(LiveCheck[i])-3):
            counter = 0
            if LiveCheck[i+3][j+2] == "0" and LiveCheck[i+3][j+2] == LiveCheck[i+4][j+3] and LiveCheck[i+4][j+3] == "X":
                counter = counter + 1
            elif LiveCheck[i+3][j+2] == "0" and LiveCheck[i+3][j+2] == LiveCheck[i+3][j+3] and LiveCheck[i+3][j+3] == "X":
                counter = counter + 1
            elif LiveCheck[i+3][j+2] == "0" and LiveCheck[i+3][j+2] == LiveCheck[i+2][j+3] and LiveCheck[i+2][j+3] == "X":
                counter = counter + 1
            elif LiveCheck[i+3][j+2] == "0" and LiveCheck[i+3][j+2] == LiveCheck[i+2][j+2] and LiveCheck[i+2][j+2] == "X":
                counter = counter + 1
            elif LiveCheck[i+3][j+2] == "0" and LiveCheck[i+3][j+2] == LiveCheck[i+2][j+1] and LiveCheck[i+2][j+1] == "X":
                counter = counter + 1
            elif LiveCheck[i+3][j+2] == "0" and LiveCheck[i+3][j+2] == LiveCheck[i+3][j+2] and LiveCheck[i+3][j+2] == "X":
                counter = counter + 1
            elif LiveCheck[i+3][j+2] == "0" and LiveCheck[i+3][j+2] == LiveCheck[i+3][j+1] and LiveCheck[i+3][j+1] == "X":
                    counter = counter + 1
                    if counter > 2 and counter <= 3:
                        LiveCheck[i+3][j+2] = "X"
    for i in range (len(LiveCheck)-4):
        for j in range (len(LiveCheck[i])-4):
            counter = 0
            if LiveCheck[i+1][j+3] == "0" and LiveCheck[i+1][j+3] == LiveCheck[i+1][j+2] and LiveCheck[i+1][j+2] == "X":
                counter = counter + 1
            elif LiveCheck[i+1][j+3] == "0" and LiveCheck[i+1][j+3] == LiveCheck[i+2][j+2] and LiveCheck[i+2][j+2] == "X":
                counter = counter + 1
            elif LiveCheck[i+1][j+3] == "0" and LiveCheck[i+1][j+3] == LiveCheck[i+2][j+3] and LiveCheck[i+2][j+3] == "X":
                counter = counter + 1
            elif LiveCheck[i+1][j+3] == "0" and LiveCheck[i+1][j+3] == LiveCheck[i+2][j+4] and LiveCheck[i+2][j+4] == "X":
                counter = counter + 1
            elif LiveCheck[i+1][j+3] == "0" and LiveCheck[i+1][j+3] == LiveCheck[i+1][j+4] and LiveCheck[i+1][j+4] == "X":
                counter = counter + 1
            elif LiveCheck[i+1][j+3] == "0" and LiveCheck[i+1][j+3] == LiveCheck[i][j+1] and LiveCheck[i][j+1] == "X":
                counter = counter + 1
                if counter > 2 and counter <= 3:
                    LiveCheck[i+1][j+3] = "X"
    for i in range (len(LiveCheck)-4):
        for j in range (len(LiveCheck)-4):
            counter = 0
            if LiveCheck[i+2][j+3] == "0" and LiveCheck[i+2][j+3] == LiveCheck[i+2][j+4] and LiveCheck[i+2][j+4] == "X":
                counter = counter + 1
            elif LiveCheck[i+2][j+3] == "0" and LiveCheck[i+2][j+3] == LiveCheck[i+3][j+4]    and LiveCheck[i+3][j+4] == "X":
                counter = counter + 1
            elif LiveCheck[i+2][j+3] == "0" and LiveCheck[i+2][j+3] == LiveCheck[i+3][j+3]    and LiveCheck[i+3][j+3] == "X":
                counter = couunter + 1
            elif LiveCheck[i+2][j+3] == "0" and LiveCheck[i+2][j+3] == LiveCheck[i+3][j+2] and LiveCheck[i+3][j+2] == "X":
                counter = counter + 1
            elif LiveCheck[i+2][j+3] == "0" and LiveCheck[i+2][j+3] == LiveCheck[i+2][j+2] and LiveCheck[i+2][j+2] == "X":
                counter = counter + 1
            elif LiveCheck[i+2][j+3] == "0" and LiveCheck[i+2][j+3] == LiveCheck[i+4][j+2] and LiveCheck[i+4][j+2] == "X":
                counter = counter + 1
            elif LiveCheck[i+2][j+3] == "0" and LiveCheck[i+2][j+3] == LiveCheck[i+4][j+3] and LiveCheck[i+4][j+3] == "X":
                counter = counter + 1
                if counter > 2 and counter <= 3:
                    LiveCheck[i+2][j+3] = "X"
    for i in range (len(LiveCheck)-4):
        for j in range (len(LiveCheck)-4):
            counter = 0
            if LiveCheck[i+3][j+3] == "0" and LiveCheck[i+3][j+3] == LiveCheck[i+2][j+3] and LiveCheck[i+2][j+3] == "X":
                counter = counter + 1
            elif LiveCheck[i+3][j+3] == "0" and LiveCheck[i+3][j+3] == LiveCheck[i+2][j+2] and LiveCheck[i+2][j+2] == "X":
                counter = counter + 1
            elif LiveCheck[i+3][j+3] == "0" and LiveCheck[i+3][j+3] == LiveCheck[i+3][j+2] and LiveCheck[i+3][j+2] == "X":
                counter = counter + 1
            elif LiveCheck[i+3][j+3] == "0" and LiveCheck[i+3][j+3] == LiveCheck[i+4][j+4] and LiveCheck[i+3][j+2] == "X":
                counter = counter + 1
                if counter > 2 and counter <= 3:
                    LiveCheck[i+3][j+3] = "X"

    return LiveCheck
   




def DeadCell():
    #checks to see which cells are dead in the board, , when iterating through the board
    #it well check each postiion one away from its current one and basically see which cells in the board are dead and do not go on to the new iteration board< set a count to count up the amount of times an x will occur when checking the ppoistions next to the starting one and if the count amounts to a number < 3 then the cells are dead and to not ge turned one un the board representing a live cell
    print()
def printBoard(liveCell):
    for i in range (len(liveCell)):
#    print("Starting Board: ")
        print(''.join(liveCell[i]))
    #this function will print everythig porating to the board, this only prints whats being made to the board by the user so whatever the user makes in player choice gets passed to the makeboard then gets passed to here to be displayed to the user
    
    





def pLayerChoice(row , col, Grid):
   # counter = 0
    if checkRange(row, col, Grid) == True:
        if Grid[row][col] == "0":
            Grid[row][col] = "X"
    return Grid
    
     #   print(Grid)
       # if i[row][col] == "X":
       #     return
       # else:
        #    i[row][col] == "0"
         #   i[row][col] = "X"
   # return Grid
    #function will take the input that they choose and insert them as an X into the board    #then the board will have the starting iteration or point that now has a specified column and row of X`s
    #modiies whats being done to make board but now with the column and row the user has selected, maybe or psobily could use the recursion process for auto for so the user does one slection and fills up the amount of x`s they want , than takes that and sends it to another fuction that sees which cell lives and dies 


def iteration():
    #this fucntion takes in the information from the live and dead cell iterations and applies them to a new baord that does the iteration process and returns a new board with the then additions of the users  
    print()


def main():
    Cellwall = []
    row = int(input("please enter the row: "))
    col = int(input("please enter the col: "))
    Grid = makeBoard(row, col,Cellwall)
    Row_cell = input("enter the row you want alive or q to exit: ")
    Col_cell = input("enter the column you want alive: ")
    while Row_cell!= "q":
        Row_cell = Row_cell.split(',')
        Col_cell = Col_cell.split(',')
        Row = int(Row_cell[0])
        Col = int(Col_cell[0])
        Celljar = Row - 1
        Celljar2 = Col -1
           # Row_Cell = input("enter the row you want alive or q to exit: ")
           # Col_cell = input("enter the column you want alive: ")
        StartIteration = pLayerChoice(Celljar,Celljar2, Grid)
        print(StartIteration)
        LiveJar = LiveCell(StartIteration)
        print(LiveJar)
        In_range = checkRange(Celljar, Celljar2, Grid)
        Row_cell = input("enter the row you want alive or q to exit: ")
        Col_cell = input("enter the column you want alive: ")
        if Row_cell == "q" or Col_cell == "q":
            printBoard(StartIteration)
            printBoard(LiveJar)
   # printBoard(Grid)
    
    
    #promt user for the amount of rows and columns they want there starting baord to be 
    #passs it to make baord so the board can be made correspondig to both row and col
    #promt them for valid imput to board here 
    #call some functions 
    #done stuff
    #need coordinates for entireboard
    #need to make a baord filled with O`s at first 
    #then we need to make a board with the live cells that the user has selected
    #then we need to iterate through that board this the users live cells and change them
    #basically iterate the board that they choose with thier specific live cells
    #do function that checks the rules and basically when iterating throguh the board
    #whcih cells are alive and dead 








main()
