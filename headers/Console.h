#ifndef PROHECT_XX_CONSOLE_H
#define PROHECT_XX_CONSOLE_H

namespace Console { 
    void resetCursor();
    void sleep(const int& ms = -1);
    void getCusrorRowPos(int &row);
    void getCusrorColPos(int &col);
    void getCursorPos(int &row, int &col);
    void getConsoleSize(int &rows, int &cols);
    void setCursorPos(short int x, short int y);
}
#endif