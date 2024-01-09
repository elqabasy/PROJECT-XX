#ifndef PROHECT_XX_CONSOLE_H
#define PROHECT_XX_CONSOLE_H
#include<string>
#include<iostream>
using namespace std;

namespace CONSOLE { 
    void sleep(const int& ms = 1000);
    void getCusrorRowPos(short int &row);
    void getCusrorColPos(short int &col);
    void getCursorPos(short int &row, short int &col);
    void getConsoleSize(short int &rows, short int &cols);
    void setCursorPos(const short int& row = -1, const short int& col = -1);
    void print(const string& text, const short int& row = -1, const short int& col = -1, const string& endLine = "\n");

    namespace STYLE{
        void getFontColor(unsigned short int& color);
        void setFontColor(const unsigned short int& color);

        void getBackColor(unsigned short int& color); 
        void setBackColor(const unsigned short int& color); 

        void getFontSize(unsigned short int& width, unsigned short int& height);
        void setFontSize(const unsigned short int& width, const unsigned short int& height);
    }
}
#endif