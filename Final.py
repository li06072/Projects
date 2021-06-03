import time

def basic_board(board): # The function is designed to form the board design for the game
    for a in range(0,9): # Loop iterates for 9 times from 0 till 9, as we have 9 positions in Tic Tac Toe game
        if((a>0) and (a%3)==0): 
            print("\n")
        if(board[a]==0):
            print("- ",end=" ")5
        if (board[a]==1):
            print("O ",end=" ")
        if(board[a]==-1):    
            print("X ",end=" ")
    print("\n\n")
# Now we will take player 1 inputs in below function 
def player1(board):
    move =input("Enter X's position from [1 till 9]: ") # The statement seek input of player 1 for positions 1 to 9
    move=int(move)  # In this statement the input is converted to insteger from string 
    if(board[move-1]!=0):
        print("Please enter right move, else it will be dismissed !!")
        exit(0) 
    board[move-1]=-1

# now we will take second player inputs in below function
def player2(board):
    move =input("Enter O's position from [1 till 9]: ") # The statement seek input of player 2 for positions 1 to 9
    move =int(move) # In this statement the input is converted to insteger from string 
    if(board[move-1]!=0):
        print("Please enter right move, else it will be dismissed !!")
        exit(0) 
    board[move-1]=1
    
#This function checks any possible winning combination and ruturns 0 if no combination is found.
def combinations(board):
    c=[[0,1,2],[3,4,5],[6,7,8],[0,3,6],[1,4,7],[2,5,8],[0,4,8],[2,4,6]]

    for i in range(0,8):
        if(board[c[i][0]] != 0 and
           board[c[i][0]] == board[c[i][1]] and
           board[c[i][0]] == board[c[i][2]]):
            return board[c[i][2]]
    return 0

#our function implementing the minmax algorithm
def minmax(board,player):
#analyse board is a helper function that parses board for entered player combinations. It is used to get current player position, then the algorithm then decides which position for other to select to beat the player 
    a=combinations(board)#change name of function when Hamna designs the helper function. 
    if(a!=0):
        return (a*player)
    final_position=-1
    value_moved=-2
    #0 to 9 since there are only 9 boxes for each mark to be placed.
    for i in range(0,9):
        if(board[i]==0):
            board[i]=player
            final_score=-minmax(board,(player*-1))
            if(final_score>value_moved):
                value_moved=final_score
                final_position=i
            board[i]=0
#if player 1 turn, final position=-1, return zero else return value of position to be used by computer to make the best possible move according to the algorithm.

    if(final_position==-1):
        return 0
    return value_moved

#In this function computer makes its move utilising minmax helper function above to implememnt minmax algorithm
def computer_move(board):
    start=time.time()
    final_position=-1
    value_moved=-2
    for i in range(0,9):
        if board[i]==0:
            board[i]=1
            #player=-1 implies running minmax algorithm for comoputer's turn.
            final_score=-minmax(board, -1)
            board[i]=0
            if(final_score>value_moved):
                value_moved=final_score
                final_position=i
#board postition used by computer while its computer's turn
    board[final_position]=1
    end=time.time()
    print(end-start)
    
    


#Main Function lets user choose in mode they want to play and calls helper functions according to the selection.
def main():
    mode=input("Enter 1 for single player, 2 for multiplayer: ") #for single player or multiplayer mode
    mode=int(mode)
    #The broad is considered in the form of a single dimentional array.
    #One player moves 1 and other move -1.
    board=[0,0,0,0,0,0,0,0,0]
    if mode==1:
        print("Computer : O Vs. You : X")
        player= input("Enter to play 1(st) or 2(nd) :") #lets us choose which player will go first
        player = int(player)
        for i in range (0,9):
            if(combinations(board)!=0):
                break
            if((i+player)%2==0):
                computer_move(board)
            else:
                basic_board(board)
                player1(board)
    else:
        for i in range (0,9):
            if(combinations(board)!=0):
                break
            if((i)%2==0):
                basic_board(board)
                player1(board)
            else:
                basic_board(board)
                player2(board)
         

    x=combinations(board)
    if(x==0):
         basic_board(board)
         print("Draw!!!")
    if(x==-1):
         basic_board(board)
         print("X Wins!!! O Looses !!!")
    if(x==1):
         basic_board(board)
         print("X Looses!!! O Wins !!!!")

main()