//
// Created by Tyler Allen on 11/2/21.
//

#ifndef TICTACTOEGAME_CHECKIFWIN_H
#define TICTACTOEGAME_CHECKIFWIN_H

class Check{
public:
    int win=0;

    int checkWin(int currentBoard[3][3]){

        for(int i=0; i<3; i++){

            //checks horizontal.
            if(((currentBoard[i][0] == currentBoard[i][1]) && (currentBoard[i][1] == currentBoard[i][2])&&(currentBoard[i][2]==currentBoard[i][0])) &&
                    ((currentBoard[i][0] != 0) && (currentBoard[i][1] !=0) && (currentBoard[i][2]!=0))) {
                std::cout << "Player " << currentBoard[i][1] << " Wins!\n";
                return win = 1;
            }
            //checks vertical.
            if(((currentBoard[0][i] == currentBoard[1][i])&&(currentBoard[1][i]==currentBoard[2][i])&&(currentBoard[2][i]==currentBoard[0][i])) &&
                    (currentBoard[0][i] != 0 && currentBoard[1][i] != 0 &&  currentBoard[2][i]!=0)){
                std::cout << "Player " << currentBoard[0][i] <<" Wins!\n";
                return win=1;
            }
        }
        //these two if statements check the diagonals.
        if(((currentBoard[0][0] == currentBoard[1][1]) &&(currentBoard[1][1]=currentBoard[2][2]) &&(currentBoard[2][2]==currentBoard[0][0])) &&
                (currentBoard[0][0] != 0 && currentBoard[1][1] != 0 && currentBoard[2][2]!=0)){
            std::cout << "Player " << currentBoard[0][0] <<" Wins!\n";
            return win=1;
        }
        if(((currentBoard[0][2] == currentBoard[1][1]) &&(currentBoard[1][1]==currentBoard[2][0]) &&(currentBoard[1][1]==currentBoard[0][2]))&&
                (currentBoard[0][2] != 0 && currentBoard[1][1] !=0 && currentBoard[2][0]!=0)){
            std::cout << "Player " << currentBoard[0][2] <<" Wins!\n";
            return win=1;
        }
        return 0;
    }

    int checkUnWonGame(int currentBoard[3][3]){

        //this function checks whether the board is filled up.
        int counter = 0;

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(currentBoard[i][j] != 0){
                    counter += 1;

                }
            }
        }
        //If all slots have a move, return a 1 which will then end the game.
        if(counter == 9){
            return 1;
        }else{
            return 0;
        }

    }



};


#endif //TICTACTOEGAME_CHECKIFWIN_H
