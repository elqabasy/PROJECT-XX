#ifndef PROJECT_XX_ANIMATION_H
#define PROJECT_XX_ANIMATION_H
#include <iostream>
#include "Constants.h"
using namespace std;

namespace Animation{
    namespace Text{
        void writing(const string& text, const int& delay = 0, const int& direction = -1, const int& row = -1, const int& col = -1, const string& endLine = "\n", const bool align = false, const short int rowAlign = -1, const short int colAlign = -1);
    }
}
#endif