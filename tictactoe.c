#include <stdio.h>
#include <stdlib.h>

//Global variables
char game_board[9];
char cmd[10] = "clear";
char y='y';
int x=0;
int put_turn = 0;
char mark;

//Function prototypes
void print_board();
void clear_board();
void take_turn();
int check_winner();


int main() {
    int game_won;
    int game_true = 0;
    char answer;
    clear_board();
    //main game loop
    while (game_true < 10){

        print_board();
        take_turn(game_true);
        game_true++;
        game_won = check_winner(game_true);
        if (game_won==0){
            printf("\nWant to play again?");
            scanf("%c", &answer);
            if (answer=='y' || answer=='Y'){
                game_true=0;
                clear_board();
            }
            else{
                exit(0);
            }
        }

    }
    return 0;
}


//Function which prints the board
void print_board(){
    //clear screen
    system(cmd);
    //print empty
    printf("\n\n\n\n");
    //print colum numbers
    printf("\t\t\t   1 | 2 | 3 \n");
    //print line over the board
    printf("\t\t\t  _ _|_ _|_ _\n");
    //Print the board array
    printf("\t\t\tA| %c | %c | %c\n\t\t\tB| %c | %c | %c\n\t\t\tC| %c | %c | %c\n\n\n\n\n", game_board[0], game_board[1], game_board[2], game_board[3], game_board[4], game_board[5], game_board[6], game_board[7], game_board[8]);
}

//Function to clear the board
void clear_board(){ 
    int i = 0;
    for(i; i<9; i++){
    game_board[i] = ' ';
    }
}

//function which takes and puts players move to the board
void take_turn(int decider){
    if (decider%2==0){
        mark='X';
    }
    else{
        mark='O';
    }
    printf("Take your turn. Give coordinates, first row (A-C) and then colum (1-3): ");
    y = getchar();
    x = getchar();
    
    if (y==65){
        put_turn = x -48 - 1;
        game_board[put_turn] = mark;

    }

    else if(y==66){
        put_turn = x +3 -48 -1;
        game_board[put_turn] = mark;
    }
    else if(y==67){
        put_turn = x +6 -48 -1;
        game_board[put_turn] = mark;
    }
    else{
        printf("Not a valid game move! You lose your turn.");
    }   
    //clear stdinput buffer. If not used the end line mark confuses the game
        while ((getchar()) != '\n');  
}

int check_winner(int winner){
    char mark;
    if ((winner-1)%2==0){
        mark='X';
    }
    else{
        mark='O';
    }
    //Check 1 horizontal line
    if (game_board[0]!=' ' && game_board[0]==game_board[1] && game_board[1]!=' ' && game_board[1]==game_board[2]){
        printf("Gongratulations %c, you are the winner!", mark);
        return 0;
    }
    //Check 2nd horizontal line
    else if (game_board[3]!=' ' && game_board[3]==game_board[4] && game_board[4]!=' ' && game_board[4]==game_board[5]){
        printf("We have a winner!2");
    }
    //Check 3rd horizontal line    
    else if(game_board[6]!=' ' && game_board[6]==game_board[7] && game_board[7]!=' ' && game_board[7]==game_board[8]){
        printf("We have a winner!3");
    }
    //Check 1st vertical line beginning from the left
    else if(game_board[0]!=' ' && game_board[0]==game_board[3] && game_board[3]!=' ' && game_board[3]==game_board[6]){
        printf("We have a winner!4");
    }
    //Check 2nd vertical line beginning from the left
    else if(game_board[1]!=' ' && game_board[1]==game_board[4] && game_board[4]!=' ' && game_board[4]==game_board[7]){
        printf("We have a winner!5");
    }
    //Check 3rd vertical line beginning from the left
    else if(game_board[2]!=' ' && game_board[2]==game_board[5] && game_board[5]!=' ' && game_board[5]==game_board[8]){
        printf("We have a winner!6");
    }
    //Check diagonal line from upper left to lower right
    else if(game_board[0]!=' ' && game_board[0]==game_board[4] && game_board[4]!=' ' && game_board[4]==game_board[8]){
        printf("We have a winner!7");
    }
    //Check diagonal line from upper right to lower left
    else if(game_board[2]!=' ' && game_board[2]==game_board[4] && game_board[4]!=' ' && game_board[4]==game_board[6]){
        printf("We have a winner!8");
    }
    return 1;
}