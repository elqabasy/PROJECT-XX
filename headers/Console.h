#ifndef PROHECT_XX_CONSOLE_H
#define PROHECT_XX_CONSOLE_H

namespace Console { 
    void resetCursor();
    void sleep(const int& ms);
    void setCursor(const int& x, const int& y);
    void getConsoleSize(int &rows, int &cols);
}
#endif