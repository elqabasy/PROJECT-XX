#include <chrono>
#include <thread>
#include <iostream>
#include <windows.h>
#include "../headers/Console.h"
using namespace std;

void Console::getConsoleSize(int& rows, int& cols) {
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CSBI);
    rows = CSBI.srWindow.Bottom - CSBI.srWindow.Top + 1;
    cols = CSBI.srWindow.Right - CSBI.srWindow.Left + 1;
}

void Console::setCursor(const int& rowPos, const int& colPos) {
    cout << "\x1b[" << rowPos << ";" << colPos << "H";
}

void Console::resetCursor(){
    cout << "\x1b[" << 0 << ";" << 0 << "H";
}

void Console::sleep(const int& ms) {
    this_thread::sleep_for(chrono::milliseconds{ms});
}   