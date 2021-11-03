#include <iostream>
#include "printBoard2.h"
#include "checkIfWin.h"

int main() {

    int moveRow1, moveCol1;
    int moveRow2, moveCol2;
    int win=0;
    int win1=0;
    int boardArray[3][3] = {{0,0,0},
                            {0,0,0},
                            {0,0,0}};


    Board board;
    Check check1;

    //Calls a function which prints out the empty initial board.
    board.printInitialBoard();

    while(win==0) {
        Player1:
        std::cout << "Player 1: Enter your move.\n";
        std::cout << "Row:";
        std::cin >> moveRow1;
        std::cout << "Column:";
        std::cin >> moveCol1;


        if(boardArray[moveRow1-1][moveCol1-1] == 0){
            boardArray[moveRow1-1][moveCol1-1] = 1;
        }else{
            std::cout << "Player already moved there; go again!\n";
            goto Player1;
        }


        //Updates and outputs the board picture
        board.updateBoard(boardArray);
        //Checks to see if a player has won
        win = check1.checkWin(boardArray);
        win1 = check1.checkUnWonGame(boardArray);

        if((win == 1)||(win1 ==1)){
            std::cout<<"Game Over!";
            break;
        }

        Player2:
        std::cout << "Player 2: Enter your move.\n";
        std::cout << "Row:";
        std::cin >> moveRow2;
        std::cout << "Column:";
        std::cin >> moveCol2;

        if(boardArray[moveRow2-1][moveCol2-1] == 0){
            boardArray[moveRow2-1][moveCol2-1] = 2;
        }else{
            std::cout << "Player already moved there; go again!\n";
            goto Player2;
        }

        boardArray[moveRow2-1][moveCol2-1] = 2;
        //Updates and outputs the board picture
        board.updateBoard(boardArray);

        //Checks to see if a player has won somewhere.
        win = check1.checkWin(boardArray);
        win1 = check1.checkUnWonGame(boardArray);

        //If
        if((win == 1)||(win1==1)){
            std::cout<<"Game Over!";
            break;
        }

    }

}
