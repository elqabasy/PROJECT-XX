#include <chrono>
#include <thread>
#include <iostream>
#include <windows.h>
#include "../headers/Console.h"
using namespace std;
namespace CS = CONSOLE;

void CS::getConsoleSize(int& rows, int& cols) {
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CSBI);
    rows = CSBI.srWindow.Bottom - CSBI.srWindow.Top + 1;
    cols = CSBI.srWindow.Right - CSBI.srWindow.Left + 1;
}

void CS::setCursorPos(short int rowPos, short int colPos) {
    // cout << "\x1b[" << rowPos << ";" << colPos << "H";
    COORD pos = {colPos, rowPos};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void CS::resetCursor(){
    // cout << "\x1b[" << 0 << ";" << 0 << "H";
    COORD pos = {0, 0};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void CS::sleep(const int& ms) {
    // if
    this_thread::sleep_for(chrono::milliseconds{ms});
}   

void CS::getCursorPos(int &row, int &col){
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CSBI);
    row = CSBI.dwCursorPosition.Y;
    col = CSBI.dwCursorPosition.X;
}


void CS::getCusrorRowPos(int &row){
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CSBI);
    row = CSBI.dwCursorPosition.Y;
}
void CS::getCusrorColPos(int &col){
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CSBI);
    col = CSBI.dwCursorPosition.X;
}