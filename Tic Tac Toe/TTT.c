#include <stdio.h>
#include <stdbool.h>

void updateBoard(int[3][3]);
void drawLine();
void introduction();
int switchPlayer(int);
void fillInitialGridStatus();
void detectWin();

//  List of characters program can choose from to fill board
char letters[] = " XO";

// Is game active
bool active = true;

int playerTurn = 1;

// Grid status determines if a certain square is full or not
bool gridStatus[3][3];

// Which letter is displayed within a square (index of 'letters' char array)
int boardState[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

int main(){

    fillInitialGridStatus();

    introduction();
    updateBoard(boardState);
    while(active){
        printf("\nPlayer %d, Select a row number! (0-2)", playerTurn);
        
        int row = NULL;
        scanf("%d", &row);
        
        printf("\nPlayer %d, Select a column number! (0-2)", playerTurn);
        int column = NULL;
        scanf("%d", &column);
        
        if(!gridStatus[row][column]){
            gridStatus[row][column] = true;
            boardState[row][column] = playerTurn;
            playerTurn = switchPlayer(playerTurn);
        }
        detectWin();
        updateBoard(boardState);


    }
    return 0;
}

// Hard coded to run through every win possibility (can probably be optimized)
void detectWin(){
    for(int i = 0; i < 3; i ++){
        if(boardState[i][0] == 1 && boardState[i][1] == 1 && boardState[i][2] == 1){
            active = false;
            printf("Player1 wins!");
        }else if(boardState[i][0] == 2 && boardState[i][1] == 2 && boardState[i][2] == 2){
            active = false;
            printf("Player2 wins!");
        }
    }

    for(int i = 0; i < 3; i ++){
        if(boardState[0][i] == 1 && boardState[1][i] == 1 && boardState[2][i] == 1){
            active = false;
            printf("Player1 wins!");
        }else if(boardState[0][i] == 2 && boardState[1][i] == 2 && boardState[2][i] == 2){
            active = false;
            printf("Player2 wins!");
        }
    }

    if(boardState[0][0] == 1 && boardState[1][1] == 1 && boardState[2][2] == 1){
        active = false;
        printf("Player1 wins!");

    }

    if(boardState[0][2] == 1 && boardState[1][1] == 1 && boardState[2][0] == 1){
        active = false;
        printf("Player1 wins!");

    }

    if(boardState[0][0] == 2 && boardState[1][1] == 2 && boardState[2][2] == 2){
        active = false;
        printf("Player2 wins!");

    }

    if(boardState[0][2] == 2 && boardState[1][1] == 2 && boardState[2][0] == 2){
        active = false;
        printf("Player2 wins!");

    }
}

// Fills each grid square to false, or empty
void fillInitialGridStatus(){

    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            gridStatus[i][j] = false;
        }
    }
}

// Intro
void introduction(){
    printf("\nHello! Today you will be playing tic tac toe with one other player.");
    
    char selection;
    
    while(selection != 'y'){
        printf("\nType 'y' to begin");
        scanf("%c", &selection);
    }
}

// Updates the board to match the 'state[][]' argument
void updateBoard(int state[3][3]){
    
    printf("\n%c | %c | %c", letters[state[0][0]], letters[state[0][1]], letters[state[0][2]]);
    drawLine();
    printf("\n%c | %c | %c", letters[state[1][0]], letters[state[1][1]], letters[state[1][2]]);
    drawLine();
    printf("\n%c | %c | %c", letters[state[2][0]], letters[state[2][1]], letters[state[2][2]]);
    printf("\n\n");
}

// Draws horizontal line of the board
void drawLine(){
    printf("\n----------");
}

// Switches active player
int switchPlayer(int player){
    if(player == 1){
        return 2;
    }else{
        return 1;
    }
}

