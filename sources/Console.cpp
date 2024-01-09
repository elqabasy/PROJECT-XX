#include <chrono>
#include <thread>
#include <iostream>
#include <windows.h>
#include "../headers/Console.h"
using namespace std;


void CONSOLE::getConsoleSize(short int& rows, short int& cols) {
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CSBI);
    rows = CSBI.srWindow.Bottom - CSBI.srWindow.Top + 1;
    cols = CSBI.srWindow.Right - CSBI.srWindow.Left + 1;
}

void CONSOLE::setCursorPos(const short int& row, const short int& col) {
    short int cRow = row, cCol = col;
    if(row == -1){
        CONSOLE::getCusrorRowPos(cRow);
    }
    if(col == -1){
        CONSOLE::getCusrorColPos(cCol);
    }

    COORD coord;
    coord.X = cCol;
    coord.Y = cRow;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void CONSOLE::sleep(const int& ms) {
    this_thread::sleep_for(chrono::milliseconds{ms});
}   

void CONSOLE::getCursorPos(short int &row, short int &col){
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CSBI);
    row = CSBI.dwCursorPosition.Y;
    col = CSBI.dwCursorPosition.X;
}


void CONSOLE::getCusrorRowPos(short int &row){
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CSBI);
    row = CSBI.dwCursorPosition.Y;
}
void CONSOLE::getCusrorColPos(short int &col){
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CSBI);
    col = CSBI.dwCursorPosition.X;
}

void CONSOLE::print(const string& text, const short int& row, const short int& col, const string& endLine){
    short int cRow = row, cCol = col;
    if(row == -1){
        CONSOLE::getCusrorRowPos(cRow);
    }
    if (col == -1){
        CONSOLE::getCusrorColPos(cCol);
    }

    CONSOLE::setCursorPos(cRow, cCol);
    cout << text << endLine;
}


// not work for end
void CONSOLE::STYLE::getFontColor(unsigned short int& color){
    CONSOLE_SCREEN_BUFFER_INFO info;
    color = info.wAttributes;
}

void CONSOLE::STYLE::setFontColor(const unsigned short int& color){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void CONSOLE::STYLE::getBackColor(unsigned short int& color){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hConsole, &bufferInfo);

    WORD currentAttributes = bufferInfo.wAttributes;
    WORD backgroundColorMask = 0x00F0;

    color = (currentAttributes & backgroundColorMask) >> 4;
}

void CONSOLE::STYLE::setBackColor(const unsigned short int& color){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hConsole, &bufferInfo);

    WORD mask = 0xFFF0;

    WORD newAttributes = (bufferInfo.wAttributes & mask) | color;
    SetConsoleTextAttribute(hConsole, newAttributes);
}


void CONSOLE::STYLE::getFontSize(unsigned short int& width, unsigned short int& height){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFO fontInfo;
    GetCurrentConsoleFont(hConsole, FALSE, &fontInfo);

    COORD fontSize = fontInfo.dwFontSize;
    width = fontSize.X; height = fontSize.Y;
}
void CONSOLE::STYLE::setFontSize(const unsigned short int& width, const unsigned short int& height){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    fontInfo.nFont = 0;
    fontInfo.dwFontSize.X = width;
    fontInfo.dwFontSize.Y = height;

    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}