//
// Created by Tyler Allen on 11/2/21.
//

#ifndef TICTACTOEGAME_PRINTBOARD2_H
#define TICTACTOEGAME_PRINTBOARD2_H

class Board{

public:
    int row;
    int column;
    int currentBoard;

    void printInitialBoard(){
        std::cout << "_____________\n";
        std::cout << "|   |   |   |\n";
        std::cout << "_____________\n";
        std::cout << "|   |   |   |\n";
        std::cout << "_____________\n";
        std::cout << "|   |   |   |\n";
        std::cout << "_____________\n";
    }

    void updateBoard(int currentBoard[3][3]){

        for(int i=0; i<3; i++){
            std::cout << "_____________\n";
            for(int j=0; j<3; j++){
                std::cout << "|";
                if(currentBoard[i][j]==0){
                    std::cout << "   ";
                }else if(currentBoard[i][j]==1){
                    std::cout << " X ";
                }else if(currentBoard[i][j]==2){
                    std::cout << " O ";
                }
            }
            std::cout << "|";
            std::cout <<"\n";
        }
        std::cout << "_____________\n";


    }

};

#endif //TICTACTOEGAME_PRINTBOARD2_H
