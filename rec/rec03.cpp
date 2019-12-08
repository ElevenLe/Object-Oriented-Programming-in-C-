//
//  rec03.cpp
//  Rec03
//
//  Created by Zhengyi Li on 2018/9/21.
//  Copyright © 2018年 Zhengyi Li. All rights reserved.
//


#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Cell{
    int row;
    int col;
    bool bomb = false;
    int bombAround = 0;
    bool visible = false;
    string tital = "n";
};

class Minesweeper{
public:
    //    The constructor to initialize the game. It's main task to to fill the board with a reasonable number of bombs, and mark the other non-bomb tiles with a count of how many neighboring tiles hold bombs. See below for comments on how to do this "randomly".
    Minesweeper(){
        
        for(int i = 0; i < BOARD_ROW_NUMBER; i++){
            vector<Cell> board_col;
            for(int j = 0; j < BOARD_COL_NUMBER; j++){
                Cell oneCell;
                oneCell.row = i;
                oneCell.col = j;
                if ((rand()%100) < BOMB_PROBABILITY){
                    oneCell.bomb = true;
                };
                
                board_col.push_back(oneCell);
            }
            board.push_back(board_col);
        }
        
        for(int i = 0; i < BOARD_ROW_NUMBER; i++ ){
            for(int j = 0; j < BOARD_COL_NUMBER; j++){
                if(i-1 >= 0 && j-1 >= 0&& board[i-1][j-1].bomb == true){
                    board[i][j].bombAround += 1;
                    board[i][j].tital = "b";
                };
                
                if(i-1 >= 0  && board[i-1][j].bomb == true){
                    board[i][j].bombAround += 1;
                    board[i][j].tital = "b";
                };
                
                if (i-1 >= 0 && j+1 <= 9 &&board[i-1][j+1].bomb == true){
                    board[i][j].bombAround += 1;
                    board[i][j].tital = "b";
                };
                
                if(i+1 <= 9 && j-1 >= 0 && board[i+1][j-1].bomb == true){
                    board[i][j].bombAround += 1;
                    board[i][j].tital = "b";
                };
                
                if(i+1 <=9 &&board[i+1][j].bomb == true){
                    board[i][j].bombAround += 1;
                    board[i][j].tital = "b";
                };
                
                if( i+1 <= 9 && j+1 <= 9 && board[i+1][j+1].bomb == true){
                    board[i][j].bombAround += 1;
                    board[i][j].tital = "b";
                };
                
                if(j-1 >= 0 &&board[i][j-1].bomb == true){
                    board[i][j].bombAround += 1;
                    board[i][j].tital = "b";
                }
                
                if(j+1 <= 9 &&board[i][j+1].bomb == true){
                    board[i][j].bombAround += 1;
                    board[i][j].tital = "b";
                };
            };
        };
        //
    }
    
//    To display the board. Take a boolean argument specifying whether to display the bombs or not. We won't want to for normal turns, but will want to at the end.
    void display(bool check){
        if(check == true){
            for(int i = 0; i < BOARD_ROW_NUMBER; i++){
                cout<< endl;
                for(int j = 0; j < BOARD_COL_NUMBER; j++){
                    if(board[i][j].bomb == true){
                        cout << "b";
                    }else{
                        cout << board[i][j].bombAround;
                    };
                    
                };
            }
            cout << endl;
        }
        else{
            for(int i = 0; i < BOARD_ROW_NUMBER; i++){
                cout<< endl;
                for(int j = 0; j < BOARD_COL_NUMBER; j++){
                    if(board[i][j].visible == true){
                        cout << board[i][j].bombAround;
                    }else{
                        cout << "*";
                    };
                };
            }cout << endl;
            
        }
        
    };
    //    done. Returns true if the game is over, false otherwise.
    bool done(){
        bool check = true;
        for(int i = 0; i < BOARD_ROW_NUMBER; i++){
            for(int j = 0; j < BOARD_COL_NUMBER; j++){
                if(board[i][j].bomb == false && board[i][j].visible == false){
                    check = false;
                }
                
            };
        }
        return check;
    };
    //    Takes a row number. Returns true if the row number is valid, and false otherwise.
    bool validRow(int rowNumber){
        if(rowNumber < BOARD_ROW_NUMBER){
            return true;
        }else{
            return false;
        }
    };
    //    Takes a column number. Returns true if the column number is valid, and false otherwise.
    bool validCol(int colNumber){
        if(colNumber < BOARD_COL_NUMBER){
            return true;
        }else{
            return false;
        }
    };
    //    Takes a row number and a column number. Returns true if the corresponding cell is visible and false otherwise.
    bool isVisible(int row, int col){
        if(board[row][col].visible == true){
            return true;
        }else{
            return false;
        };
    }
    //    play. Takes a row number and a column number, changing the state of the board as appropriate for this move. Returns false if the move results in an explosion.
    bool play(int row, int col){
        board[row][col].visible = true;
        if(board[row][col].bomb == true){
            return false;
            
        }else{
            
            if(board[row][col].bombAround != 0){
                return true;
            }else{
                vector<Cell> checkList;
                checkList.push_back(board[row][col]);
                
                while(checkList.size() != 0){
                    
                    
                    Cell check = checkList.back();
                    //cout << "check row :" << check.row << "check col :" << check.col << endl;
                    //cout << check.bombAround;
                    checkList.pop_back();
                    if(check.bombAround == 0){
                        
                        if(check.row + 1 <= 9
                           && board[check.row+1][check.col].visible == false
                           && board[check.row+1][check.col].bomb == false ){
                            if (board[check.row+1][check.col].bombAround == 0){
                                
                                checkList.push_back(board[check.row+1][check.col]);
                            }
                            board[check.row+1][check.col].visible = true;};
                        
                        if(check.row + 1 <= 9 && check.col + 1 <= 9
                           && board[check.row+1][check.col+1].visible == false
                           && board[check.row+1][check.col+1].bomb == false){
                            if (board[check.row+1][check.col+1].bombAround == 0){
                                
                                checkList.push_back(board[check.row+1][check.col+1]);
                            }
                            board[check.row+1][check.col+1].visible = true;
                        };
                        
                        if(check.row + 1 <= 9 && check.col - 1 >= 0 &&
                           board[check.row+1][check.col-1].visible == false &&
                           board[check.row+1][check.col-1].bomb == false){
                            if(board[check.row+1][check.col-1].bombAround == 0){
                                
                                checkList.push_back(board[check.row+1][check.col-1]);
                            }
                            board[check.row+1][check.col-1].visible = true;
                        };
                        
                        if (check.row - 1 >= 0 &&
                            board[check.row-1][check.col].visible == false &&
                            board[check.row-1][check.col].bomb != true)
                        {
                            if(board[check.row-1][check.col].bombAround == 0){
                                
                                checkList.push_back(board[check.row-1][check.col]);
                            }
                            board[check.row-1][check.col].visible = true;
                        };
                        
                        if(check.row - 1 >= 0 && check.col - 1 >= 0 &&
                           board[check.row-1][check.col-1].visible == false &&
                           board[check.row-1][check.col-1].bomb == false){
                            if(board[check.row-1][check.col-1].bombAround == 0){
                                
                                checkList.push_back(board[check.row-1][check.col-1]);
                            }
                            board[check.row-1][check.col-1].visible = true;
                        };
                        
                        if(check.row - 1 >= 0 && check.col + 1 <= 9 &&
                           board[check.row-1][check.col+1].visible == false &&
                           board[check.row-1][check.col+1].bomb == false){
                            if(board[check.row-1][check.col+1].bombAround == 0){
                                
                                checkList.push_back(board[check.row-1][check.col+1]);
                            }
                            board[check.row-1][check.col+1].visible = true;
                        }
                        
                        
                        if (check.col + 1 <= 9 &&
                            board[check.row][check.col+1].visible == false&&
                            board[check.row][check.col+1].bomb == false){
                            if(board[check.row][check.col+1].bombAround == 0){
                                
                                checkList.push_back(board[check.row][check.col+1]);
                            }
                            board[check.row][check.col+1].visible = true;
                        }
                        
                        if (check.col - 1 >= 0 &&
                            board[check.row][check.col-1].visible == false &&
                            board[check.row][check.col-1].bomb == false){
                            if(board[check.row][check.col-1].bombAround == 0){
                                
                                checkList.push_back(board[check.row][check.col-1]);
                            }
                            board[check.row][check.col-1].visible = true;
                        };
                        
                        
                    }else{
                        check.visible = true;
                        
                        
                    };
                    
                    
                    
            };
                return true;
            };
        };
    };
    
private:
    const int BOARD_ROW_NUMBER = 10;
    const int BOARD_COL_NUMBER  = 10;
    vector<vector<Cell>> board;
    const int BOMB_PROBABILITY = 10;
};


int main() {
    Minesweeper sweeper;
    // Continue until only invisible cells are bombs
    while (!sweeper.done()) {
        sweeper.display(false); // display board without bombs
        
        int row_sel = -1, col_sel = -1;
        while (row_sel == -1) {
            // Get a valid move
            int r, c;
            cout << "row? ";
            cin >> r;
            if (!sweeper.validRow(r)) {
                cout << "Row out of bounds\n";
                continue;
            }
            cout << "col? ";
            cin >> c;
            if (!sweeper.validCol(c)) {
                cout << "Column out of bounds\n";
                continue;
            }
            if (sweeper.isVisible(r,c)) {
                cout << "Square already visible\n";
                continue;
            }
            row_sel = r;
            col_sel = c;
        }
        // Set selected square to be visible. May effect other cells.
        if (!sweeper.play(row_sel,col_sel)) {
            cout << "Sorry, you died..\n";
            sweeper.display(true); // Final board with bombs shown
            exit(0);
        }
    }
    // Ah! All invisible cells are bombs, so you won!
    cout << "You won!!!!\n";
    sweeper.display(true); // Final board with bombs shown
}
