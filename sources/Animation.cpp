#include <cmath>
#include <chrono>
#include <thread>
#include <iostream>
#include "../headers/Console.h"
#include "../headers/Constants.h"
#include "../headers/Animation.h"
using namespace std;
namespace CS = CONSOLE;


void Animation::Text::writing(const string& text, const int& delay, const short int& direction, const short int& row, const short int& col, const string& endLine, const bool& align, const short int& rowAlign, const short int& colAlign) {
    const int TEXT_SIZE = text.size();
    short int lastRow = 0, lastColumn = 0;
    short int choosenRow = 0, choosenColumn = 0;
    
    // check for any alignment before do anything
    if(align){
        short int rows, cols; CS::getConsoleSize(rows, cols); // save rows and cols to variables: rows, cols
        const int length = text.size();
        int colPos = 0, rowPos = 0;

        // align top-left
        switch (colAlign){
            case -1: // left
                colPos = 0;
                break;
            case 0: // center
                colPos = (cols / 2) - (length / 2);
                break;
            case 1: // right
                colPos = cols - length;
                break;
            default:
                break;
        }
        
        switch (rowAlign){
            case -1: // left
                rowPos = 0;
                break;
            case 0: // center
                rowPos = (rows / 2) - 1; // because we write horizontal not vertical: we will do this later.
                break;
            case 1: // right
                rowPos = rows - 1;
                break;
            default:
                break;
        }
        
        choosenRow = rowPos; choosenColumn = colPos;
        CS::setCursorPos(rowPos, colPos);
    }


    // get current position before update to new one
    CS::getCursorPos(lastRow, lastColumn);

    // start writing at specific position
    if(row == -1){
        // this is mean default value
        CS::getCusrorRowPos(choosenRow);
    }else{
        choosenRow = row;
    }
    if(col == -1){
        // this is mean default value
        CS::getCusrorColPos(choosenColumn);
    }else{
        choosenColumn = col;
    }
    
    CS::setCursorPos(choosenRow, choosenColumn);

    if(direction == -1){
        // left to right
        for (int i = 0; i < TEXT_SIZE; i++) {
            CS::setCursorPos(choosenRow, choosenColumn + i + 1);
            cout << text[i] << flush;
            CS::sleep(delay);

        }
        cout << endLine << flush;
    }else if (direction == 0){
        int leftCount = ceil(TEXT_SIZE / 2);
        int rightCount = TEXT_SIZE-leftCount;


        thread left(writing, text.substr(0, leftCount), delay, -1, choosenRow, choosenColumn, endLine, false, 0, 0);
        CS::sleep(1);
        thread right(writing, text.substr(leftCount-1, TEXT_SIZE-1), delay , 1, choosenRow, choosenColumn + leftCount - 1, endLine, false, 0, 0);
        
        left.join();
        right.join();


    }else if (direction == 1){
        // right to left
        for(int x = text.size()-1; x >= 0; x--){
            CS::setCursorPos(choosenRow, choosenColumn + x + 1);
            cout << text[x] << flush;
            CS::sleep(delay);
        }
        CS::setCursorPos(choosenRow, choosenColumn + TEXT_SIZE);
        cout << endLine << flush;
    }
}